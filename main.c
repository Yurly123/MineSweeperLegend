#include "util.h"
#include "title.h"

void initializeProgram() {
  setColor(RESET);
  srand((unsigned int)time(NULL));
  SetConsoleTitle("Mine Sweeper Legend");
  clearScreen();
  hideCursor();
}

int main() {
  initializeProgram();
  titleLoop();
}