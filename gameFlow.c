#include "gameFlow.h"

void gameFlow() {
  enum Difficulty difficulty = selectDifficulty();
  while(1) {
    struct Cell **board = initializeBoard(difficulty);

    time_t gameTime;
    enum GameState gameResult = gameLoop(board, difficulty, &gameTime);
    setBackgroundColor(RESET); //! 배경색 초기화
    setTextColor(RESET);       //! 텍스트색 초기화

    enum GameEndOption endOption;
    switch (gameResult) {
      case GAME_OVER:
        endOption = gameOverLoop(gameTime, difficulty);
        break;
      case WIN:
        endOption = winLoop(gameTime, difficulty);
        break;
    }

    clearScreen();
    freeBoard(board, difficulty);

    switch (endOption) {
      case RESTART: break;
      case EXIT: return;
      case RANKING:
        registerRankingEntry(gameTime, difficulty);
        return;
    }
  }
}

enum Difficulty selectDifficulty() {
  clearScreen();
  struct TextBox options[3] = {
    {0, 1, "쉬움 (9x9, 지뢰 10개)"},
    {0, 2, "보통 (16x16, 지뢰 40개)"},
    {0, 3, "어려움 (16x30, 지뢰 99개)"}
  };
  for (int i = 0; i < 3; i++) 
    printTextBox(options[i]);
  int selectedOption = 0;
  while (1) {
    setTextColor(GREEN);
    printTextBox(options[selectedOption]);

    char input = getInput();

    setTextColor(RESET);
    printTextBox(options[selectedOption]);

    switch (input) {
      case 'w':
        selectedOption = (selectedOption - 1 + 3) % 3;
        break;
      case 's':
        selectedOption = (selectedOption + 1) % 3;
        break;
      case 'j':
        clearScreen();
        return (enum Difficulty)selectedOption;
    }
  }
} 

void freeBoard(struct Cell** board, enum Difficulty difficulty) {
  int rows;
  switch (difficulty) {
    case EASY: rows = 9; break;
    case MEDIUM: rows = 16; break;
    case HARD: rows = 16; break;
  }
  for (int i = 0; i < rows; i++) 
    free(board[i]);
  free(board);
}
