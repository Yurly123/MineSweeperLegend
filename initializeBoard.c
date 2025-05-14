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
  int rows, colums;
  int dx[8] = {-1,-1,0,1,1,1,0,-1};
  int dy[8] = {0,1,1,1,0,-1,-1,-1};
  if (difficulty == EASY){
    colums = 9;
    rows = 9;
    
  }else if (difficulty == MEDIUM){
    colums = 16;
    rows = 16;
  }else{
    colums = 30;
    rows = 16;
  }
  for(int r=0; r< rows;r++){
    for(int c = 0; c<colums; c++){
      board[r][c].adjacentMines =0;
      if(board[r][c].isMine){
          continue;}
      for(int i =0; i<8;i++){       
        int x = c + dx[i];
        int y = r + dy[i];
        if(0<=x && x<colums&& 0<=y && y<rows){
          if(board[y][x].isMine == 1){
            board[r][c].adjacentMines++;
          }else{
            continue;
          }
        }
      }
    
    }


  }
}


  

