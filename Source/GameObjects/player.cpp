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

void Player::Update()
{
	// Movimiento
}

void Player::Render()
{
	// Mostrar jugador
}