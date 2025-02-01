#include "contreras.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>

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

	Movement();
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
