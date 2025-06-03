#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>

#include "types.h"

void clearScreen();
char getInput();
void waitForInput();
void hideCursor();
void gotoxy(int x, int y);
void printxy(int x, int y, const char* format, ...);
void printTextBox(struct TextBox option);

enum Color {
  BLACK = 0,
  RED = 1,
  GREEN = 2,
  YELLOW = 3,
  BLUE = 4,
  MAGENTA = 5,
  CYAN = 6,
  WHITE = 7,
  BRIGHT_BLACK = 60,
  BRIGHT_RED = 61,
  BRIGHT_GREEN = 62,
  BRIGHT_YELLOW = 63,
  BRIGHT_BLUE = 64,
  BRIGHT_MAGENTA = 65,
  BRIGHT_CYAN = 66,
  BRIGHT_WHITE = 67,
  RESET = -1,
};
void setTextColor(enum Color color);
void setBackgroundColor(enum Color color);
void setTextAndBackgroundColor(enum Color text, enum Color background);