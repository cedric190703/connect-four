# pragma once
#include <iostream>
using namespace std;

class Board {
public :
    Board(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;

        // Create the board of size rows x cols
        this->board = new char*[rows];

        // Create columns
        for(int i = 0; i < rows; i++) {
            this->board[i] = new char[cols];
        }

        // Fill the board with 0
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                this->board[i][j] = '0';
            }
        }
    };
    ~Board() {
        for (int i = 0; i < rows; i++) {
            delete[] board[i];
        }

        delete[] board;
    };
    int isFull();
    int isColumnFull(int i);
    int isValidMove(int);
    void placeToken(int, char);
    char checkWin();
    char getToken(int i, int j) { return this->board[i][j]; };
    int getRow() { return this->rows; };
    int getCol() { return this->cols; };

private:
    char** board;
    int rows;
    int cols;
};