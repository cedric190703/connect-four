#include <iostream>
#include "Game.h"

void Game::printBoard() {
    // Numbers indexes in the top
    cout << endl;
    for(int x = 1; x <= 7; x++) {
        printf("  %d ", x);
    }
    cout << endl;

    // The text will be printed in green for the player
    // ANd in red for the AI
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
                if(token == this->getAIToken()) {
                    cout << "\033[31m" << token << "\033[0m"; // Red
                } else {
                    cout << "\033[32m" << token << "\033[0m"; // Green
                }
            }
            cout << " ";
        }
        cout << "|" << endl;
    }
    
    for(int x = 0; x < rows; x++) {
            cout << "+---";
        }
    cout << "+" << endl;

    // Numbers indexes in the bottom
    cout << endl;
    for(int x = 1; x <= 7; x++) {
        printf("  %d ", x);
    }
    cout << endl;
}