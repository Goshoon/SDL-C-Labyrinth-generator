#pragma once
#include "application.h"
#include "define.h"
#include "camera.h"
#include "SDL.h"

#include <memory>

extern std::unique_ptr<Application> app;

class Contreras
{

public:
	Contreras();
	Contreras(int x, int y);
	SDL_Rect position;

	void Update();
    void Render(Camera* camera);

private:
	void Movement();
	void clampsito();
};