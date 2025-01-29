#include "sceneExample.h"

float lerp ( float a, float b, float t ) 
{ 
    return a + t *  ( b - a ) ; 
}

sceneExample::sceneExample()
{
	std::cout << "Created scene!\n";

    generationWindow = true;
    xoffset = 0;
    yoffset = 0;
    player = new Player(24, 24);
}

sceneExample::~sceneExample()
{
	delete maze;
    delete player;
}

void sceneExample::Update()
{
    if (app->mbLeft && !ImGui::IsWindowHovered(ImGuiHoveredFlags_AnyWindow))
    {
        float multiplier = 0.05f;
        float speed = 0.1f;
        previousMouseX = lerp(previousMouseX, app->mouseX, speed);
        previousMouseY = lerp(previousMouseY, app->mouseY, speed);
        xoffset += (app->mouseX - previousMouseX) * multiplier;
        yoffset += (app->mouseY - previousMouseY) * multiplier;
    }
    else
    {
        previousMouseX = app->mouseX;
        previousMouseY = app->mouseY;
    }

    if (generationWindow)
    {
        ImGui::Begin("meow", &generationWindow);
        ImGui::Text("hola");
        ImGui::End();
    }

    ImGui::BeginMainMenuBar();
    ImGui::Text("Prueba");
    ImGui::EndMainMenuBar();

    // std::cout<< "Player Inicialized"; 

    player->Update();

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
        	SDL_Color color = { 0, 0, 0, 255 }; // Color defecto (negro)
        	SDL_Color outlineColor = { 0, 0, 0, 255 };

            int cellX = cellArea->x + xoffset;
            int cellY = cellArea->y + yoffset;
            int cellW = cellArea->w;
            int cellH = cellArea->h;

        	if (maze->cellMatrix[i][j].visited) // Revisar si se itero por esta celda
        		color = { 255, 255, 255, 255 };

            // Dibujar celdas
            app->DrawRectangle(cellArea->x+xoffset, cellArea->y+yoffset, cellArea->w, cellArea->h, color);

            /* Dibujar paredes de celdas */
            if (!cell->upOpen) // Pared superior
                app->DrawRectangle(cellX, cellY, cellW, outlineSize, outlineColor);
            if (!cell->downOpen) // Pared inferior
                app->DrawRectangle(cellX, cellY + cellH - outlineSize, cellW, outlineSize, outlineColor);
            if (!cell->leftOpen) // Pared izquierda
                app->DrawRectangle(cellX, cellY, outlineSize, cellH, outlineColor);
            if (!cell->rightOpen) // Pared derecha
                app->DrawRectangle(cellX + cellW - outlineSize, cellY, outlineSize, cellH, outlineColor);
        }
    }

    player->Render();
}