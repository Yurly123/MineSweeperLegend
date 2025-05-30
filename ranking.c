#include "ranking.h"

void rankingLoop() {
  int count = 0;
  struct RankingEntry* rankingEntries = getRankingEntries(&count);

  printRankingScreen(rankingEntries, count);

  waitForInput();
  clearScreen();
  freeRankingEntries(rankingEntries, count);
}

void printRankingScreen(struct RankingEntry* entries, int count) {
  clearScreen();
  sortRankingEntries(entries, count);

  printf("\n=== 쉬움 랭킹 ===\n\n");
  for (int i = 0, easyCount = 0; i < count; i++) {
    if (entries[i].difficulty == EASY) {
      printf("%d. %s - %d초 : %s\n", ++easyCount, entries[i].name, entries[i].time, entries[i].comment);
    }
  }

  printf("\n=== 보통 랭킹 ===\n\n");
  for (int i = 0, mediumCount = 0; i < count; i++) {
    if (entries[i].difficulty == MEDIUM) {
      printf("%d. %s - %d초 : %s\n", ++mediumCount, entries[i].name, entries[i].time, entries[i].comment);
    }
  }

  printf("\n=== 어려움 랭킹 ===\n\n");
  for (int i = 0, hardCount = 0; i < count; i++) {
    if (entries[i].difficulty == HARD) {
      printf("%d. %s - %d초 : %s\n", ++hardCount, entries[i].name, entries[i].time, entries[i].comment);
    }
  }
}

void sortRankingEntries(struct RankingEntry* entries, int count) {
  for (int i = 0; i < count - 1; i++) {
    for (int j = i + 1; j < count; j++) {
      if (entries[i].time > entries[j].time) {
        struct RankingEntry temp = entries[i];
        entries[i] = entries[j];
        entries[j] = temp;
      }
    }
  }
}

void registerRankingEntry(time_t gameTime, enum Difficulty difficulty) {
  char name[1024];
  char comment[1024];

  clearScreen();
  printf("랭킹에 등록될 이름을 입력하세요: ");
  fgets(name, sizeof(name), stdin);
  name[strcspn(name, "\n")] = '\0'; // 개행 문자 제거

  printf("댓글을 입력하세요: ");
  fgets(comment, sizeof(comment), stdin);
  comment[strcspn(comment, "\n")] = '\0'; // 개행 문자 제거

  struct RankingEntry entry;
  entry.name = strdup(name);
  entry.comment = strdup(comment);
  entry.time = (int)gameTime;
  entry.difficulty = difficulty;

  postRankingEntry(entry);

  free(entry.name);
  free(entry.comment);
}