#include "title.h"

void titleLoop() {
  struct TextBox options[TITLE_OPTIONS_COUNT] = {
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
        gameFlow();
        break;
      case 1: // 게임 설명
        printHelpScreen();
        break;
      case 2: // 랭킹
        rankingLoop();
        break;
      case 3: // 종료하기
        clearScreen();
        return;
    }
  }
}

void printTitleScreen(struct TextBox* options) {
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
    printTextBox(options[i]);
  }
  
  setTextColor(BRIGHT_BLACK);
  printxy(33, 23, "(w,a,s,d) 이동 / (j) 선택");
  setTextColor(RESET);
}

void handleTitleInput(struct TextBox* options, int *selectedOption) {
  while (1) {
    setTextColor(GREEN);
    printTextBox(options[*selectedOption]);
    
    char input = getInput();

    setTextColor(RESET);
    printTextBox(options[*selectedOption]);

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