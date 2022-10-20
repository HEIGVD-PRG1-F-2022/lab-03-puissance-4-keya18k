//
// Created by Emuye Dessasa on 20.10.2022.
//

#include "cellType.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

char getPlayerChar(CellType player){
    switch(player){
        case PLAYER_ONE: return '1';
        case PLAYER_TWO: return '2';
        default : return ' ';
    }
}
void displayRules(){

    cout << "--------------" << endl;
    cout << "|Regle du jeu|" << endl;
    cout << "--------------" << endl;
    cout << "Le but du jeu est d'aligner une suite de 4 pions de " << endl
            << "Tour a tour, les deux joueurs placent un pion dans la colonne de leur choix, " << endl
            << "le pion va jusqu'a la position la plus basse de la colonne " << endl
            << "Le vainqueur est le joueur qui aligne 4 pions (horizontal, vertical ou diagonal) " << endl
            << "Si, toutes les cases sont remplies et qu'il n'y a aucun alignement" << endl
            << "la partie est declaree nulle." << endl << endl;
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