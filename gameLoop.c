#include "gameLoop.h"

GameState gameLoop(Cell** board, Difficulty difficulty) {
  initializeBoard(board, difficulty);
  printGameScreen(board, difficulty);
  while (1) {
    handleGameInput(board, difficulty);
    updateGameScreen(board, difficulty);

    GameState gameState = checkGameEnd(board, difficulty);
    switch (gameState) {
      case PLAYING: break;
      case GAME_OVER:
        clearScreen();
        printf("Game Over!");
        waitForInput();
        clearScreen();
        return GAME_OVER;
      case WIN:
        clearScreen();
        printf("You Win!");
        waitForInput();
        clearScreen();
        return WIN;
    }
  }
}

// 표ㅅㅎ
void printGameScreen(Cell** board, Difficulty difficulty) {
  
}

// 표ㅅㅎ
void updateGameScreen(Cell** board, Difficulty difficulty) {
  
}

// 안ㅅㅎ
void handleGameInput(Cell** board, Difficulty difficulty) {
  
}

// 박ㅈㅇ
void floodFill(Cell** board, int x, int y, Difficulty difficulty) {
  
}

// 박ㅈㅇ
GameState checkGameEnd(Cell** board, Difficulty difficulty) {
  
}