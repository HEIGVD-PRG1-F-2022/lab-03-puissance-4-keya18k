#include <iostream>
#include <vector>
#include "gameLogic.h"

using namespace std;


/*enum CellType { PLAYER_ONE, PLAYER_TWO, EMPTY };
enum GameEndedReason { PLAYER_WON, TIE };

// gameEndedVerification


// gameInputOutput


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
} */

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