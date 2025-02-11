#include "player.h"

Player::Player() // Contructor por defecto
{
	position.x = 0;
	position.y = 0;
	position.w = 24;
	position.h = 24;
	horizontalMove = false;
	verticalMove = false;
	horizontalSpeed = 0;
	verticalSpeed = 0;
	moveSpeed = 3;
	runSpeed = 1;
}

Player::Player(int x, int y) // Constructor a posicion
{
	position.x = x;
	position.y = y;
	position.w = 24;
	position.h = 24;
	horizontalMove = false;
	verticalMove = false;
	horizontalSpeed = 0;
	verticalSpeed = 0;
	moveSpeed = 3;
	runSpeed = 1;
}

void Player::Update(MazeGenerator& maze)
{
	clampsito();

	/* Actualizar celda actual del jugador */
	int x = position.x / CELL_WIDTH;
	int y = position.y / CELL_WIDTH;
	cell = &maze.cellMatrix[x][y];

	/* Dirección de jugador */
	horizontalMove = (app->mover_derecha ? 1 : 0) - (app->mover_izquierda ? 1 : 0);
	verticalMove = (app->mover_abajo ? 1 : 0) - (app->mover_arriba ? 1 : 0);

	/* Velocidad de movimiento */
	horizontalSpeed = (app->dash * runSpeed + moveSpeed) * horizontalMove;
	verticalSpeed = (app->dash * runSpeed + moveSpeed) * verticalMove;


	/* Crear área de colisión (hitbox) para revisar colisión en el eje horizontal */
	SDL_Rect horizontalCheck = position;
	horizontalCheck.x += horizontalSpeed;

	if (horizontalMove != 0)  // Revisar colision si hay movimiento
	{
		if ((horizontalMove < 0 && Collide(horizontalCheck, cell->left)) || 	// Revisar collision en paredes horizontales
		    (horizontalMove > 0 && Collide(horizontalCheck, cell->right)))
		{
			/*
			horizontalCheck.x -= horizontalSpeed;
			horizontalCheck.x += horizontalMove;
			while (!Collide(horizontalCheck, (horizontalMove < 0) ? cell->left : cell->right)) // Acercar a pared en (1 o -1) unidades
				position.x += horizontalMove;
			*/
			horizontalSpeed = 0;
		}
	}
	

	/* Crear área de colisión (hitbox) para revisar colisión en el eje vertical */
	SDL_Rect verticalCheck = position;
	verticalCheck.y += verticalSpeed;

	if (verticalMove != 0) // Revisar colision si hay movimiento
	{
		if ((verticalMove < 0 && Collide(verticalCheck, cell->top)) || 			// Revisar collision en paredes verticales
		    (verticalMove > 0 && Collide(verticalCheck, cell->bottom))) 
		{
			/*
			verticalCheck.y -= verticalSpeed;
			verticalCheck.y += verticalMove;
			while (!Collide(verticalCheck, (verticalMove < 0) ? cell->top : cell->bottom)) // Acercar a pared en (1 o -1) unidades
				position.y += verticalMove;
			*/
			verticalSpeed = 0;
		}
	}

	position.x += horizontalSpeed;
	position.y += verticalSpeed;
}

void Player::Render(Camera& camera)
{
	SDL_Color playerColor = { 0, 0, 0, 255 };
	SDL_Color playerShadow = { 0, 0, 0, 100 };
	app->DrawRectangle(camera, position.x+4, position.y+4, position.w, position.h, playerShadow);
	app->DrawRectangle(camera, position.x, position.y, position.w, position.h, playerColor);
}

void Player::clampsito(){

	int relative_position_x = CELL_WIDTH * MATRIX_DIMENSION - position.w * 2; 
	int relative_position_y = CELL_HEIGHT * MATRIX_DIMENSION - position.h * 2; 

	position.x = std::clamp((position.x), 0, relative_position_x);
	position.y = std::clamp((position.y), 0, relative_position_y);
}