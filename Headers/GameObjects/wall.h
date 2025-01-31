#pragma once
#include "SDL.h"

class Wall
{
public:
	Wall(int x, int y, int w, int h);	
	~Wall();

	SDL_Rect position;

	void Render();
};