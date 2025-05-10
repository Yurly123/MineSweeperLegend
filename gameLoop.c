#include "gameLoop.h"

enum GameState gameLoop(struct Cell** board, enum Difficulty difficulty) {
  printGameScreen(board, difficulty);
  while (1) {
    handleGameInput(board, difficulty);
    updateGameScreen(board, difficulty);

    enum GameState gameState = checkGameEnd(board, difficulty);
    switch (gameState) {
      case PLAYING: break;
      case GAME_OVER: case WIN:
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
void handleGameInput(struct Cell** board, enum Difficulty difficulty) {
  
}

// 박ㅈㅇ
void floodFill(struct Cell** board, int x, int y, enum Difficulty difficulty) {
  
}

// 박ㅈㅇ
enum GameState checkGameEnd(struct Cell** board, enum Difficulty difficulty) {
  
}