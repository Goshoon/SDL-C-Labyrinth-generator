#include "player.h"

Player::Player() // Contructor por defecto
{
	position.x = 0;
	position.y = 0;
	position.w = 24;
	position.h = 24;
}

Player::Player(int x, int y) // Constructor a posicion
{
	position.x = x;
	position.y = y;
	position.w = 24;
	position.h = 24;
}

void Player::Update(MazeGenerator& maze)
{
	clampsito();
	int x = position.x / CELL_WIDTH;
	int y = position.y / CELL_WIDTH;

	cell = &maze.cellMatrix[x][y];

	float desplazamiento = 2.0f;
	
	if(app->dash)
	{
		desplazamiento = 3.0f;
	}

	if(app->mover_arriba && Collide(position, cell->top) == false)
	{
		position.y = position.y - desplazamiento;
	}

	if(app->mover_abajo && Collide(position, cell->bottom) == false)
	{
		position.y = position.y + desplazamiento;
	}

	if(app->mover_izquierda && Collide(position, cell->left) == false)
	{
		position.x = position.x - desplazamiento;
	}

	if(app->mover_derecha && Collide(position, cell->right) == false)
	{
		position.x = position.x + desplazamiento;
	}
}

void Player::Render(Camera& camera)
{
	SDL_Color playerColor = { 0, 0, 0, 255 };
	SDL_Color playerShadow = { 0, 0, 0, 100 };
	//SDL_Color cellColor = { 0, 0, 185, 25 };
	//app->DrawRectangle(camera, cell->position.x, cell->position.y, cell->position.w, cell->position.h, cellColor);
	app->DrawRectangle(camera, position.x+4, position.y+4, position.w, position.h, playerShadow);
	app->DrawRectangle(camera, position.x, position.y, position.w, position.h, playerColor);
}

void Player::clampsito(){

	int relative_position_x = CELL_WIDTH * MATRIX_DIMENSION - position.w * 2; 
	int relative_position_y = CELL_HEIGHT * MATRIX_DIMENSION - position.h * 2; 

	position.x = std::clamp((position.x), 0, relative_position_x);
	position.y = std::clamp((position.y), 0, relative_position_y);
}