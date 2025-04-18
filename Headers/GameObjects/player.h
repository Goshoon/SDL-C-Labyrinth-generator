#pragma once
#include "application.h"
#include "define.h"
#include "camera.h"
#include "cell.h"
#include "mazeGenerator.h"
#include "collision.h"
#include "entity.h"
#include "math.h"

#include <SDL2/SDL.h>

#include <memory>
#include <algorithm>
#include <iostream>

class Player : public Entity
{

public:
	Player();
	Player(int x, int y);
	
	void Update(MazeGenerator& maze);
	void Render(Camera& camera);
private:
	Cell* cell;
	void SetAngle();
	void LoockOnLevel();
	int horizontalMove, verticalMove;
	int horizontalSpeed, verticalSpeed, moveSpeed, runSpeed;
};
