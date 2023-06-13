#include "AI.h"

int AI::alphaBeta(Board* board, char playerToken, char opponentToken, int depth, int alpha, int beta, bool maximizingPlayer, int& bestMove) {
    if (depth == 0 || board->checkWin() != '0') {
        return board->evaluate(playerToken, opponentToken);
    }

    for (int move : board->getMoves()) {
        if (maximizingPlayer) {
            Board newBoard(*board);
            newBoard.placeToken(playerToken, move);

            int score = alphaBeta(&newBoard, playerToken, opponentToken, depth - 1, alpha, beta, !maximizingPlayer, bestMove);
            // Update alpha and bestMove if necessary
            if (score > alpha) {
                alpha = score;
                bestMove = move;
            }
        } else {
            Board newBoard(*board);
            newBoard.placeToken(opponentToken, move);

            int score = alphaBeta(&newBoard, playerToken, opponentToken, depth - 1, alpha, beta, !maximizingPlayer, bestMove);
            // Update beta if necessary
            if (score < beta) {
                beta = score;
            }
        }

        // Perform alpha-beta pruning
        if (alpha >= beta) {
            break;
        }
    }

    return maximizingPlayer ? alpha : beta;
}

int AI::findBestMove(Board* board, int depth) {
    int alpha = INT_MIN;
    int beta = INT_MAX;
    char opponentToken = (this->token == 'X') ? 'O' : 'X';
    bool maximizingPlayer = true;
    int bestMove = -1;

    alphaBeta(board, this->token, opponentToken, depth - 1, alpha, beta, maximizingPlayer, bestMove);

    return bestMove != -1 ? bestMove : 0;
}
