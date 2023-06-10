# pragma once
#include "Player.h"
#include "Board.h"
using namespace std;

class Game {
public:
    Game(Player& p1, Player& AI, Board* board) : p1(p1), AI(AI), board(board) {};
     ~Game() {
        delete board;
    };
    void printBoard();
    Board* board;
    char getP1Token() { return p1.getToken(); };
    char getAIToken() { return AI.getToken(); };
    string getP1Name() { return p1.getName(); }

private:
    Player p1;
    Player AI;
};