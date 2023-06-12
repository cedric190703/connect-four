# pragma once
#include <iostream>
#include <tuple>
#include <vector>
#include <stdio.h>
#include <math.h>
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
    Board(const Board& board) {
        this->rows = board.rows;
        this->cols = board.cols;

        this->board = new char*[rows];

        for(int i = 0; i < rows; i++) {
            this->board[i] = new char[cols];
            for(int j = 0; j < cols; j++) {
                this->board[i][j] = board.board[i][j];
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
    void placeToken(char, int);
    char checkWin();
    char getToken(int i, int j) { return this->board[i][j]; };
    int getRow() { return this->rows; };
    int getCol() { return this->cols; };
    // Heuristic function
    int evaluate(char, char);
    vector<int> getMoves();

private:
    char** board;
    int rows;
    int cols;
};