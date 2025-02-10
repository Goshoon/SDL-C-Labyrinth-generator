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
    player->Update(*maze);
    contreras->localizatePlayer(*player, *maze);
    contreras->Chase(player.get());
    contreras->Update();

    if (app->mbLeft && !ImGui::IsWindowHovered(ImGuiHoveredFlags_AnyWindow))
    {
        float multiplier = 0.05f;
        float speed = 0.1f;

        previousMouseX = lerp(previousMouseX, app->mouseX, speed);
        previousMouseY = lerp(previousMouseY, app->mouseY, speed);
        camera->position.x -= (app->mouseX - previousMouseX) * multiplier;
        camera->position.y -= (app->mouseY - previousMouseY) * multiplier;
    }
    else if ( app->mover_abajo || app->mover_arriba || app->mover_derecha || app->mover_izquierda )
    {
        float multiplier = 0.05f;

        int size_width = 0;
        int size_heigth = 0;

        int x_target = 0;
        int y_target = 0;

        SDL_GetWindowSize(app->window, &size_width, &size_heigth);

        x_target = (player->position.x - (size_width / 2));
        y_target = (player->position.y - (size_heigth / 2));

        camera->position.x = lerp(camera->position.x, x_target, 0.02);
        camera->position.y = lerp(camera->position.y, y_target, 0.02);

        for(int i = 0; i > 5; i++ ) // Hihi
        {
            x_target = -(player->position.x - (size_width / 2));
            y_target = -(player->position.y - (size_heigth / 2));

            camera->position.x = lerp(camera->position.x, x_target, 0.02);
            camera->position.y = lerp(camera->position.y, y_target, 0.02);
        }
    }
    else
    {
        previousMouseX = app->mouseX;
        previousMouseY = app->mouseY;
    }

    camera->Update();

    if (generationWindow)
    {
        ImGui::Begin("meow", &generationWindow);
        ImGui::Text("hola");
        ImGui::End();
    }

    ImGui::BeginMainMenuBar();
    if (ImGui::BeginMenu("Files"))
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
    app->CalculateZoom(*camera);
    
	for (int i = 0; i < MATRIX_DIMENSION; ++i)
    {
        for (int j = 0; j < MATRIX_DIMENSION; ++j)
        {
        	Cell* cell = &maze->cellMatrix[i][j];
            cell->Render(*camera);
        }
    }

    player->Render(*camera);
    contreras->Render(*camera);
}