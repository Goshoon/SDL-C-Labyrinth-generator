#include "mazeGenerator.h"

MazeGenerator::MazeGenerator()
{
	Generate();
}

MazeGenerator::~MazeGenerator()
{
    
}

void MazeGenerator::Generate()
{
    GenerateCells();
    GenerateMaze();
}

void MazeGenerator::GenerateCells()
{
	for (int i = 0; i < MATRIX_DIMENSION; ++i)
        for (int j = 0; j < MATRIX_DIMENSION; ++j)
            cellMatrix[i][j] = Cell(i * CELL_WIDTH, j * CELL_HEIGHT);
}

void MazeGenerator::GenerateMaze()
{
    std::mt19937 gen(static_cast<unsigned int>(std::time(nullptr)));
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
                    cellMatrix[horizontal][vertical].top = { 0, 0, 0, 0 };
                    vertical--;
                    cellMatrix[horizontal][vertical].downOpen = true;
                    cellMatrix[horizontal][vertical].bottom = { 0, 0, 0, 0 };
                    moved = true;
                }
                break;
            case 1: // Down
                if (vertical < MATRIX_DIMENSION - 1 && !cellMatrix[horizontal][vertical + 1].visited)
                {
                    cellMatrix[horizontal][vertical].downOpen = true;
                    cellMatrix[horizontal][vertical].bottom = { 0, 0, 0, 0 };
                    vertical++;
                    cellMatrix[horizontal][vertical].upOpen = true;
                    cellMatrix[horizontal][vertical].top = { 0, 0, 0, 0 };
                    moved = true;
                }
                break;
            case 2: // Left
                if (horizontal > 0 && !cellMatrix[horizontal - 1][vertical].visited)
                {
                    cellMatrix[horizontal][vertical].leftOpen = true;
                    cellMatrix[horizontal][vertical].left = { 0, 0, 0, 0 };
                    horizontal--;
                    cellMatrix[horizontal][vertical].rightOpen = true;
                    cellMatrix[horizontal][vertical].right = { 0, 0, 0, 0 };
                    moved = true;
                }
                break;
            case 3: // Right
                if (horizontal < MATRIX_DIMENSION - 1 && !cellMatrix[horizontal + 1][vertical].visited)
                {
                    cellMatrix[horizontal][vertical].rightOpen = true;
                    cellMatrix[horizontal][vertical].right = { 0, 0, 0, 0 };
                    horizontal++;
                    cellMatrix[horizontal][vertical].leftOpen = true;
                    cellMatrix[horizontal][vertical].left = { 0, 0, 0, 0 };
                    moved = true;
                }
                break;
            }

            if (moved)
            {
                cells.push(&cellMatrix[horizontal][vertical]); // First push to stack
                cellMatrix[horizontal][vertical].visited = true; // Then mark as visited
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
                horizontal = topCell->position.x / CELL_WIDTH;
                vertical = topCell->position.y / CELL_HEIGHT;
            }
            else
            {
                finished = true;
                break; // Exit loop immediately
            }
        }
    }
}