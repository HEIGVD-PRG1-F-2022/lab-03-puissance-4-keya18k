/*
 * Fichier : gameInputOutput.cpp
 * Autheur : Emuye Dessasa, Boris Hutzli
 * Date    : 20.10.22
 *
 * But     : Fichier contenant les fonctions concernant l'affichage et la saisie pour le jeu
 */

#include "cellType.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

const string PLAYER_ONE_NAME = "Joueur 1";
const string PLAYER_TWO_NAME = "Joueur 2";
const char PLAYER_ONE_CHAR = '1';
const char PLAYER_TWO_CHAR = '2';

// Retourne le charactère représentant le pion des joueurs
char getPlayerChar(CellType player){
    switch(player){
        case PLAYER_ONE: return PLAYER_ONE_CHAR;
        case PLAYER_TWO: return PLAYER_TWO_CHAR;
        default : return ' ';
    }
}

// Affiche les règles du jeu
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

// Retourne le nom des joueurs
string getPlayerName(CellType player){
    switch(player){
        case PLAYER_ONE : return PLAYER_ONE_NAME;
        case PLAYER_TWO : return PLAYER_TWO_NAME;
    }
}

// Affiche la grille du jeu
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

// Saisie d'une valeur int de l'utilisateur
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