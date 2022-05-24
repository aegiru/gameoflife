#ifndef GRA_H
#define GRA_H

using namespace std;

int countNeighbors(int **board, int y, int x, int width, int height) {
    int sum = 0;
    for (int i = y - height; i <= y + height; i++) {
        for (int j = x - width; j <= x + width; j++) {
            if (board[i][j] == 1) {
                if (i == y && j == x) {

                } else {
                    sum++;
                }

            }
        }
    }

    return sum;
}

int **iterate(int **board, int height, int width, int offsetY, int offsetX, int neighborHeight, int neighborWidth, int *aliveConditions, int *deadConditions, int aliveConditionsCount, int deadConditionsCount) {
    int **newBoard = new int *[BOARD_HEIGHT + 2];
    for (int i = 0; i < BOARD_HEIGHT + 2; i++) {
        newBoard[i] = new int[BOARD_WIDTH + 2];
        for (int j = 0; j < BOARD_WIDTH + 2; j++) {
            newBoard[i][j] = 0;
        }
    }
    for (int i = 0 + offsetY; i < height; i++) {
        for (int j = 0 + offsetX; j < width; j++) {
            int neighbors = countNeighbors(board, i, j, neighborHeight, neighborWidth);
            bool operated = false;
            if (board[i][j] == 1) {
                operated = false;
                for (int k = 0; k < aliveConditionsCount; k++) {
                    if (neighbors == aliveConditions[k]) {
                        newBoard[i][j] = 1;
                        operated = true;
                        continue;
                    }
                }
                if (!operated) {
                    newBoard[i][j] = 0;
                }
            } else {
                for (int l = 0; l < deadConditionsCount; l++) {
                    if (neighbors == deadConditions[l]) {
                        newBoard[i][j] = 1;
                        continue;
                    }
                }
            }
        }
    }

    return newBoard;
}

#endif //GAMEOFLIFE_GRA_H
