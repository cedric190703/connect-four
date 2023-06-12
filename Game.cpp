#include <iostream>
#include "Game.h"

void Game::printBoard() {
    int rows = this->board->getRow();
    int cols = this->board->getCol();

    for(int j = 0; j < cols; ++j) {
        // Separate each columns
        for(int x = 0; x < rows; x++) {
            cout << "+---";
        }
        cout << "+" << endl;

        for(int i = 0; i < rows; ++i) {
            cout << "| ";
            char token = this->board->getToken(i, j);
            if(token == '0') {
                cout << " ";
            } else {
                //printf("I: %d and J: %d\n", i, j);
                cout << token;
            }
            cout << " ";
        }
        cout << "|" << endl;
    }
    
    for(int x = 0; x < rows; x++) {
            cout << "+---";
        }
    cout << "+" << endl;
}