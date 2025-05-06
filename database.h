#pragma once

#include "util.h"
#include "env.h"
#include "types.h"

RankingEntry* getRankingEntries(int* count);
void freeRankingEntries(RankingEntry *entries, int count);
void postRankingEntry(RankingEntry entry);

typedef enum {
    GET, POST
} HttpMethod;
char* executeHttpRequest(const char* url, HttpMethod method, const char* body);