#pragma once
#include "cell.h"

#include <stack>
#include <algorithm>
#include <iostream>
#include <random>
#include <ctime>

class MazeGenerator
{
public:
	MazeGenerator();
	~MazeGenerator();

	void Generate();

	Cell cellMatrix[MATRIX_DIMENSION][MATRIX_DIMENSION];
private:
	std::stack<Cell*> cells;

	void GenerateCells();
	void GenerateMaze();
};