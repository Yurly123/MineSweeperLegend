#pragma once

#include "util.h"

struct Cell {
  int isMine;
  int adjacentMines;
  int isFlagged;
  int isRevealed;
};

enum Difficulty {
  EASY = 0, // 9x9, 지뢰 10개
  MEDIUM = 1, // 16x16, 지뢰 40개
  HARD = 2, // 16x30, 지뢰 99개
};

enum GameState {
  PLAYING, 
  GAME_OVER, 
  WIN,
};

struct TextBox {
  int x;
  int y;
  char* text;
};

struct RankingEntry {
  char* name;
  int time;
  enum Difficulty difficulty;
  char* comment;
};

struct Coord {
  int x;
  int y;
};