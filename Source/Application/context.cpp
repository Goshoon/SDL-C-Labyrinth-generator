#include "context.h"

void Inititialize() // Iniciar SDL y sus modulos (SDL_Image, SDL_TTF, SDL_Mixer)
{
    Application& app = Application::GetInstance();
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG;

	// Inicializar Dear ImGui
	IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui::StyleColorsClassic(); // Tema

    // Setup Platform/Renderer backends
    ImGui_ImplSDL2_InitForSDLRenderer(app.window, app.renderer);
    ImGui_ImplSDLRenderer2_Init(app.renderer);

    LoadTextures();
}
void Quit() // Cerrar aplicacion
{
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    IMG_Quit();
	SDL_Quit();
}

void LoadTextures() // Cargar todas las imagenes con ("Identificador", "Ruta del archivo")
{
    Application::GetInstance().AddTexture("Player", "Resources/Images/rat.png");
}