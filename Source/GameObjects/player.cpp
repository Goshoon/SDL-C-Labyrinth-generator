#include "player.h"
#include <algorithm>
#include <iostream>

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

void Player::Update()
{
	Input();

	clampsito();

}

void Player::Render(Camera *camera)
{
	SDL_Color outlineColor = { 0, 0, 0, 255 }; 
	app->DrawRectangle(position.x + camera->position.x, position.y + camera->position.y, 24, 24, outlineColor);
}

void Player::Input()
{
	float desplazamiento = 2.0f;
// && timerDash == 0
	if(app->dash)
	{
		desplazamiento = 3.0f;
	}

	if(app->mover_arriba)
	{
		position.y = position.y - desplazamiento;
	}

	if(app->mover_abajo)
	{
		position.y = position.y + desplazamiento;
	}

	if(app->mover_izquierda)
	{
		position.x = position.x - desplazamiento;
	}

	if(app->mover_derecha)
	{
		position.x = position.x + desplazamiento;
	}

	if(app->mover_abajo && app->mover_izquierda)
	{
		position.x = position.x - (desplazamiento * 0.30f);
		position.y = position.y + (desplazamiento * 0.30f);
	}

	if(app->mover_abajo && app->mover_derecha)
	{
		position.x = position.x + (desplazamiento * 0.30f);
		position.y = position.y + (desplazamiento * 0.30f);
	}

	if(app->mover_arriba && app->mover_derecha)
	{
		position.x = position.x + (desplazamiento * 0.30f);
		position.y = position.y - (desplazamiento * 0.30f);
	}

	if(app->mover_arriba && app->mover_izquierda)
	{
		position.x = position.x - (desplazamiento * 0.30f);
		position.y = position.y - (desplazamiento * 0.30f);
	}


}

void Player::clampsito(){

	int relative_position_x = CELL_WIDTH * MATRIX_DIMENSION - position.w * 2; 
	int relative_position_y = CELL_WIDTH * MATRIX_DIMENSION - position.h * 2; 

	position.x = std::clamp((position.x), 0, relative_position_x);
	position.y = std::clamp((position.y), 0, relative_position_y);
	std::cout<<position.x<< " : " <<position.y << "\n";

}