//
// Created by Emuye Dessasa on 20.10.2022.
//

#ifndef MANDELBROT_GAMELOGIC_H
#define MANDELBROT_GAMELOGIC_H

#include "cellType.h"
#include <vector>
#include <string>
using namespace std;

void addPiece(vector<vector<CellType>>& gameGrid, int colonneIndex, CellType type);
void switchPlayerTurn(CellType& currentPlayerTurn);
void gameStart();
#endif //MANDELBROT_GAMELOGIC_H
