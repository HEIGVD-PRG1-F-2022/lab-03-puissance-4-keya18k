#include <iostream>
#include <vector>

using namespace std;

const int WIN_COUNT = 4;

enum CellType { PLAYER_ONE, PLAYER_TWO, EMPTY };

bool checkWinner (const vector<vector<CellType>>& gameGrid) {
    for (int y = 0; y < gameGrid.size(); y++) {
        for (int x = 0; x < gameGrid[0].size(); x++) {
            CellType type = gameGrid[y][x];

            if (type == EMPTY) {
                continue;
            }

            // horizontal right
            {
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
                    return true;
                }
            }


            // vertical down
            {
                bool won = true;
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
                if (won) {
                    return true;
                }
            }

            // diagonal right
            {
                bool won = true;
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
                if (won) {
                    return true;
                }
            }

            // diagonal left
            {
                bool won = true;
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
    }

    return false;
}

char getPlayerChar(CellType type){
    switch(type){
        case PLAYER_ONE: return '1';
        case PLAYER_TWO: return '2';
        default : return ' ';
    }
}
void addPiece(vector<vector<CellType>>& gameGrid, int colonneIndex, CellType type){
    for(int y = gameGrid.size()-1; y >= 0; y--){
        CellType currentType = gameGrid[y][colonneIndex];
        if(currentType == EMPTY){
            gameGrid[y][colonneIndex] = type;
            return;
        }
    }
}
void display(vector<vector<CellType>> gameGrid){
    for(int c = 0; c < gameGrid[0].size(); c++){
        cout << "  " << c << " ";
    }
    for(int y = 0; y < gameGrid.size(); y++){
        for(int c = 0; c < gameGrid[0].size()*4+1; c++){
            cout << '-';
        }
        cout << endl;
        for(int x = 0; x < gameGrid[0].size(); x++){
            cout << '|' << " " << getPlayerChar(gameGrid[y][x]) << " ";
        }
        cout << '|' << endl;
    }for(int c = 0; c < gameGrid[0].size()*4+1; c++){
        cout << '-';
    }
}
int main() {
    int colomns = 7;
    int lines = 6;

    vector<vector<CellType>> gameGrid (lines, vector<CellType> (colomns, EMPTY));

    bool gameRunning = true;

    do {
        int chosenColumn;

        do {
            cout << "Veuillez insérer une valeure entre 0 et " << gameGrid[0].size() - 1 << " (inclus) : ";
        } while (chosenColumn < 0 || chosenColumn >= gameGrid[0].size());
    } while (gameRunning);


   /* gameGrid[3] = {
            EMPTY, EMPTY, EMPTY, PLAYER_ONE, PLAYER_ONE, PLAYER_ONE, PLAYER_ONE
    };*/
    addPiece(gameGrid, 6, PLAYER_ONE);
    addPiece(gameGrid, 6, PLAYER_ONE);
    addPiece(gameGrid, 6, PLAYER_ONE);
    addPiece(gameGrid, 6, PLAYER_TWO);

    addPiece(gameGrid, 5, PLAYER_ONE);
    addPiece(gameGrid, 5, PLAYER_ONE);
    addPiece(gameGrid, 5, PLAYER_TWO);

    addPiece(gameGrid, 4, PLAYER_ONE);
    addPiece(gameGrid, 4, PLAYER_TWO);

    addPiece(gameGrid, 3, PLAYER_TWO);
    display(gameGrid);
    bool winner = checkWinner(gameGrid);
    if (winner) {
        cout << "winner";
    }


    return 0;
}