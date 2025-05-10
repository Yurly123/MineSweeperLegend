#pragma once

#include "util.h"
#include "types.h"

enum GameState gameLoop(struct Cell** board, enum Difficulty difficulty);
void printGameScreen(struct Cell** board, enum Difficulty difficulty);
void updateGameScreen(struct Cell** board, enum Difficulty difficulty);
void handleGameInput(struct Cell** board, enum Difficulty difficulty, struct Coord* cursor);
void floodFill(struct Cell** board, enum Difficulty difficulty, struct Coord target);
enum GameState checkGameEnd(struct Cell** board, enum Difficulty difficulty);
