#include "AI.h"

int AI::alphaBeta(Board* board, char opponentToken, int depth, int alpha, int beta, bool maximizingPlayer) {
    if (depth == 0 || board->checkWin() != '0') {
        return board->evaluate(this->token, opponentToken);
    }

    if (maximizingPlayer) {
        int value = INT_MIN;
        for (int move : board->getMoves()) {
            Board childBoard(*board); // Create a deep copy of the board
            childBoard.placeToken(this->token, move);
            value = max(value, alphaBeta(&childBoard, opponentToken, depth - 1, alpha, beta, false));
            alpha = max(alpha, value);
            if (beta <= alpha) {
                break; // Beta cutoff
            }
        }
        return value;
    } else {
        int value = INT_MAX;
        for (int move : board->getMoves()) {
            Board childBoard(*board); // Create a deep copy of the board
            childBoard.placeToken(opponentToken, move);
            value = min(value, alphaBeta(&childBoard, opponentToken, depth - 1, alpha, beta, true));
            beta = min(beta, value);
            if (beta <= alpha) {
                break; // Alpha cutoff
            }
        }
        return value;
    }
}

int AI::findBestMove(Board* board, int depth) {
    int bestScore = INT_MIN;
    int bestMove = -1;
    int alpha = INT_MIN;
    int beta = INT_MAX;
    char opponentToken = this->token == 'X' ? 'O' : 'X';
    bool maximizingPlayer = true;

    for (int move : board->getMoves()) {
        Board newBoard(*board);
        newBoard.placeToken(this->token, move);

        int score = alphaBeta(&newBoard, opponentToken, depth - 1, alpha, beta, maximizingPlayer);
        
        if (score > bestScore) {
            cout << "score: " << score << endl;
            bestScore = score;
            bestMove = move;
        } else if (score < 0) {
            // If the current move has the same score as the best move so far,
            // prioritize countering the opponent's move
            Board counterBoard(*board);
            counterBoard.placeToken(opponentToken, move);
            int counterScore = alphaBeta(&counterBoard, this->token, depth - 1, alpha, beta, !maximizingPlayer);
            if (counterScore > bestScore) {
                bestScore = counterScore;
                bestMove = move;
            }
        }
    }

    return bestMove;
}