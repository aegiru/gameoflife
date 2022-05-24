#ifndef PRINT_H
#define PRINT_H

using namespace std;

void printBoard(int **board, int height, int width, int offsetY, int offsetX) {
    for (int i = 0 + offsetY; i < height; i++) {
        for (int j = 0 + offsetX; j < width; j++) {
            if (board[i][j] == 1) {
                cout << '#';
            } else {
                cout << ' ';
            }
        }
        cout << endl;
    }
}

#endif

