#pragma once
#include "application.h"
#include "define.h"
#include "SDL.h"

#include <memory>
extern std::unique_ptr<Application> app;

class Player
{
public:
	Player();
	Player(int x, int y);
	SDL_Rect position;

	void Update();
	void Render();
};