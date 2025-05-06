#include "ranking.h"

void rankingLoop() {
  printRankingScreen();
  RankingEntry entry = { "tempName", 100 };
  postRankingEntry(entry);
  waitForInput();
}

void printRankingScreen() {
  clearScreen();
  int count = 0;
  RankingEntry* rankingEntries = getRankingEntries(&count);
  for (int i = 0; i < count; i++) {
    printf("%d. %s - %d\n", i + 1, rankingEntries[i].name, rankingEntries[i].time);
  }
}
