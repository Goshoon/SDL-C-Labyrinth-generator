#include "player.h"

Player::Player() // Contructor por defecto
{
	position.x = 0;
	position.y = 0;
	position.w = 12;
	position.h = 12;
}

Player::Player(int x, int y) // Constructor a posicion
{
	position.x = x;
	position.y = y;
	position.w = 12;
	position.h = 12;
}

void Player::Update(MazeGenerator& maze)
{
	Input();
	clampsito();
	int x = position.x / CELL_WIDTH;
	int y = position.y / CELL_WIDTH;

	std::cout << position.x << " : " << x << "\n";
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

/*
	desplazamiento = 1.0f;
	if(app->mover_abajo && app->mover_izquierda)
	{
		position.x = position.x - (desplazamiento * 0.02);
		position.y = position.y + (desplazamiento * 0.02);
	}

	if(app->mover_abajo && app->mover_derecha)
	{
		position.x = position.x + (desplazamiento * 0.02);
		position.y = position.y + (desplazamiento * 0.02);
	}

	if(app->mover_arriba && app->mover_derecha)
	{
		position.x = position.x + (desplazamiento * 0.02);
		position.y = position.y - (desplazamiento * 0.02);
	}

	if(app->mover_arriba && app->mover_izquierda)
	{
		position.x = position.x - (desplazamiento * 0.02);
		position.y = position.y - (desplazamiento * 0.02);
	}

*/
}

void Player::Render(Camera& camera)
{
	SDL_Color outlineColor = { 0, 0, 0, 255 };
	SDL_Color blue = { 0, 0, 255, 255 };
	app->DrawRectangle(camera, cell->position.x, cell->position.y, cell->position.w, cell->position.h, blue);
	app->DrawRectangle(camera, position.x, position.y, 24, 24, outlineColor);
}

void Player::Input()
{
	
}

void Player::clampsito(){

	int relative_position_x = CELL_WIDTH * MATRIX_DIMENSION - position.w * 2; 
	int relative_position_y = CELL_HEIGHT * MATRIX_DIMENSION - position.h * 2; 

	position.x = std::clamp((position.x), 0, relative_position_x);
	position.y = std::clamp((position.y), 0, relative_position_y);
}