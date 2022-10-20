//
// Created by Emuye Dessasa on 20.10.2022.
//

#ifndef MANDELBROT_GAMEENDEDVERIFICATION_H
#define MANDELBROT_GAMEENDEDVERIFICATION_H

#include "cellType.h"
#include <vector>
using namespace std;

bool checkTie(vector<vector<CellType>> gameGrid);
bool checkWinner (const vector<vector<CellType>>& gameGrid);

#endif //MANDELBROT_GAMEENDEDVERIFICATION_H
