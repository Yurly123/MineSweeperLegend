#pragma once

#include "util.h"
#include "types.h"

enum GameEndOption gameOverLoop(time_t gameTime, enum Difficulty difficulty);
enum GameEndOption winLoop(time_t gameTime, enum Difficulty difficulty);
void printGameEndFrame(int baseX);
int handleGameEndInput(char input, int* selectedOption, int optionCount);