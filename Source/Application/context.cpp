#include "context.h"

void Inititialize() // Iniciar SDL y SDL_Image
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG;
    TTF_Init();

    font = TTF_OpenFont("./Resources/font.ttf", 24); /* Cargar fuente */

	// Inicializar Dear ImGui
	IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui::StyleColorsClassic(); // Tema

    // Setup Platform/Renderer backends
    ImGui_ImplSDL2_InitForSDLRenderer(app->window, app->renderer);
    ImGui_ImplSDLRenderer2_Init(app->renderer);

    LoadTextures();
}
void Quit() // Cerrar aplicacion
{
    TTF_CloseFont(font);

    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    TTF_Quit();
    IMG_Quit();
	SDL_Quit();
}

void LoadTextures() // Cargar todas las imagenes con ("Identificador", "Ruta del archivo")
{
    app->AddTexture("Player", "Resources/Images/rat.png");
}