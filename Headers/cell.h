#pragma once
#include "define.h"
#include "camera.h"
#include "application.h"

#include "SDL.h"

#include <memory>

extern std::unique_ptr<Application> app;

class Cell
{
public:
	Cell();
	Cell(int x, int y);
	~Cell();

	SDL_Rect position, top, bottom, left, right;
	
	bool visited = false;
	
	bool upOpen = false;
	bool downOpen = false;
	bool leftOpen = false;
	bool rightOpen = false;

	void Render(Camera& camera);
};