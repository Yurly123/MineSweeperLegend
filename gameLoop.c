#include "gameLoop.h"

GameState gameLoop(Cell** board, Difficulty difficulty) {
  printGameScreen(board, difficulty);
  while (1) {
    handleGameInput(board, difficulty);
    updateGameScreen(board, difficulty);

    GameState gameState = checkGameEnd(board, difficulty);
    switch (gameState) {
      case PLAYING: break;
      case GAME_OVER: case WIN:
        return gameState;
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