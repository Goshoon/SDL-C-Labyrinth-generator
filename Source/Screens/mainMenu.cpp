#include "mainMenu.h"

MainMenu::MainMenu()
{
	std::cout << "Created scene!\n";
}

MainMenu::~MainMenu()
{

}

void MainMenu::Update()
{
    ImGui::Begin("Guillermo", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);
    ImGui::Text("Maze Generator!");
    ImGui::End();
}

void MainMenu::Render()
{
    SDL_Color backgroundColor = { 0, 0, 100, 255 };
    SDL_Rect background = { 0, 0, 1920, 1080 };
    app->DrawRectangle(background.x, background.y, background.w, background.h, backgroundColor);
}