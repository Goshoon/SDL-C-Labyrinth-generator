#pragma once
#include "SDL.h"
#include "application.h"
#include "camera.h"
#include <memory>

extern std::unique_ptr<Application> app;

class Button
{
public:
	Button(int x, int y, int w, int h);	
    Button();
	SDL_Rect position;

	void Render(Camera& camera);
};