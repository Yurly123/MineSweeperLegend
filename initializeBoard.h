#pragma once

#include "util.h"
#include "types.h"

struct Cell** initializeBoard(enum Difficulty difficulty);

struct Cell** initializeArray(enum Difficulty difficulty);
void placeMines(struct Cell** board, enum Difficulty difficulty);
void calculateAdjacentMines(struct Cell** board, enum Difficulty difficulty);