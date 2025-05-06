#pragma once

#include "util.h"
#include "ranking.h"
#include "gameFlow.h"

#define TITLE_OPTIONS_COUNT 4

void titleLoop();
void printTitleScreen(TextBox* options);
void handleTitleInput(TextBox* options, int* selectedOption);