//
// Created by Emuye Dessasa on 20.10.2022.
//

#ifndef MANDELBROT_GAMEINPUTOUTPUT_H
#define MANDELBROT_GAMEINPUTOUTPUT_H

#include "cellType.h"
#include <vector>
#include <string>
using namespace std;
char getPlayerChar(CellType player);
string getPlayerName(CellType player);
int getUserIntInput(int min, int max, string message);
void display(vector<vector<CellType>> gameGrid);
void displayRules();
#endif //MANDELBROT_GAMEINPUTOUTPUT_H
