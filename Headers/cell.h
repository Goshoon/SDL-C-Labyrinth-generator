#pragma once
#include "define.h"
#include "wall.h"
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
	/*
	Wall top;
	Wall bottom;
	Wall left;
	Wall Right;
	*/
};