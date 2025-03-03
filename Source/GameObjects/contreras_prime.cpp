#include "contreras_prime.h"

ContrerasPrime::ContrerasPrime()
{
    position.x = 0;
	position.y = 0;
	position.w = 24;
	position.h = 24;
}

ContrerasPrime::ContrerasPrime(int x, int y) // Constructor a posicion
{
	position.x = x;
	position.y = y;
	position.w = 24;
	position.h = 24;
}

void ContrerasPrime::Update()
{

	// Movement();
	clampsito();

}

void ContrerasPrime::LoockOnLevel(){

	int relative_position_x = CELL_WIDTH * MATRIX_DIMENSION - position.w * 0.5; 
	int relative_position_y = CELL_HEIGHT * MATRIX_DIMENSION - position.h * 0.5; 

	position.x = std::clamp((position.x), 0, relative_position_x);
	position.y = std::clamp((position.y), 0, relative_position_y);
}