#include "util.h"

void initializeProgram() {
  setColor(DEFAULT);
  srand((unsigned int)time(NULL));
  SetConsoleTitle("Mine Sweeper Legend");
  clearScreen();
  hideCursor();
}

int main() {
  initializeProgram();
  printxy(10, 10, "Hello, World!");
  waitForInput();
}