#include "gameLoop.h"

enum GameState gameLoop(struct Cell** board, enum Difficulty difficulty, time_t* gameTime) {
  printGameScreen(board, difficulty);

  struct Coord cursor = {0, 0};
  int isFirstClick = 1;
  time_t startTime, endTime;
  while (1) {
    handleGameInput(board, difficulty, &cursor);
    updateGameScreen(board, difficulty);

    if (isFirstClick) {
      isFirstClick = 0;
      time(&startTime);
    }

    enum GameState gameState = checkGameEnd(board, difficulty);
    switch (gameState) {
      case PLAYING: break;
      case GAME_OVER: case WIN:
        time(&endTime);
        *gameTime = difftime(endTime, startTime);
        return gameState;
    }
  }
}

// 표ㅅㅎ
void printGameScreen(struct Cell** board, enum Difficulty difficulty) {
  
}

// 표ㅅㅎ
void updateGameScreen(struct Cell** board, enum Difficulty difficulty) {
  
}

// 안ㅅㅎ
void handleGameInput(struct Cell** board, enum Difficulty difficulty, struct Coord* cursor) {
  
}

// 박ㅈㅇ
void floodFill(struct Cell** board, enum Difficulty difficulty, struct Coord target) {
  int x = target.x, y = target.y;
  if (board[y][x].adjacentMines != 0)
    return;

  int rows, cols;
  switch (difficulty) {
    case EASY: rows = 9; cols = 9; break;
    case MEDIUM: rows = 16; cols = 16; break;
    case HARD: rows = 16; cols = 30; break;
  }

  for (int i = y - 1; i <= y + 1; i++) {
    for (int j = x - 1; j <= x + 1; j++) {
      if (i < 0 || i >= rows || j < 0 || j >= cols)
        continue;
      if (board[i][j].isRevealed)
        continue;

      board[i][j].isRevealed = 1;
      floodFill(board, difficulty, (struct Coord){j, i});
    }
  }
}

// 박ㅈㅇ
enum GameState checkGameEnd(struct Cell** board, enum Difficulty difficulty) {
  int rows, cols, mines;
  switch (difficulty) {
    case EASY: rows = 9; cols = 9; mines = 10; break;
    case MEDIUM: rows = 16; cols = 16; mines = 40; break;
    case HARD: rows = 16; cols = 30; mines = 99; break;
  }

  int leftCells = rows * cols - mines;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      struct Cell cell = board[i][j];
      if (cell.isRevealed && cell.isMine)
        return GAME_OVER;
      if (cell.isRevealed && !cell.isMine)
        leftCells--;
    }
  }
  
  if (leftCells == 0)
    return WIN;
  else return PLAYING;
}