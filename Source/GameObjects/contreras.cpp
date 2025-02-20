#include "contreras.h"

Contreras::Contreras() // Contructor por defecto
{
	position.x = 0;
	position.y = 0;
	position.w = 24;
	position.h = 24;
}

Contreras::Contreras(int x, int y) // Constructor a posicion
{
	position.x = x;
	position.y = y;
	position.w = 24;
	position.h = 24;
}

void Contreras::Update()
{

	// Movement();
	clampsito();

}

void Contreras::clampsito(){

	int relative_position_x = CELL_WIDTH * MATRIX_DIMENSION - position.w * 2; 
	int relative_position_y = CELL_WIDTH * MATRIX_DIMENSION - position.h * 2; 

	position.x = std::clamp(position.x, position.w, relative_position_x + position.w);
	position.y = std::clamp(position.y, position.h, relative_position_y - position.h);
}

void Contreras::Render(Camera& camera) // Posicion en pantalla = posicion + posicion_camara
{
	SDL_Color entityColor = { 255, 0, 0, 255 }; 
	SDL_Color entityShadow = { 255, 0, 0, 100 };
	app->DrawRectangle(camera, position.x+4, position.y+4, position.w, position.h, entityShadow);
	app->DrawRectangle(camera, position.x, position.y, position.w, position.h, entityColor);
}

void Contreras::Movement()
{
    srand(time(0)); // Inicializar la semilla aleatoria

    int probabilidad = (rand() % 21) - 10; 
	float desplazamiento = 2.0f;

	if(probabilidad > 0)
	{
		if(probabilidad > 5)
		{
			position.x = position.x + desplazamiento;
		}
		else
		{
			position.y = position.y - desplazamiento;
		}
	}
	else
	{
		if(probabilidad < -5)
		{
			position.x = position.x - desplazamiento;
		}
		else
		{
			position.y = position.y + desplazamiento;
		}
	}
	

}

void Contreras::Chase(Player* player)
{
	float diference_x = 0.50f;
	float diference_y = 0.50f;
	diference_x = player->position.x - position.x;
	diference_y = player->position.y - position.y;
	
	if(diference_x < 1)
	{
		diference_x = -(diference_x); 
	}

	if(diference_y < 1)
	{
		diference_y = -(diference_y);
	}

	float desplazamiento = 2.0f;
	if(diference_x > diference_y)
	{

		if(player->position.x > position.x)
		{
			position.x += desplazamiento;
		}

		if(player->position.x < position.x)
		{
			position.x -= desplazamiento;
		}
	}
	else
	{

		if(player->position.y > position.y)
		{
			position.y += desplazamiento;
		}
		
		if(player->position.y < position.y)
		{
			position.y -= desplazamiento;
		}

	}

}

bool Contreras::ChaseCheck(float x, float y, float x_c, float y_c)
{
	return std::abs(x - x_c) <= 20 && std::abs(y - y_c) <= 20;
}

void Contreras::localizatePlayer(Player& player, MazeGenerator& maze)
{
	//&maze.cellMatrix[player.position.x][player.position.y];
	//std::cout << "&maze.cellMatrix[player.position.x][player.position.y]" << " : " << &maze.cellMatrix[player.position.x][player.position.y] << std::endl;
}