# pragma once
#include "Player.h"
#include "Board.h"
#include "AI.h"
using namespace std;

class Game {
public:
    Game(Player& p1, AI& AIplayer, Board* board) : p1(p1), AIplayer(AIplayer), board(board) {};
     ~Game() {
        delete board;
    };
    void printBoard();
    Board* board;
    char getP1Token() { return p1.getToken(); };
    char getAIToken() { return AIplayer.getToken(); };
    string getP1Name() { return p1.getName(); }
    int getAIMove() { return this->AIplayer.findBestMove(this->board, 5); };

private:
    Player p1;
    AI AIplayer;
};