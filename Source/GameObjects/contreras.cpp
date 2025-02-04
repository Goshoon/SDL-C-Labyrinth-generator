#include "contreras.h"

Contreras::Contreras() // Contructor por defecto
{
	position.x = 0;
	position.y = 0;
	position.w = 12;
	position.h = 12;
}

Contreras::Contreras(int x, int y) // Constructor a posicion
{
	position.x = x;
	position.y = y;
	position.w = 12;
	position.h = 12;
}

void Contreras::Update()
{

	// Movement();
	clampsito();

}

void Contreras::clampsito(){

	int relative_position_x = CELL_WIDTH * MATRIX_DIMENSION - position.w * 2; 
	int relative_position_y = CELL_WIDTH * MATRIX_DIMENSION - position.h * 2; 

	position.x = std::clamp((position.x), 0, relative_position_x);
	position.y = std::clamp((position.y), 0, relative_position_y);
	// std::cout<<position.x<< " : " <<position.y << "\n";

}

void Contreras::Render(Camera* camera) // Posicion en pantalla = posicion + posicion_camara
{
	SDL_Color outlineColor = { 255, 0, 0, 255 }; 
	app->DrawRectangle(position.x + camera->position.x, position.y + camera->position.y, 24, 24, outlineColor);
}

void Contreras::Movement()
{

    srand(time(0)); // Inicializar la semilla aleatoria

    int probabilidad = (rand() % 21) - 10; 
	float desplazamiento = 2.0f;

	// std::cout<<"Probabilidad", probabilidad;

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

	std::cout << "player_coordinates: " << player->position.x << ", " << player->position.y << "\n";
	std::cout << "contreras_coordinates: " << position.x << ", " << position.y << "\n";

	if(ChaseCheck(position.x, position.y, player->position.x, player->position.y ))
	{
		std::cout << "you got it";
		return;
	}

	// float desplazamiento = 2.0f;

	// std::cout << "probabilidad: " << probabilidad << "\n";

	float diference_x = 0.00f;
	float diference_y = 0.00f;
	diference_x = player->position.x - position.x;
	diference_y = player->position.y - position.y;

	// std::cout << "diferencias: " << diference_x << ", " << diference_y << "\n";

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