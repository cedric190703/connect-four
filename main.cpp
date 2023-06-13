#include <iostream>
#include <stdio.h>
#include "Game/Board.h"
#include "Game/Game.h"
#include "Game/Player.h"
#include "AI/AI.h"
using namespace std;

int main() {
    // Initialize Board, Players and Game
    string name;
    char token;

    cout  << endl;
    cout << "What's your name?" << endl;
    cin >> name;

    cout << "Choose your token between << '\033[32mX\033[0m' or '\033[31mO\033[0m'" << endl;
    cin >> token;

    // Check if the user token is correct
    while(token != 'X' && token != 'O') {
        cout << endl;
        cout << "Choose a correct token: '\033[32mX\033[0m' or '\033[31mO\033[0m'" << endl;
        cin >> token;
    }

    cout << endl;
    Player p1(name, token);
    char tokenAI = token == 'X' ? 'O' : 'X';
    int difficulty;
    cout << endl;

    // Select difficulty
    cout << "Select a difficulty: (\033[31m1\033[0m - \033[32m5\033[0m):" << endl;
    cin >> difficulty;

    // Check if the user difficlty is correct
    while(difficulty < 0 || difficulty > 5) {
        cout << endl;
        cout << "Choose a correct difficulty: (\033[31m1\033[0m - \033[32m5\033[0m)" << endl;
        cin >> token;
    }
    cout << endl;
    
    AI AIplayer(tokenAI);
    Board* board = new Board(7, 6);
    Game game(p1, AIplayer, board, difficulty);

    char winner;
    int position;
    int positionAI;
    int tour = 1;

    // Loop until there is a winner
    do {
        printf("Tour Number : %d", tour);
        cout << endl;

        // Draw the current state of the board before any move in this tour
        game.printBoard();
        cout << endl;
        cout << "Choose your column (1-7):" << endl;
        cin >> position;
        cout << endl;
        printf("Position chosen: %d\n", position);
        position--;

        // Check if the position chosen by the player is valid
        while (position < 0 || position > 6 || game.board->isValidMove(position) == -1) {
            cout << "You can't play with this position." << endl;
            cout << "Retry." << endl;
            cin >> position;
            printf("Position chosen: %d\n", position);
            position--;
        }
        game.board->placeToken(game.getP1Token(), position);
        printf("Player: %s\n", game.getP1Name().c_str());

        // Draw player move
        cout << endl;
        game.printBoard();
        cout << endl;

        // Check if the player has win the game 
        winner = game.board->checkWin();
        if(winner != '0') {
            break;
        }

        // AI part turn
        printf("AI turn:\n");
        positionAI = game.getAIMove();
        printf("Position chosen: %d\n", positionAI);
        game.board->placeToken(tokenAI, positionAI);

        // Draw AI move
        cout << endl;
        game.printBoard();
        cout << endl;

        tour++;
        // Check if the AI has win the game
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