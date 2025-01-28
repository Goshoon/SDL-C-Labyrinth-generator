#include "mazeGenerator.h"

MazeGenerator::MazeGenerator()
{
	GenerateCells();
    GenerateMaze();
}

MazeGenerator::~MazeGenerator()
{
    
}

void MazeGenerator::GenerateCells()
{
	for (int i = 0; i < MATRIX_DIMENSION; ++i)
        for (int j = 0; j < MATRIX_DIMENSION; ++j)
            cellMatrix[i][j] = Cell(i * CELL_WIDTH, j * CELL_HEIGHT);
}

void MazeGenerator::GenerateMaze()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, MATRIX_DIMENSION - 1);

    int horizontal = dis(gen);
    int vertical = dis(gen);
    bool finished = false;
    
    std::cout << "Posicion inicial: " << horizontal << ", " << vertical << std::endl;
    cells.push(&cellMatrix[horizontal][vertical]);
    cellMatrix[horizontal][vertical].visited = true;

    while (!finished)
    {
        bool moved = false;
        int directions[] = {0, 1, 2, 3};
        std::shuffle(std::begin(directions), std::end(directions), gen);

        for (int direction : directions)
        {
            switch (direction)
            {
            case 0: // Up
                if (vertical > 0 && !cellMatrix[horizontal][vertical - 1].visited)
                {
                    cellMatrix[horizontal][vertical].upOpen = true;
                    vertical--;
                    cellMatrix[horizontal][vertical].downOpen = true;
                    moved = true;
                }
                break;
            case 1: // Down
                if (vertical < MATRIX_DIMENSION - 1 && !cellMatrix[horizontal][vertical + 1].visited)
                {
                    cellMatrix[horizontal][vertical].downOpen = true;
                    vertical++;
                    cellMatrix[horizontal][vertical].upOpen = true;
                    moved = true;
                }
                break;
            case 2: // Left
                if (horizontal > 0 && !cellMatrix[horizontal - 1][vertical].visited)
                {
                    cellMatrix[horizontal][vertical].leftOpen = true;
                    horizontal--;
                    cellMatrix[horizontal][vertical].rightOpen = true;
                    moved = true;
                }
                break;
            case 3: // Right
                if (horizontal < MATRIX_DIMENSION - 1 && !cellMatrix[horizontal + 1][vertical].visited)
                {
                    cellMatrix[horizontal][vertical].rightOpen = true;
                    horizontal++;
                    cellMatrix[horizontal][vertical].leftOpen = true;
                    moved = true;
                }
                break;
            }

            if (moved)
            {
                cells.push(&cellMatrix[horizontal][vertical]);
                cellMatrix[horizontal][vertical].visited = true;
                std::cout << "Posicion: " << horizontal << ", " << vertical << std::endl;
                break;
            }
        }

        if (!moved)
        {
            cells.pop();
            if (!cells.empty())
            {
                auto topCell = cells.top();
                horizontal = topCell->rect.x/CELL_WIDTH; // Adjust if necessary
                vertical = topCell->rect.y/CELL_HEIGHT;
            }
            else
            {
                finished = true;
            }
        }
    }
}