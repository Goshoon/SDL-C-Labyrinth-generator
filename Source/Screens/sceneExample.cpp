#include "sceneExample.h"

sceneExample::sceneExample()
{
	std::cout << "Created scenedd!\n";
	ventanaEjemplo = true;
	app->AddTexture("gorp", "Resources/Images/gorp.png");
	gorp = app->GetTexture("gorp");
}

sceneExample::~sceneExample()
{
	SDL_DestroyTexture(gorp);
}

void sceneExample::Update()
{
	if (ventanaEjemplo)
	{
		ImGui::Begin("Ventana de ejemplo :3", &ventanaEjemplo);
		ImGui::Text(":3333");

		ImVec2 imageSize(200.0f, 200.0f); // Adjust as needed
		ImGui::Image(reinterpret_cast<ImTextureID>(gorp), imageSize);

		if (ImGui::IsItemHovered() && ImGui::IsMouseReleased(1)) // Right-click
    	{
        	ImGui::OpenPopup("Click");
    	}

		if(ImGui::BeginPopup("Click")) 
		{
  			ImGui::Text("Contenido");
  			ImGui::EndPopup();
		}
		ImGui::Text("right-click me");
		ImGui::End();
	}
}

void sceneExample::Render()
{
	app->RenderImage(gorp, 0, 0, 256, 256);
}