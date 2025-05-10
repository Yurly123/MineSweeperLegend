#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#include "types.h"

void clearScreen();
char getInput();
void waitForInput();
void hideCursor();
void gotoxy(int x, int y);
void printxy(int x, int y, const char* format, ...);
void printTextBox(struct TextBox option);

enum Color {
  BLACK = 30,
  RED = 31,
  GREEN = 32,
  YELLOW = 33,
  BLUE = 34,
  MAGENTA = 35,
  CYAN = 36,
  WHITE = 37,
  BRIGHT_BLACK = 90,
  BRIGHT_RED = 91,
  BRIGHT_GREEN = 92,
  BRIGHT_YELLOW = 93,
  BRIGHT_BLUE = 94,
  BRIGHT_MAGENTA = 95,
  BRIGHT_CYAN = 96,
  BRIGHT_WHITE = 97,
  RESET = 0,
};
void setColor(enum Color color);

