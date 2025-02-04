#pragma once
#include "application.h"
#include "define.h"
#include "camera.h"
#include "SDL.h"

#include <memory>
#include <algorithm>
#include <iostream>

extern std::unique_ptr<Application> app;

class Player
{

public:
	Player();
	Player(int x, int y);
	SDL_Rect position;

	void Update();
	void Render(Camera& camera);
private:
	void Input();
	void clampsito();
	
};