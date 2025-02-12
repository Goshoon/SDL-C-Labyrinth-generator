#pragma once
#include "application.h"
#include "define.h"
#include "camera.h"
#include "cell.h"
#include "MazeGenerator.h"
#include "collision.h"
#include "entity.h"

#include "SDL.h"

#include <memory>
#include <algorithm>
#include <iostream>

extern std::unique_ptr<Application> app;

class Player : public Entity
{

public:
	Player();
	Player(int x, int y);
	SDL_Rect position, sprite;
	Cell* cell;

	void Update(MazeGenerator& maze);
	void Render(Camera& camera);
private:
	void clampsito();
	short horizontalMove, verticalMove;
	short horizontalSpeed, verticalSpeed, moveSpeed, runSpeed;
};