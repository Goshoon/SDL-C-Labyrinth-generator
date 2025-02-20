#include "player.h"

Player::Player() // Contructor por defecto
	:Entity()
{
	spritesheet = app->GetTexture("Player");
	if (spritesheet == nullptr)
        std::cerr << "Failed to load player texture!" << std::endl;

	position.w = 64;
    position.h = 64;
    offset.x = position.w/2;
    offset.y = position.h/2;
	horizontalMove = false;
	verticalMove = false;
	horizontalSpeed = 0;
	verticalSpeed = 0;
	moveSpeed = 3;
	runSpeed = 1;

	SDL_QueryTexture(spritesheet, NULL, NULL, &maxframes, NULL);
	maxframes = maxframes / sprite.w;
}

Player::Player(int x, int y) // Constructor a posicion
	:Entity(x, y)
{
	spritesheet = app->GetTexture("Player");
	if (spritesheet == nullptr) {
        std::cerr << "Failed to load player texture!" << std::endl;
    }

    position.w = 64;
    position.h = 64;
    offset.x = position.w/2;
    offset.y = position.h/2;
	horizontalMove = false;
	verticalMove = false;
	horizontalSpeed = 0;
	verticalSpeed = 0;
	moveSpeed = 3;
	runSpeed = 1;

	SDL_QueryTexture(spritesheet, NULL, NULL, &maxframes, NULL);
	maxframes = maxframes / sprite.w;
}

void Player::Update(MazeGenerator& maze)
{
	LoockOnLevel();

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

	if (app->mover_derecha)
		angle = 0.0 + (45 * app->mover_arriba) - (45 * app->mover_abajo);
	if (app->mover_izquierda)
		angle = 180.0 + (45 * app->mover_arriba) - (45 * app->mover_abajo);
	if (app->mover_abajo)
		angle = 90 - (45 * app->mover_derecha) + (45 * app->mover_izquierda);
	if (app->mover_arriba)
		angle = 270 + (45 * app->mover_derecha) - (45 * app->mover_izquierda);

	if (verticalMove != 0 || horizontalMove != 0)
		Animate();

	position.x += horizontalSpeed;
	position.y += verticalSpeed;
}

void Player::Render(Camera& camera)
{
	app->RenderEntity(camera, *this);
}

void Player::LoockOnLevel(){

	int relative_position_x = CELL_WIDTH * MATRIX_DIMENSION - position.w * 0.5; 
	int relative_position_y = CELL_HEIGHT * MATRIX_DIMENSION - position.h * 0.5; 

	position.x = std::clamp((position.x), 0, relative_position_x);
	position.y = std::clamp((position.y), 0, relative_position_y);
}