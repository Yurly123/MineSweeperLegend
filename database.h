#pragma once

#include "util.h"
#include "env.h"
#include "types.h"

struct RankingEntry* getRankingEntries(int* count);
void freeRankingEntries(struct RankingEntry *entries, int count);
void postRankingEntry(struct RankingEntry entry);

typedef enum {
    GET, POST
} HttpMethod;
char* executeHttpRequest(const char* url, HttpMethod method, const char* body);