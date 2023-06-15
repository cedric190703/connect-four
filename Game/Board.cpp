#include "Board.h"

int Board::isFull() {
    for(int i = 0; i < this->rows; i++) {
        if(isColumnFull(i) == -1) {
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

void Board::placeToken(char token, int i) {
    // But we need to have an empty case with the function isColumnFull
    int idx = isColumnFull(i);
    if(idx == -1) {
        return;
    }
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
        for(int j = this->rows-1; j >= 3; --j) {
            if(this->board[j][i] != '0' &&
                this->board[j][i] == this->board[j - 1][i] &&
                this->board[j][i] == this->board[j - 2][i] &&
                this->board[j][i] == this->board[j - 3][i]) {
                    return this->board[j][i];
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
                return this->board[i][j];
            }
        }
    }

    return '0';
}

vector<int> Board::getMoves() {
    vector<int> moves;
    for (int row = 0; row < this->rows; ++row) {
        if (isValidMove(row) != -1) {
            moves.push_back(row);
        }
    }
    return moves;
}

void printBoard(char** board, int rows, int cols) {
    cout << endl;
    for(int x = 0; x < 7; x++) {
        printf(" %d ", x);
    }
    cout << endl;

    for(int j = 0; j < cols; ++j) {
        // Separate each columns
        for(int x = 0; x < rows; x++) {
            cout << "+---";
        }
        cout << "+" << endl;

        for(int i = 0; i < rows; ++i) {
            cout << "| ";
            char token = board[i][j];
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

// Function that calculates the heuristic value
int Board::evaluate(char AItoken, char opponentToken) {

    int score = 0;

    // Check for vertical lines
    for(int i = 0; i < this->rows; ++i) {
        for(int j = this->cols-1; j >= 3; --j) {
            char token = this->board[i][j];
            if(token != '0' &&
                token == this->board[i][j - 1] &&
                token == this->board[i][j - 2] &&
                token == this->board[i][j - 3]) {
                if(token == AItoken) {
                    score += 5000;
                } else if(token == opponentToken) {
                    score -= 5000;
                }
            } else if(token != '0' &&
                token == this->board[i][j - 1] &&
                token == this->board[i][j - 2]) {
                if(token == AItoken) {
                    score += 1000;
                } else if(token == opponentToken) {
                    score -= 1000;
                }
            } else if(token != '0' &&
                token == this->board[i][j - 1]) {
                if(token == AItoken) {
                    score += 100;
                } else if(token == opponentToken) {
                    score -= 100;
                }
            }
        }
    }
    
    // Check for horizontal lines
    for(int i = 0; i < this->cols; ++i) {
        for(int j = this->rows-1; j >= 3; --j) {
            char token = this->board[j][i];
            if(token != '0' &&
                token == this->board[j - 1][i] &&
                token == this->board[j - 2][i] &&
                token == this->board[j - 3][i]) {
                if(token == AItoken) {
                    score += 5000;
                } else if(token == opponentToken) {
                    score -= 5000;
                }
            } else if(token != '0' &&
                token == this->board[j - 1][i] &&
                token == this->board[j - 2][i]) {
                if(token == AItoken) {
                    score += 1000;
                } else if(token == opponentToken) {
                    score -= 1000;
                }
            } else if(token != '0' &&
                token == this->board[j - 1][i]) {
                if(token == AItoken) {
                    score += 100;
                } else if(token == opponentToken) {
                    score -= 100;
                }
            }
        }
    }

    // Check diagonal lines (top-right to bottom-left)
    for (int i = 0; i < rows - 3; ++i) {
        for (int j = 3; j < cols; ++j) {
            char token = this->board[i][j];
            if (token != '0' &&
                token == this->board[i + 1][j - 1] &&
                token == this->board[i + 2][j - 2] &&
                token == this->board[i + 3][j - 3]) {
                if(token == AItoken) {
                    score += 5000;
                } else if(token == opponentToken) {
                    score -= 5000;
                } else if(token != '0' &&
                token == this->board[i + 1][j - 1] &&
                token == this->board[i + 2][j - 2]) {
                if(token == AItoken) {
                    score += 500;
                } else if(token == opponentToken) {
                    score -= 500;
                }
                } else if(token != '0' &&
                    token == this->board[i + 1][j - 1]) {
                    if(token == AItoken) {
                        score += 100;
                    } else if(token == opponentToken) {
                        score -= 100;
                    }
                }
            }
        }
    }

    // Check diagonal lines (top-left to bottom-right)
    for (int i = 0; i < rows - 3; ++i) {
        for (int j = 0; j < cols - 3; ++j) {
            char token = this->board[i][j];
            if (token != '0' &&
                token == this->board[i + 1][j + 1] &&
                token == this->board[i + 2][j + 2] &&
                token == this->board[i + 3][j + 3]) {
                if(token == AItoken) {
                    score += 5000;
                } else if(token == opponentToken) {
                    score -= 5000;
                } else if(token != '0' &&
                token == this->board[i + 1][j + 1] &&
                token == this->board[i + 2][j + 2]) {
                if(token == AItoken) {
                    score += 1000;
                } else if(token == opponentToken) {
                    score -= 1000;
                }
                } else if(token != '0' &&
                token == this->board[i + 1][j + 1]) {
                    if(token == AItoken) {
                        score += 100;
                    } else if(token == opponentToken) {
                        score -= 100;
                    }
                }
            }
        }
    }

    return score;
}
