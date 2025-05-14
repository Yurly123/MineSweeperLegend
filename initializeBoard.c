#include "initializeBoard.h"

void initializeBoard(struct Cell** board, enum Difficulty difficulty) {
  initializeArray(board, difficulty);
  placeMines(board, difficulty);
  calculateAdjacentMines(board, difficulty);
}

// 박ㅅㅇ

 // 초기화 함수 정의
void initializeArray(struct Cell** board, enum Difficulty difficulty) {
    int rows = 0, cols = 0;

    switch (difficulty) {
        case EASY:
            rows = 9;
            cols = 9;
            break;
        case MEDIUM:
            rows = 16;
            cols = 16;
            break;
        case HARD:
            rows = 16;
            cols = 30;
            break;
        default:
            return;
    }

    // 보드 초기화
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j].isMine = 0;
            board[i][j].adjacentMines = 0;
            board[i][j].isFlagged = 0;
            board[i][j].isRevealed = 0;
        }
    }
}

int main() {
    enum Difficulty difficulty = MEDIUM;
    int rows = 0, cols = 0;

    switch (difficulty) {
        case EASY:
            rows = 9;
            cols = 9;
            break;
        case MEDIUM:
            rows = 16;
            cols = 16;
            break;
        case HARD:
            rows = 16;
            cols = 30;
            break;
    }

    // 보드 동적 메모리 할당
    struct Cell** board = (struct Cell**)malloc(rows * sizeof(struct Cell*));
    for (int i = 0; i < rows; i++) {
        board[i] = (struct Cell*)malloc(cols * sizeof(struct Cell));
    }

    // 보드 초기화
    initializeArray(board, difficulty);

    // 확인용 출력
    printf("board[0][0]: isMine = %d, isFlagged = %d, isRevealed = %d\n", 
           board[0][0].isMine, board[0][0].isFlagged, board[0][0].isRevealed);

    // 메모리 해제
    for (int i = 0; i < rows; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
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


  

