#include "database.h"

// Helper function to find a JSON field
const char *findJsonField(const char *json, const char *field) {
  char fieldSearch[256];
  sprintf(fieldSearch, "\"%s\":", field);
  return strstr(json, fieldSearch);
}

// Helper function to extract string value from JSON
char *extractStringValue(const char *json) {
  const char *start = strstr(json, "\"stringValue\":");
  if (!start)
    return NULL;

  start = strchr(start + 14, '"');
  if (!start)
    return NULL;
  start++; // Skip the first quote

  const char *end = strchr(start, '"');
  if (!end)
    return NULL;

  size_t length = end - start;
  char *result = malloc(length + 1);
  if (!result)
    return NULL;

  strncpy(result, start, length);
  result[length] = '\0';
  return result;
}

// Helper function to extract integer value from JSON
int extractIntValue(const char *json) {
  const char *start = strstr(json, "\"integerValue\":");
  if (!start)
    return 0;

  start = strchr(start + 15, '"');
  if (!start)
    return 0;
  start++; // Skip the first quote

  return atoi(start);
}

RankingEntry *parseRankingJson(const char *json, int *count) {
  *count = 0;

  const char *documents = strstr(json, "\"documents\":");
  if (!documents)
    return NULL;

  int docCount = 0;
  const char *docPos = documents;
  while ((docPos = strstr(docPos + 1, "\"fields\":")) != NULL) {
    docCount++;
  }
  if (docCount == 0)
    return NULL;

  RankingEntry *entries = malloc(sizeof(RankingEntry) * docCount);
  if (!entries) return NULL;

  int index = 0;
  const char *current = documents;
  while ((current = strstr(current + 1, "\"fields\":")) != NULL && index < docCount) {
    const char *nameField = findJsonField(current, "name");
    entries[index].name = extractStringValue(nameField);

    const char *timeField = findJsonField(current, "time");
    entries[index].time = extractIntValue(timeField);

    const char *difficultyField = findJsonField(current, "difficulty");
    entries[index].difficulty = extractIntValue(difficultyField);

    const char *commentField = findJsonField(current, "comment");
    entries[index].comment = extractStringValue(commentField);

    current++;
    index++;
  }

  *count = index;
  return entries;
}

void freeRankingEntries(RankingEntry *entries, int count) {
  if (!entries) return;
  for (int i = 0; i < count; i++) {
    free(entries[i].name);
    free(entries[i].comment); 
  }
  free(entries);
}

RankingEntry *getRankingEntries(int *count) {
  char *data = executeHttpRequest(getRankingHttpUrl(), GET, NULL);
  if (!data) {
    *count = 0;
    return NULL;
  }

  RankingEntry *entries = parseRankingJson(data, count);
  free(data); 
  return entries;
}

void postRankingEntry(RankingEntry entry) {
  char body[256];
  snprintf(body, sizeof(body),
           "{\\\"fields\\\": {"
           "\\\"name\\\": {\\\"stringValue\\\": \\\"%s\\\"}, "
           "\\\"time\\\": {\\\"integerValue\\\": \\\"%d\\\"}, "
           "\\\"difficulty\\\": {\\\"integerValue\\\": \\\"%d\\\"}, "
           "\\\"comment\\\": {\\\"stringValue\\\": \\\"%s\\\"}"
           "}}",
           entry.name, entry.time, entry.difficulty, entry.comment);

  char* result = executeHttpRequest(getRankingHttpUrl(), POST, body);
  if (result) free(result);
}

char *executeHttpRequest(const char *url, HttpMethod method, const char *body) {
  char command[1024];

  switch (method) {
  case GET:
    snprintf(command, sizeof(command), "curl -s -S \"%s\"", url);
    break;
  case POST:
    snprintf(command, sizeof(command), "curl -X POST -H \"Content-Type: application/json\" -d \"%s\" -s -S \"%s\"", body, url);
    break;
  default:
    return NULL; // Unsupported method
  }

  FILE *pipe = popen(command, "r");
  if (!pipe)
    return NULL;

  char *buffer = malloc(4096); // Adjust size as needed
  size_t bufferSize = 4096;
  size_t index = 0;
  int c;

  while ((c = fgetc(pipe)) != EOF) {
    if (index >= bufferSize - 1) {
      bufferSize *= 2;
      buffer = realloc(buffer, bufferSize);
    }
    buffer[index++] = (char)c;
  }

  if (buffer)
    buffer[index] = '\0';
  pclose(pipe);
  return buffer;
}