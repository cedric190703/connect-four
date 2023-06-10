#include <iostream>
#include <stdio.h>
#include "Game.h"

int main() {
    // Initialize Board, Players and Game
    string name;
    char token;
    cout << "What's your name?" << endl;
    cin >> name;
    cout << "Choose your token between 'X' or 'O'" << endl;
    cin >> token;
    Player p1(name, token, 0);
    char tokenAI = token == 'X' ? 'O' : 'X';
    Player AI("AI", tokenAI, 1);
    Board* board = new Board(7, 6);
    Game game(p1, AI, board);
    char winner;
    int position;
    int tour = 1;
    do {
        printf("Tour Number : %d", tour);
        cout << endl;
        game.printBoard();
        cout << endl;
        cout << "Choose your column (1-6):" << endl;
        cin >> position;
        cout << endl;
        printf("Position chosen: %d\n", position);
        position--;
        while (position < 0 || position > 5 || game.board->isValidMove(position) == -1) {
            cout << "You can't play with this position." << endl;
            cout << "Retry." << endl;
            cin >> position;
            printf("Position chosen: %d\n", position);
            position--;
        }
        game.board->placeToken(position, game.getP1Token());
        printf("Player: %s", game.getP1Name().c_str());
        cout << endl;
        game.printBoard();
        cout << endl;

        // AI turn with the MiniMax algorithm :
        //////////
        // TODO //
        //////////

        cout << endl;
        tour++;
        winner = game.board->checkWin();
    } while (winner == '0');
    if(p1.getToken() == winner) {
        cout << "You just won the game !!!" << endl;
    }
    else {
        cout << "You just lose the game." << endl;
    }

    return 0;
}