#include "sceneExample.h"

sceneExample::sceneExample()
{
	std::cout << "Created scene!\n";
    generationWindow = true;
}

sceneExample::~sceneExample()
{



}

void sceneExample::Update()
{

    if (app->mbLeft && !ImGui::IsWindowHovered(ImGuiHoveredFlags_AnyWindow))
    {
        float multiplier = 0.05f;
        float speed = 0.1f;
        previousMouseX = lerp(previousMouseX, app->mouseX, speed);
        previousMouseY = lerp(previousMouseY, app->mouseY, speed);
        camera->position.x += (app->mouseX - previousMouseX) * multiplier;
        camera->position.y += (app->mouseY - previousMouseY) * multiplier;
    }
    else if(app->mover_abajo || app->mover_arriba || app->mover_derecha || app->mover_izquierda)
    {

        float multiplier = 0.05f;

        int size_width = 0;
        int size_heigth = 0;

        int x_target = 0;
        int y_target = 0;

        SDL_GetWindowSize(app->window, &size_width, &size_heigth);

        x_target = -(player->position.x - (size_width / 2));
        y_target = -(player->position.y - (size_heigth / 2));

        camera->position.x = lerp(camera->position.x, x_target, 0.02);
        camera->position.y = lerp(camera->position.y, y_target, 0.02);

    }
    else
    {

        previousMouseX = app->mouseX;
        previousMouseY = app->mouseY;

    }

    player->Update();
    contreras->Update();

    camera->campsito();

    if (generationWindow)
    {
        ImGui::Begin("meow", &generationWindow);
        ImGui::Text("hola");
        ImGui::End();
    }

    ImGui::BeginMainMenuBar();
    if (ImGui::BeginMenu("HOLA PUTOS PENDEJOS BABOSOS IDIOTAS"))
    {
        if (ImGui::MenuItem("New"))
            generationWindow = true;

        ImGui::Separator();

        if (ImGui::MenuItem("Exit"))
            app->done = true;

        ImGui::EndMenu();
    }
    ImGui::EndMainMenuBar();
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

            /* Posicion de dibujado */
            int cellX = cellArea->x + camera->position.x;
            int cellY = cellArea->y + camera->position.y;
            int cellW = cellArea->w;
            int cellH = cellArea->h;

        	if (maze->cellMatrix[i][j].visited) // Revisar si se itero por esta celda
        		color = { 255, 255, 255, 255 };

            // Dibujar celdas
            app->DrawRectangle(cellArea->x+camera->position.x, cellArea->y+camera->position.y, cellArea->w, cellArea->h, color);

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

    player->Render(camera.get());

    contreras->Render(camera.get());

}