#include "util.h"

void clearScreen() {
  system("cls || clear");
  setTextAndBackgroundColor(RESET, RESET);
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

enum Color textColor = RESET;
enum Color backgroundColor = RESET;

void setTextColor(enum Color color) {
  setTextAndBackgroundColor(color, backgroundColor);
}

void setBackgroundColor(enum Color color) {
  setTextAndBackgroundColor(textColor, color);
}

void setTextAndBackgroundColor(enum Color text, enum Color background) {
  textColor = text;
  backgroundColor = background;

  if (text == RESET && background == RESET) 
    printf("\e[0m");
  else if (text == RESET) 
    printf("\e[%dm", background + 40);
  else if (background == RESET) 
    printf("\e[%dm", text + 30);
  else 
    printf("\e[%d;%dm", text + 30, background + 40);
}