#include "mainMenu.h"

MainMenu::MainMenu()
{
	std::cout << "Created scene!\n";
}

MainMenu::~MainMenu()
{

}

void MainMenu::Update()
{
    /* Centrar la ventana "Main Menu" */
    ImGuiIO& io = ImGui::GetIO();
    ImGui::SetNextWindowSize(ImVec2(220, 200));
    ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x / 2 - 110, io.DisplaySize.y / 2 - 100));

    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(10, 10)); 
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(10, 10));
    
    /* Ventana principal del menu inicial */
    ImGui::Begin("Main Menu", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize);
    ImGui::Text("Maze Generator!");
    ImGui::Separator(); // Linea divisora
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.2f, 0.6f, 1.0f, 1.0f)); // Color del boton default
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.3f, 0.7f, 1.0f, 1.0f)); // Color al tener el cursor encima
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.1f, 0.5f, 0.9f, 1.0f));  // Color al precionar boton
    
    if (ImGui::Button("Generate a maze", ImVec2(200, 40)))
        currentScreen = std::make_unique<sceneExample>();

    if (ImGui::Button("Exit", ImVec2(200, 40)))
        Application::GetInstance().done = true;

    ImGui::PopStyleColor(3);
    ImGui::PopStyleVar(2);
    
    ImGui::End();
}


void MainMenu::Render()
{
    SDL_Color backgroundColor = { 0, 0, 100, 255 };
    SDL_Rect background = { 0, 0, 1920, 1080 };
    Application::GetInstance().DrawRectangle(background.x, background.y, background.w, background.h, backgroundColor);
}