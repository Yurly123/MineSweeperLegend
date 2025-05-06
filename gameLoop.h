#pragma once

#include "util.h"
#include "types.h"
#include "initializeBoard.h"

GameState gameLoop(Cell** board, Difficulty difficulty);
void printGameScreen(Cell** board, Difficulty difficulty);
void updateGameScreen(Cell** board, Difficulty difficulty);
void handleGameInput(Cell** board, Difficulty difficulty);
void floodFill(Cell** board, int x, int y, Difficulty difficulty);
GameState checkGameEnd(Cell** board, Difficulty difficulty);
