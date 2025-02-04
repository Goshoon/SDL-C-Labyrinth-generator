#pragma once
#include "application.h"
#include "define.h"
#include "camera.h"
#include "SDL.h"
#include "player.h"

#include <memory>
#include <cmath>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <algorithm>

extern std::unique_ptr<Application> app;

class Contreras
{

public:
	Contreras();
	Contreras(int x, int y);
	SDL_Rect position;

	void Update();
    void Render(Camera& camera);
	void Chase(Player* player);
	bool ChaseCheck(float x, float y, float x_c, float y_c);
	int Cuadrante;

private:
	void Movement();
	void clampsito();
};