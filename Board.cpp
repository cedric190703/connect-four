#include "Board.h"
#include <stdio.h>

int Board::isFull() {
    for(int i = 0; i < this->rows; i++) {
        if(!isColumnFull(i)) {
            return 0;
        }
    }
    return 1;
}

int Board::isColumnFull(int i) {
    // Returns the position of the first empty case in the board
    // Otherwise returns 0
    for(int j = this->cols-1; j >= 0; --j) {
        if(this->board[i][j] == '0') {
            return j;
        }
    }
    return -1;
}

int Board::isValidMove(int i) {
    int idx = isColumnFull(i);
    if(idx == -1) {
        return -1;
    }
    return idx;
}   

void Board::placeToken(int i, char token) {
    // We suppose that the idx is valid
    // But we need to have an empty case with the function isColumnFull
    int idx = isColumnFull(i);
    this->board[i][idx] = token;
}

char Board::checkWin() {
    // Check for vertical lines
    for(int i = 0; i < this->rows; ++i) {
        for(int j = this->cols-1; j > 3; --j) {
            if(this->board[i][j] != '0' &&
                this->board[i][j] == this->board[i][j - 1] &&
                this->board[i][j] == this->board[i][j - 2] &&
                this->board[i][j] == this->board[i][j - 3]) {
                    return this->board[i][j];
                }
        }
    }

    // Check for horizontal lines
    for(int i = 0; i < this->cols; ++i) {
        for(int j = 0; j < this->rows-4; ++j) {
            if(this->board[i][j] != '0' &&
                this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2] &&
                this->board[i][j] == this->board[i][j + 3]) {
                    return this->board[i][j];
                }
        }
    }

    // Check diagonal lines (top-right to bottom-left)
    for (int i = 0; i < rows - 3; ++i) {
        for (int j = 3; j < cols; ++j) {
            if (this->board[i][j] != '0' &&
                this->board[i][j] == this->board[i + 1][j - 1] &&
                this->board[i][j] == this->board[i + 2][j - 2] &&
                this->board[i][j] == this->board[i + 3][j - 3]) {
                return this->board[i][j];
            }
        }
    }

    // Check diagonal lines (top-left to bottom-right)
    for (int i = 0; i < rows - 3; ++i) {
        for (int j = 0; j < cols - 3; ++j) {
            if (this->board[i][j] != '0' &&
                this->board[i][j] == this->board[i + 1][j + 1] &&
                this->board[i][j] == this->board[i + 2][j + 2] &&
                this->board[i][j] == this->board[i + 3][j + 3]) {
                return this->board[i][j]; // Return the winning player's token
            }
        }
    }

    return '0';
}