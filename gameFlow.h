#pragma once

#include "util.h"
#include "types.h"
#include "gameLoop.h"
#include "initializeBoard.h"

void gameFlow();
Difficulty selectDifficulty();
void freeBoard(Cell** board, Difficulty difficulty);