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
    
}

void MainMenu::Render()
{
    SDL_Color backgroundColor = { 0, 0, 100, 255 };
    SDL_Rect background = { 0, 0, 1920, 1080 };
    app->DrawRectangle(background.x, background.y, background.w, background.h, backgroundColor);    
}