//
// Created by Emuye Dessasa on 20.10.2022.
//

#include "cellType.h"
#include <vector>
using namespace std;

const int WIN_COUNT = 4;


bool checkWinner (const vector<vector<CellType>>& gameGrid) {
    for (int y = 0; y < gameGrid.size(); y++) {
        for (int x = 0; x < gameGrid[0].size(); x++) {
            bool won = true;
            CellType type = gameGrid[y][x];

            if (type == EMPTY) {
                continue;
            }
            // horizontal right
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

            if(won){
                return won;
            }

            won = true;


            // vertical down
            for (int i = 1; i <= WIN_COUNT - 1; i++) {
                if (y + i >= gameGrid.size()) {
                    won = false;
                    break;
                }
                CellType nextCell = gameGrid[y + i][x];
                if (nextCell != type) {
                    won = false;
                    break;
                }
            }
            if(won){
                return won;
            }

            won = true;

            // diagonal right
            for (int i = 1; i <= WIN_COUNT - 1; i++) {
                if (y + i >= gameGrid.size() || x + i >= gameGrid[0].size()) {
                    won = false;
                    break;
                }
                CellType nextCell = gameGrid[y + i][x + i];
                if (nextCell != type) {
                    won = false;
                    break;
                }
            }
            if(won){
                return won;
            }

            won = true;
            // diagonal left
            for (int i = 1; i <= WIN_COUNT - 1; i++) {
                if (y + i >= gameGrid.size() || x - i < 0) {
                    won = false;
                    break;
                }
                CellType nextCell = gameGrid[y + i][x - i];
                if (nextCell != type) {
                    won = false;
                    break;
                }
            }

            if (won) {
                return true;
            }
        }
    }
    return false;
}
bool checkTie(vector<vector<CellType>> gameGrid) {
    for (int y = 0; y < gameGrid.size(); y++) {
        for (int x = 0; x < gameGrid[0].size(); x++) {
            if (gameGrid[y][x] == EMPTY) {
                return false;
            }
        }
    }

    return true;
}