#pragma once
#include "define.h"
#include "camera.h"
#include "application.h"

#include <SDL2/SDL.h>

#include <memory>
#include <vector>

class Cell
{
public:
	Cell();
	Cell(int x, int y);
	~Cell();

	SDL_Rect position;
	std::shared_ptr<SDL_Rect> top, bottom, left, right;
	std::vector<std::shared_ptr<SDL_Rect>> walls;
	//std::vector<SDL_Rect*> walls;
	
	bool visited = false;
	bool upOpen = false;
	bool downOpen = false;
	bool leftOpen = false;
	bool rightOpen = false;

	void Render(Camera& camera);
};