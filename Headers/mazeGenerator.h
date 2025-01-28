#pragma once
#include "cell.h"

#include <stack>
#include <algorithm>
#include <iostream>
#include <random>

class MazeGenerator
{
public:
	MazeGenerator();
	~MazeGenerator();

	Cell cellMatrix[MATRIX_DIMENSION][MATRIX_DIMENSION];
private:
	std::stack<Cell*> cells;

	void GenerateCells();
	void GenerateMaze();
};