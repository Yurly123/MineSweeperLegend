#include "title.h"

void titleLoop() {
    int selectedOption = 0;
    printTitleScreen(selectedOption);
    while (1) {
        updateTitleScreen(selectedOption);
        handleTitleInput(&selectedOption);
    }
}

void printTitleScreen(int selectedOption) {

}

void updateTitleScreen(int selectedOption) {

}

void handleTitleInput(int* selectedOption) {

}