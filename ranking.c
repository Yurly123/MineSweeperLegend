#include "ranking.h"

void rankingLoop() {
  int count = 0;
  RankingEntry* rankingEntries = getRankingEntries(&count);

  printRankingScreen(rankingEntries, count);

  freeRankingEntries(rankingEntries, count);
}

void printRankingScreen(RankingEntry* entries, int count) {
  clearScreen();
  for (int i = 0; i < count; i++) {
    printf("%d. %s - %d\n", i + 1, entries[i].name, entries[i].time);
  }
  waitForInput();
}
