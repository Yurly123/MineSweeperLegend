#pragma once

#include "util.h"
#include "database.h"

void rankingLoop();
void printRankingScreen(struct RankingEntry* entries, int count);
void registerRankingEntry(time_t gameTime, enum Difficulty difficulty);