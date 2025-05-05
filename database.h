#pragma once

#include "util.h"
#include "env.h"
#include "types.h"

RankingEntry* getRankingEntries(int* count);
char* executeHttpRequest(const char* url);