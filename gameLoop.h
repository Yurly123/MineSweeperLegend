#pragma once

#include "util.h"
#include "types.h"

enum GameState gameLoop(struct Cell** board, enum Difficulty difficulty, time_t* gameTime);
void printGameScreen(struct Cell** board, enum Difficulty difficulty);
void updateGameScreen(struct Cell** board, enum Difficulty difficulty, struct Coord cursor, struct Coord prevCursor);
void handleGameInput(struct Cell** board, enum Difficulty difficulty, struct Coord* cursor);
void floodFill(struct Cell** board, enum Difficulty difficulty, struct Coord target);
enum GameState checkGameEnd(struct Cell** board, enum Difficulty difficulty);
