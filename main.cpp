#include <iostream>
#include <vector>

using namespace std;

const int WIN_COUNT = 4;

enum CellType { PLAYER_ONE, PLAYER_TWO, EMPTY };

void checkWinner ( vector<vector<CellType>> gameGrid) {
    for (int y = 0; y < gameGrid.size(); y++) {
        for (int x = 0; x < gameGrid[0].size(); x++) {
            CellType type = gameGrid[y][x];

            if (type == EMPTY) {
                continue;
            }

            // horizontal right
            bool won = true;
            for (int i = 1; i <= WIN_COUNT - 1; i++) {
                if (x + i >= gameGrid[0].size()) {
                    won = false;
                    break;
                }
                CellType nextCell = gameGrid[y][x + i];
                if (nextCell != type) {
                    won = false;
                    break;
                }
            }
            if (won) {
                cout << "gagner";
            }


            // vertical down

            // diagonal right

            // diagonal left
        }
    }
}

int main() {
    int colomns = 7;
    int lines = 6;

    vector<vector<CellType>> gameGrid (lines, vector<CellType> (colomns, EMPTY));

    gameGrid[3] = {
            EMPTY, EMPTY, EMPTY, PLAYER_ONE, PLAYER_ONE, PLAYER_ONE, PLAYER_ONE
    };

    checkWinner(gameGrid);

    return 0;
}