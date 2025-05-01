#pragma once

#include "util.h"
#include "types.h"

void initializeBoard(Cell** board, Difficulty difficulty);

void initializeArray(Cell** board, Difficulty difficulty);
void placeMines(Cell** board, Difficulty difficulty);
void calculateAdjacentMines(Cell** board, Difficulty difficulty);