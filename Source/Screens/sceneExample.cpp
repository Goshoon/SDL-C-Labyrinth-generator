#include "sceneExample.h"

sceneExample::sceneExample()
{
	std::cout << "Created scene!\n";
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
	for (int i = 0; i < MATRIX_DIMENSION; ++i)
    {
        for (int j = 0; j < MATRIX_DIMENSION; ++j)
        {
        	short outlineSize = 2;
        	Cell* cell = &maze->cellMatrix[i][j];
        	SDL_Rect* cellArea = &cell->rect;
        	SDL_Color color = { 0, 0, 0, 255 };
        	SDL_Color outlineColor = { 0, 0, 0, 255 };

        	if (maze->cellMatrix[i][j].visited)
        		color = { 255, 255, 255, 255 };

            app->DrawRectangle(cellArea->x, cellArea->y, cellArea->w, cellArea->h, color);

            // Draw Walls
            if (!cell->upOpen) // Top wall
            {
                app->DrawRectangle(cellArea->x, cellArea->y, cellArea->w, outlineSize, outlineColor);
            }
            if (!cell->downOpen) // Bottom wall
            {
                app->DrawRectangle(cellArea->x, cellArea->y + cellArea->h - outlineSize, cellArea->w, outlineSize, outlineColor);
            }
            if (!cell->leftOpen) // Left wall
            {
                app->DrawRectangle(cellArea->x, cellArea->y, outlineSize, cellArea->h, outlineColor);
            }
            if (!cell->rightOpen) // Right wall
            {
                app->DrawRectangle(cellArea->x + cellArea->w - outlineSize, cellArea->y, outlineSize, cellArea->h, outlineColor);
            }
        }
    }
}