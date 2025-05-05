#pragma once

#include "util.h"

typedef struct {
  int isMine;
  int adjacentMines;
  int isFlagged;
  int isRevealed;
} Cell;

typedef enum {
  EASY, // 9x9, 지뢰 10개
  MEDIUM, // 16x16, 지뢰 40개
  HARD, // 16x30, 지뢰 99개
} Difficulty;

typedef enum {
  PLAYING, 
  GAME_OVER, 
  WIN,
} GameState;

typedef struct {
  int x;
  int y;
  char* text;
} Option;

typedef struct {
  char* name;
  int time;
} RankingEntry;