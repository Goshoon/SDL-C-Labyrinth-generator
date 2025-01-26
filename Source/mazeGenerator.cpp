#include "mazeGenerator.h"
#include <iostream>

MazeGenerator::MazeGenerator()
{

}

MazeGenerator::~MazeGenerator()
{

}

void MazeGenerator::Generate()
{
	for (int i = 0; i < MATRIX_DIMENTION; ++i)
    {
        for (int j = 0; j < MATRIX_DIMENTION; ++j)
        {
            cellMatrix[i][j] = Cell(i * CELL_WIDTH, j * CELL_HEIGHT);
        }
    }
}