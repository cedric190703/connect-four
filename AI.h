#pragma once
#include "Board.h"
#include <limits.h>
#include <vector>

class AI {
public:
    AI(char token) : token(token) {};
    ~AI() {};
    char getToken() { return this->token; };
    int alphaBeta(Board* board, char opponentToken, int depth, int alpha, int beta, bool maximizingPlayer);
    int findBestMove(Board* board, int depth);

private:
    char token;
};