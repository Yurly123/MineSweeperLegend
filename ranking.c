#include "ranking.h"

void rankingLoop() {
  int count = 0;
  struct RankingEntry* rankingEntries = getRankingEntries(&count);

  printRankingScreen(rankingEntries, count);

  freeRankingEntries(rankingEntries, count);
}

void printRankingScreen(struct RankingEntry* entries, int count) {
  clearScreen();
  char difficultyString[3][10] = {"쉬움", "보통", "어려움"};
  for (int i = 0; i < count; i++) {
    printf("%d. %s (%s, %d초): %s\n", i + 1, entries[i].name, difficultyString[entries[i].difficulty], entries[i].time, entries[i].comment);
  }
  waitForInput();
}

void registerRankingEntry(time_t gameTime, enum Difficulty difficulty) {
  char name[1024];
  char comment[1024];

  clearScreen();
  printf("랭킹에 등록될 이름을 입력하세요: ");
  fgets(name, sizeof(name), stdin);
  name[strcspn(name, "\n")] = '\0'; // 개행 문자 제거

  printf("댓글을 입력하세요 (선택사항): ");
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