#pragma once
#include "SDL.h"

class Player
{
public:
	Player(int x, int y);
	SDL_Rect position;

	void Update();
	void Render();
};