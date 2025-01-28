#include "sceneExample.h"

float lerp ( float a, float b, float t ) 
{ 
    return a + t *  ( b - a ) ; 
}

sceneExample::sceneExample()
{
	std::cout << "Created scene!\n";

    xoffset = 0;
    yoffset = 0;
}

sceneExample::~sceneExample()
{
	delete maze;
}

void sceneExample::Update()
{
    std::cout << app->space << " : " << xoffset << " : " << yoffset << "\n";
    if (app->space)
    {
        float multiplier = 0.05f;
        previousMouseX = lerp(previousMouseX, app->mouseX, multiplier);
        previousMouseY = lerp(previousMouseY, app->mouseY, multiplier);
        xoffset += (app->mouseX - previousMouseX) * multiplier;
        yoffset += (app->mouseY - previousMouseY) * multiplier;
    }
    else
    {
        previousMouseX = app->mouseX;
        previousMouseY = app->mouseY;
    }
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

            app->DrawRectangle(cellArea->x+xoffset, cellArea->y+yoffset, cellArea->w, cellArea->h, color);

            // Draw Walls
            if (!cell->upOpen) // Top wall
            {
                app->DrawRectangle(cellArea->x+xoffset, cellArea->y+yoffset, cellArea->w, outlineSize, outlineColor);
            }
            if (!cell->downOpen) // Bottom wall
            {
                app->DrawRectangle(cellArea->x+xoffset, cellArea->y + cellArea->h - outlineSize + yoffset, cellArea->w, outlineSize, outlineColor);
            }
            if (!cell->leftOpen) // Left wall
            {
                app->DrawRectangle(cellArea->x+xoffset, cellArea->y+yoffset, outlineSize, cellArea->h, outlineColor);
            }
            if (!cell->rightOpen) // Right wall
            {
                app->DrawRectangle(cellArea->x + cellArea->w - outlineSize+xoffset, cellArea->y+yoffset, outlineSize, cellArea->h, outlineColor);
            }
        }
    }
}