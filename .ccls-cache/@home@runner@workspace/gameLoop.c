#include "gameLoop.h"

void gameLoop(Cell** board, Difficulty difficulty) {
  initializeBoard(board, difficulty);
  printGameScreen(board, difficulty);
  while (1) {
    handleInput(board, difficulty);
    updateGameScreen(board, difficulty);
  }
}

// 표ㅅㅎ
void printGameScreen(Cell** board, Difficulty difficulty) {
  
}

// 표ㅅㅎ
void updateGameScreen(Cell** board, Difficulty difficulty) {
  
}

// 안ㅅㅎ
void handleInput(Cell** board, Difficulty difficulty) {
  
}

