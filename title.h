#pragma once

#include "util.h"
#include "ranking.h"

#define TITLE_OPTIONS_COUNT 4

void titleLoop();
void printTitleScreen(Option* options);
void handleTitleInput(Option* options, int* selectedOption);