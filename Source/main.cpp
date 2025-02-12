#include "main.h"
using std::cout, std::cin, std::shared_ptr, std::unique_ptr, std::make_unique;

TTF_Font* font;
unique_ptr<Application> app = make_unique<Application>(); /* Crear una instancia de la aplicacion (ventana + render) y que sea global*/
unique_ptr<Screen> currentScreen = make_unique<MainMenu>(); /* Crear escena inicial */
int fps = 144;
int desiredDelta = 1000 / fps;

int main(int argc, char* argv[])
{
	// Inicializar SDL2 & ImGui
	Inititialize();

	while(!app->done) /* Ciclo loop */
	{
		int startLoop = SDL_GetTicks(); /* Guardar los ticks al principio del loop */
		app->Input(); /* Detectar teclas e interacciones con la ventana */

		ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        currentScreen->Update(); /* Metodo de crear botones e interacciones de la escena actual */
		app->Display(); /* Mostrar interfaces y Actualizar pantalla */
		currentScreen->Render(); /* Metodo de mostrar elementos como imagenes u efectos */
		app->DrawEverything(); /* Actualizar la pantalla y dibujar el frame actual */

		int delta = SDL_GetTicks() - startLoop;
		if (delta < desiredDelta)
		{
			SDL_Delay(desiredDelta - delta);
		}
	}

	// Cerrar dependencias y limpiar memoria
	Quit();
	
	return 0;
}