#include "cell.h"
Cell::Cell() {}

Cell::Cell(int x, int y)
{
	visited = false;
	upOpen = false;
	downOpen = false;
	leftOpen = false;
	rightOpen = false;
	
	position.x = x;
	position.y = y;
	position.w = CELL_WIDTH;
	position.h = CELL_HEIGHT;

	top = std::make_shared<SDL_Rect>(SDL_Rect{ x, y, CELL_WIDTH, CELL_OUTLINE });
	bottom = std::make_shared<SDL_Rect>(SDL_Rect{ x, (y + CELL_HEIGHT) - CELL_OUTLINE, CELL_WIDTH, CELL_OUTLINE });
	left = std::make_shared<SDL_Rect>(SDL_Rect{ x, y, CELL_OUTLINE, CELL_HEIGHT });
	right = std::make_shared<SDL_Rect>(SDL_Rect{ (x + CELL_WIDTH) - CELL_OUTLINE, y, CELL_OUTLINE, CELL_HEIGHT });

	walls.push_back(top);
	walls.push_back(bottom);
	walls.push_back(left);
	walls.push_back(right);
}

Cell::~Cell() {}

void Cell::Render(Camera& camera)
{
	Application& app = Application::GetInstance();
	
	SDL_Color outlineColor = { 0, 0, 0, 255 };
	SDL_Color color = { 255, 255, 255, 255 };
	app.DrawRectangle(camera, position.x, position.y, position.w, position.h, color);
	app.DrawRectangle(camera, top->x, top->y, top->w, top->h, outlineColor);
	app.DrawRectangle(camera, bottom->x, bottom->y, bottom->w, bottom->h, outlineColor);
	app.DrawRectangle(camera, left->x, left->y, left->w, left->h, outlineColor);
	app.DrawRectangle(camera, right->x, right->y, right->w, right->h, outlineColor);
}