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
void placeMines(struct Cell** board, enum Difficulty difficulty) { // 2차원 포인터, Difficulty 사용
    if (board == NULL) return;
    
    int rows, cols, num_mines;

    switch (difficulty) {
        case EASY:
            rows = 9;
            cols = 9;
            num_mines = 10;
            break;
        case MEDIUM:
            rows = 16;
            cols = 16;
            num_mines = 40;
            break;
        case HARD:
            rows = 16;
            cols = 30;
            num_mines = 99;
            break;
        default:
            return;
    }

    int placed = 0;
    while (placed < num_mines) {
        int r = rand() % rows;
        int c = rand() % cols;

        if (board[r][c].isMine == 0) {
            board[r][c].isMine = 1;
            placed++;
        }
    }
}

// 김ㅇㅈ
void calculateAdjacentMines(struct Cell** board, enum Difficulty difficulty) {
  
}
