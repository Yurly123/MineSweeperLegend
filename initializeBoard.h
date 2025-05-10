#pragma once

#include "util.h"
#include "types.h"

void initializeBoard(struct Cell** board, enum Difficulty difficulty);

void initializeArray(struct Cell** board, enum Difficulty difficulty);
void placeMines(struct Cell** board, enum Difficulty difficulty);
void calculateAdjacentMines(struct Cell** board, enum Difficulty difficulty);