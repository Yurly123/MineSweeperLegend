#include "initializeBoard.h"

void initializeBoard(struct Cell** board, enum Difficulty difficulty) {
  initializeArray(board, difficulty);
  placeMines(board, difficulty);
  calculateAdjacentMines(board, difficulty);
}

// 박ㅅㅇ
void initializeArray(struct Cell** board, enum Difficulty difficulty) {
  
}

// 최ㅇㅇ
void placeMines(struct Cell** board, enum Difficulty difficulty) {
  
}

// 김ㅇㅈ
void calculateAdjacentMines(struct Cell** board, enum Difficulty difficulty) {
  
}