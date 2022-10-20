#include <iostream>
#include <vector>

using namespace std;

const int WIN_COUNT = 4;

enum CellType { PLAYER_ONE, PLAYER_TWO, EMPTY };
enum GameEndedReason { PLAYER_WON, TIE };

// gameEndedVerification
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

// gameInputOutput
char getPlayerChar(CellType player){
    switch(player){
        case PLAYER_ONE: return '1';
        case PLAYER_TWO: return '2';
        default : return ' ';
    }
}
string getPlayerName(CellType player){
    switch(player){
        case PLAYER_ONE : return "Joueur 1";
        case PLAYER_TWO : return "Joueur 2";
    }
}
void display(vector<vector<CellType>> gameGrid){
    for(int c = 0; c < gameGrid[0].size(); c++){
        cout << "  " << c << " ";
    } cout << endl;
    for(int y = 0; y < gameGrid.size(); y++){
        for(int c = 0; c < gameGrid[0].size()*4+1; c++){
            cout << '-';
        }
        cout << endl;
        for(int x = 0; x < gameGrid[0].size(); x++){
            cout << '|' << " " << getPlayerChar(gameGrid[y][x]) << " ";
        }
        cout << '|' << endl;
    }
    for(int c = 0; c < gameGrid[0].size()*4+1; c++){
        cout << '-';
    }
    cout << endl;
}
int getUserIntInput(int min, int max, string message) {
    int input;
    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
        }
        cout << message;
        cin >> input;
        cout << endl;
    } while (cin.fail() || input < min || input >= max);
    return input;
}

// gameLogic
void addPiece(vector<vector<CellType>>& gameGrid, int colonneIndex, CellType type){
    for(int y = gameGrid.size()-1; y >= 0; y--){
        CellType currentType = gameGrid[y][colonneIndex];
        if(currentType == EMPTY){
            gameGrid[y][colonneIndex] = type;
            return;
        }
    }
}
void switchPlayerTurn(CellType& currentPlayerTurn){
    switch(currentPlayerTurn){
        case PLAYER_ONE : currentPlayerTurn = PLAYER_TWO; return;
        case PLAYER_TWO : currentPlayerTurn = PLAYER_ONE; return;
    }
}
void gameStart(){
    const int MIN_COLUMNS_LINES = 4;
    const int MAX_COLUMNS_LINES = 10;


    string gridSizeInputString = "Veuillez insérer le nombre de colonnes (entre " + to_string(MIN_COLUMNS_LINES) +
                                 " et " + to_string(MAX_COLUMNS_LINES) + ") : ";

    bool gameRunning = true;
    CellType playerTurn = PLAYER_ONE;
    GameEndedReason reason = PLAYER_WON;
    int columns = getUserIntInput(MIN_COLUMNS_LINES, MAX_COLUMNS_LINES + 1, gridSizeInputString); // 7
    int lines = getUserIntInput(MIN_COLUMNS_LINES, MAX_COLUMNS_LINES + 1, gridSizeInputString); // 6;
    vector<vector<CellType>> gameGrid (lines, vector<CellType> (columns, EMPTY));


    display(gameGrid);
    do {
        cout << "C'est au " << getPlayerName(playerTurn) << " de joueur." << endl;

        int chosenColumn = getUserIntInput(0, columns, "Veuillez inserer une valeure entre 0 et " +
                                                       to_string(columns - 1) + " (inclus) : ");

        addPiece(gameGrid, chosenColumn, playerTurn);
        gameRunning = !checkWinner(gameGrid);
        display(gameGrid);
        if (gameRunning) {

            if (checkTie(gameGrid)) {
                gameRunning = false;
                reason = TIE;
            }
            switchPlayerTurn(playerTurn);
        }
    } while (gameRunning);

    switch (reason) {
        case PLAYER_WON:
            cout << getPlayerName(playerTurn) << " a gagne";
        case TIE:
            cout << "Personne a gagne";
    }
}

int main() {
    gameStart();

    /*addPiece(gameGrid, 6, PLAYER_ONE);
    addPiece(gameGrid, 6, PLAYER_ONE);
    addPiece(gameGrid, 6, PLAYER_ONE);
    addPiece(gameGrid, 6, PLAYER_TWO);

    addPiece(gameGrid, 5, PLAYER_ONE);
    addPiece(gameGrid, 5, PLAYER_ONE);
    addPiece(gameGrid, 5, PLAYER_TWO);

    addPiece(gameGrid, 4, PLAYER_ONE);
    addPiece(gameGrid, 4, PLAYER_TWO);

    addPiece(gameGrid, 3, PLAYER_ONE);
    display(gameGrid);
    bool winner = checkWinner(gameGrid);
    if (winner) {
        cout << "winner";
    }*/


    return 0;
}