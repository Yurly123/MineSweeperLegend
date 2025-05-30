#pragma once

#include "util.h"
#include "types.h"
#include "gameLoop.h"
#include "initializeBoard.h"
#include "gameEnd.h"

void gameFlow();
enum Difficulty selectDifficulty();
void freeBoard(struct Cell** board, enum Difficulty difficulty);