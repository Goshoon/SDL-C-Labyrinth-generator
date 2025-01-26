#pragma once
#include "define.h"
#include "SDL.h"

class Cell
{
public:
	Cell();
	Cell(int x, int y);
	~Cell();

	SDL_Rect rect;
	
	bool visited = false;
	bool upOpen = false;
	bool downOpen = false;
	bool leftOpen = false;
	bool rightOpen = false;
};