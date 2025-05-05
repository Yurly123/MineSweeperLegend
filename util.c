#include "util.h"

void clearScreen() {
  system("cls || clear");
}

char getInput(const char* availableInputs, ...) {
  va_list args;
  va_start(args, availableInputs);

  char input;
  do input = _getch();
    while (strchr(availableInputs, input) == NULL);
  
  va_end(args);
  return input;
}

void waitForInput() {
  _getch();
}

void hideCursor() {
  printf("\e[?25l");
}

void gotoxy(int x, int y) {
  printf("\033[%d;%dH", y, x);
  hideCursor();
}

void printxy(int x, int y, const char* format, ...) {
  va_list args;
  va_start(args, format);  
  gotoxy(x, y);
  vprintf(format, args);
  va_end(args);
}

void setColor(Color color) {
  printf("\e[%dm", color + 30);
}