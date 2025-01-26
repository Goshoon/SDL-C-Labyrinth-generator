#include "sceneExample.h"

sceneExample::sceneExample()
{
	std::cout << "Created scenedd!\n";
	maze->Generate();
}

sceneExample::~sceneExample()
{
	delete maze;
}

void sceneExample::Update()
{
	
}

void sceneExample::Render()
{
	for (int i = 0; i < MATRIX_DIMENTION; ++i)
    {
        for (int j = 0; j < MATRIX_DIMENTION; ++j)
        {
        	SDL_Rect* cellArea = &maze->cellMatrix[i][j].rect;
        	SDL_Color color = { 0, 0, 0, 255 };

        	if (maze->cellMatrix[i][j].visited)
        		color = { 255, 255, 255, 255 };

            app->DrawRectangle(cellArea->x, cellArea->y, cellArea->w, cellArea->h, color);
        }
    }
}