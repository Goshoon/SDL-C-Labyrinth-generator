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
#include <contreras.h>

extern std::unique_ptr<Application> app;

class ContrerasPrime : public Contreras
{

public:
	ContrerasPrime();
	ContrerasPrime(int x, int y);
	SDL_Rect position;

	void Update();
    void Render(Camera& camera);
	void Chase(Player* player);
	void ChaseColision(MazeGenerator* maze);
	void localizatePlayer(Player& player, MazeGenerator& maze);
	bool ChaseCheck(float x, float y, float x_c, float y_c);
	void LoockOnLevel();
	int Cuadrante;
	std::vector<int> Perseguir = {};

private:
	void Movement();
	void clampsito();
};