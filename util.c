#include "util.h"

void clearScreen() {
  system("cls || clear");
}

char getInput() {
  char input = _getch();
  if (input >= 'A' && input <= 'Z') {
    input += 'a' - 'A'; 
  }
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

void printTextBox(struct TextBox option) {
  printxy(option.x, option.y, option.text);
}

void setColor(enum Color color) {
  printf("\e[%dm", color);
}