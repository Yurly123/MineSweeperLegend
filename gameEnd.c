#include "gameEnd.h"

enum GameEndOption gameOverLoop(time_t gameTime, enum Difficulty difficulty) {
  int cols;
  switch (difficulty) {
    case EASY: cols = 9; break;
    case MEDIUM: cols = 16; break;
    case HARD: cols = 30; break;
  }
  int baseX = cols * 2 + 4;
  printGameEndFrame(baseX);
  printxy(baseX + 4, 4, "게임 오버!");
  printxy(baseX + 4, 5, "소요 시간: %ld초", gameTime);

  struct TextBox options[] = {
    {baseX + 4, 7, "다시 시작"},
    {baseX + 15, 7, "종료"}
  };
  for (int i = 0; i < 2; i++)
    printTextBox(options[i]);
  int selectedOption = 0;
  waitForInput();
  
  while (1) {
    for (int i = 0; i < 2; i++) {
      if (i == selectedOption) setTextColor(GREEN);
      else setTextColor(RESET);
      printTextBox(options[i]);
    }

    char input = getInput();
    int isSelected = handleGameEndInput(input, &selectedOption, 2);

    if (isSelected) {
      switch (selectedOption) {
        case 0: return RESTART;
        case 1: return EXIT;
      }
    }
  }
}

enum GameEndOption winLoop(time_t gameTime, enum Difficulty difficulty) {
  int cols;
  switch (difficulty) {
    case EASY: cols = 9; break;
    case MEDIUM: cols = 16; break;
    case HARD: cols = 30; break;
  }
  int baseX = cols * 2 + 4;
  printGameEndFrame(baseX);

  printxy(baseX + 4, 4, "게임 클리어!");
  printxy(baseX + 4, 5, "소요 시간: %ld초", gameTime);
  struct TextBox options[] = {
    {baseX + 4, 7, "랭킹"},
    {baseX + 10, 7, "다시 시작"},
    {baseX + 21, 7, "종료"}
  };
  for (int i = 0; i < 3; i++)
    printTextBox(options[i]);
  int selectedOption = 0;
  waitForInput();

  while (1) {
    for (int i = 0; i < 3; i++) {
      if (i == selectedOption) setTextColor(GREEN);
      else setTextColor(RESET);
      printTextBox(options[i]);
    }

    char input = getInput();
    int isSelected = handleGameEndInput(input, &selectedOption, 3);
    if (isSelected) {
      switch (selectedOption) {
        case 0: return RANKING;
        case 1: return RESTART;
        case 2: return EXIT;
      }
    }
  }
}

void printGameEndFrame(int baseX) {
  printxy(baseX, 2, "┌");
  printxy(baseX, 9, "└");
  printxy(baseX + 30, 2, "┐");
  printxy(baseX + 30, 9, "┘");
  for (int i = 3; i < 9; i++) {
    printxy(baseX, i, "│");
    printxy(baseX + 30, i, "│");
  }
  for (int i = 1; i < 30; i++) {
    printxy(baseX + i, 2, "─");
    printxy(baseX + i, 9, "─");
  }
}

int handleGameEndInput(char input, int* selectedOption, int optionCount) {
  switch (input) {
    case 'a':
      *selectedOption = (*selectedOption - 1 + optionCount) % optionCount;
      break;
    case 'd':
      *selectedOption = (*selectedOption + 1) % optionCount;
      break;
    case 'j':
      return 1;
  }
  return 0;
}