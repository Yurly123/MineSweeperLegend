#include "util.h"
#include "title.h"

void initializeProgram() {
  setTextColor(RESET);
  srand((unsigned int)time(NULL));
  SetConsoleTitle("Mine Sweeper Legend");
  setlocale(LC_ALL, ".UTF-8");
  clearScreen();
  hideCursor();
}

int main() {
  initializeProgram();
  titleLoop();
}