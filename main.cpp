#include <iostream>
#include <chrono>
#include <thread>

#define BOARD_WIDTH 70
#define BOARD_HEIGHT 23
#define BOARD_OFFSETX 1
#define BOARD_OFFSETY 1
#define NEIGHBOR_HEIGHT 1
#define NEIGHBOR_WIDTH 1

#include "print.h"
#include "gra.h"

using namespace std;


int main() {
    int **board = new int *[BOARD_HEIGHT + 2];
    for (int i = 0; i < BOARD_HEIGHT + 2; i++) {
        board[i] = new int[BOARD_WIDTH + 2];
        for (int j = 0; j < BOARD_WIDTH + 2; j++) {
            board[i][j] = 0;
        }
    }

    int aliveConditionsCount = 2;
    int deadConditionsCount = 1;
    int *aliveConditions = new int[aliveConditionsCount];
    int *deadConditions = new int[deadConditionsCount];
    aliveConditions[0] = 2;
    aliveConditions[1] = 3;
    deadConditions[0] = 3;


    board[4][4] = 1;
    board[4][7] = 1;
    board[5][8] = 1;
    board[6][8] = 1;
    board[7][8] = 1;
    board[7][7] = 1;
    board[7][6] = 1;
    board[7][5] = 1;
    board[6][4] = 1;

    while (true) {
        system("cls");
        printBoard(board, BOARD_HEIGHT, BOARD_WIDTH, BOARD_OFFSETY, BOARD_OFFSETX);
        board = iterate(board, BOARD_HEIGHT, BOARD_WIDTH, BOARD_OFFSETX, BOARD_OFFSETY, NEIGHBOR_HEIGHT, NEIGHBOR_WIDTH, aliveConditions, deadConditions, aliveConditionsCount, deadConditionsCount);
        this_thread::sleep_for(chrono::milliseconds(500));
    }


    for (int i = 0; i < BOARD_HEIGHT + 2; i++) {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}