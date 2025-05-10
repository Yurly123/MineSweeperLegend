#pragma once

#include "util.h"
#include "types.h"

enum GameState gameLoop(struct Cell** board, enum Difficulty difficulty);
void printGameScreen(struct Cell** board, enum Difficulty difficulty);
void updateGameScreen(struct Cell** board, enum Difficulty difficulty);
void handleGameInput(struct Cell** board, enum Difficulty difficulty);
void floodFill(struct Cell** board, int x, int y, enum Difficulty difficulty);
enum GameState checkGameEnd(struct Cell** board, enum Difficulty difficulty);
