#pragma once

#include "util.h"
#include "types.h"
#include "initializeBoard.h"

void gameLoop(Cell** board, Difficulty difficulty);
void printGameScreen(Cell** board, Difficulty difficulty);
void updateGameScreen(Cell** board, Difficulty difficulty);
void handleInput(Cell** board, Difficulty difficulty);
