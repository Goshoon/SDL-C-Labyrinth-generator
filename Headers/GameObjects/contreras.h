#pragma once
#include "application.h"
#include "define.h"
#include "camera.h"
#include "SDL.h"
#include "player.h"
#include "cell.h"
#include "mazeGenerator.h"
#include "collision.h"

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
	void localizate(Camera&, MazeGenerator& maze);
	bool ChaseCheck(float x, float y, float x_c, float y_c);

	void ChaseColide(Player& player, MazeGenerator& maze);

	float cuadrante = 0.00f;
	char eje_cuadrante;
	Cell* cell;
	std::vector<int> Perseguir = {};

private:
	void Movement();
	void clampsito();
};