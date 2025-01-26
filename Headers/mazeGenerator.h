#pragma once
#include "cell.h"

#include <stack>

class MazeGenerator
{
public:
	MazeGenerator();
	~MazeGenerator();

	void Generate();

	Cell cellMatrix[MATRIX_DIMENTION][MATRIX_DIMENTION];
private:
	std::stack<Cell*> cells;
};