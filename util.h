#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>

void clearScreen();
char getInput(const char* availableInputs, ...);
void waitForInput();
void hideCursor();
void gotoxy(int x, int y);
void printxy(int x, int y, const char* format, ...);

typedef enum {
  BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, DEFAULT,
} Color;
void setColor(Color color);

