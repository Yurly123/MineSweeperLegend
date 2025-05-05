#pragma once

#include "util.h"

#define TITLE_OPTIONS_COUNT 2

void titleLoop();
void printTitleScreen(Option* options);
void handleTitleInput(Option* options, int* selectedOption);