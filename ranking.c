#include "ranking.h"

void rankingLoop() {
  int count = 0;
  RankingEntry* rankingEntries = getRankingEntries(&count);

  printRankingScreen(rankingEntries, count);

  freeRankingEntries(rankingEntries, count);
}

void printRankingScreen(RankingEntry* entries, int count) {
  clearScreen();
  char difficultyString[3][10] = {"쉬움", "보통", "어려움"};
  for (int i = 0; i < count; i++) {
    printf("%d. %s (%s, %d초): %s\n", i + 1, entries[i].name, difficultyString[entries[i].difficulty], entries[i].time, entries[i].comment);
  }
  waitForInput();
}
