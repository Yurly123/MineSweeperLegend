#pragma once

#include "util.h"
#include "ranking.h"
#include "gameFlow.h"
#include "help.h"`

#define TITLE_OPTIONS_COUNT 4

void titleLoop();
void printTitleScreen(struct TextBox* options);
void handleTitleInput(struct TextBox* options, int* selectedOption);