//
// Created by Emuye Dessasa on 20.10.2022.
//
#include <string>
#include <vector>
#include <iostream>
#include "cellType.h"
#include "gameInputOutput.h"
#include "gameEndedVerification.h"


using namespace std;


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
    enum GameEndedReason { PLAYER_WON, TIE };
    const int MIN_COLUMNS_LINES = 4;
    const int MAX_COLUMNS_LINES = 10;
    displayRules();

    string columnInputString = "Veuillez inserer le nombre de colonnes (entre " + to_string(MIN_COLUMNS_LINES) +
                                 " et " + to_string(MAX_COLUMNS_LINES) + ") : ";
    string lineSizeInputString = "Veuillez inserer le nombre de lignes (entre " + to_string(MIN_COLUMNS_LINES) +
                                 " et " + to_string(MAX_COLUMNS_LINES) + ") : ";

    bool gameRunning = true;
    CellType playerTurn = PLAYER_ONE;
    GameEndedReason reason = PLAYER_WON;
    int columns = getUserIntInput(MIN_COLUMNS_LINES, MAX_COLUMNS_LINES + 1, columnInputString); // 7
    int lines = getUserIntInput(MIN_COLUMNS_LINES, MAX_COLUMNS_LINES + 1, lineSizeInputString); // 6;
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
            cout << getPlayerName(playerTurn) << " a gagne"; break;
        case TIE:
            cout << "Personne a gagne"; break;
    }
}