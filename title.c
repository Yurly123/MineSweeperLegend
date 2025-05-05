#include "title.h"

void titleLoop() {
  Option options[TITLE_OPTIONS_COUNT] = {
    {10, 21, "시작하기"},
    {30, 21, "게임 설명"},
    {50, 21, "랭킹"},
    {70, 21, "종료하기"},
  };
  int selectedOption = 0;
  while(1) {
    printTitleScreen(options);
    handleTitleInput(options, &selectedOption);

    switch (selectedOption) {
      case 0: // 시작하기
        clearScreen();
        break;
      case 1: // 게임 설명
        clearScreen();
        break;
      case 2: // 랭킹
        rankingLoop();
        break;
      case 3: // 종료하기
        clearScreen();
        exit(0);
    }
  }
}

void printTitleScreen(Option* options) {
  clearScreen();
  gotoxy(0, 0);
  puts("                                                                                                    ");
  puts("                                                                                                    ");
  puts("          ■     ■  ■                  ■■■■■                                                         ");
  puts("          ■■   ■■                    ■                                                              ");
  puts("          ■ ■ ■ ■  ■  ■■■■    ■■■     ■■■■■   ■  ■  ■   ■■■    ■■■    ■■■    ■■■   ■■■■             ");
  puts("          ■  ■  ■  ■  ■   ■  ■  ■■         ■  ■  ■  ■  ■  ■■  ■  ■■  ■   ■  ■  ■■  ■   ■            ");
  puts("          ■     ■  ■  ■   ■   ■■      ■■■■■    ■■ ■■    ■■     ■■    ■■■■    ■■    ■                ");
  puts("                                                                     ■                              ");
  puts("                                                                     ■                              ");
  puts("           ■■■                                                ■■                                    ");
  puts("             ■                                               ■                                      ");
  puts("             ■       ■■■■     ■■■   ■  ■■■■   ■ ■■■      ■■■■                                       ");
  puts("            ■       ■  ■■■  ■    ■ ■  ■  ■■■  ■    ■   ■    ■                                       ");
  puts("           ■■■      ■       ■     ■   ■       ■    ■  ■     ■                                       ");
  puts("              ■■■■   ■■■■    ■■■■■     ■■■■  ■     ■   ■■■■ ■                                       ");
  puts("                           ■    ■                                                                   ");
  puts("                            ■■■■                                                                    ");
  puts("                                                                                                    ");
  puts("====================================================================================================");
  puts("                                                                                                    ");
  puts("                                                                                                    ");
  puts("                                                                                                    ");
  puts("                                                                                                    ");
  puts("                                                                                                    ");

  for (int i = 0; i < TITLE_OPTIONS_COUNT; ++i) {
    printOption(options[i]);
  }
  
  setColor(BRIGHT_BLACK);
  printxy(33, 23, "(w,a,s,d) 이동 / (j) 선택");
  setColor(RESET);
}

void handleTitleInput(Option* options, int *selectedOption) {
  while (1) {
    setColor(GREEN);
    printOption(options[*selectedOption]);
    
    char input = getInput();

    setColor(RESET);
    printOption(options[*selectedOption]);

    switch (input) {
      case 'a':
        *selectedOption = (*selectedOption - 1 + TITLE_OPTIONS_COUNT) % TITLE_OPTIONS_COUNT;
        break;
      case 'd':
        *selectedOption = (*selectedOption + 1) % TITLE_OPTIONS_COUNT;
        break;
      case 'j':
        return;
      default: break;
    }
  }
}