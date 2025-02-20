#include "application.h"

Application::Application()
{
	window = SDL_CreateWindow(
		"Application", 
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
	);

	renderer = SDL_CreateRenderer(
		window, -1, SDL_RENDERER_SOFTWARE  /* Cambiar SDL_RENDERER_ACCELERATED -> SDL_RENDERER_ACCELERATED  Para usar GPU */
	);
	
	SDL_SetWindowMinimumSize(window, 800, 640);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_RenderSetScale(renderer, RENDER_SCALE, RENDER_SCALE);

	done = false;
	mbLeft = false;
	mbRight = false;
	space = false;
	mover_arriba = false;
	mover_abajo = false;
	mover_derecha = false;
	mover_izquierda = false;
	dash = false;
	zoom = 1.0f;
}

Application::~Application()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	for (auto& pair : images)
	{
		SDL_DestroyTexture(pair.second);
	}
}

void Application::AddTexture(const std::string& ID, const char* fileDir)
{
	SDL_Texture* texture = IMG_LoadTexture(renderer, fileDir);
	images[ID] = texture;
	if (texture != nullptr)
		std::cout << "image loaded!" << "\n";
}

SDL_Texture* Application::GetTexture(const std::string& ID)
{
	auto it = images.find(ID);
	std::cout << images.size();
	return it != images.end() ? it->second : nullptr;
}

void Application::Display()
{
	SDL_RenderClear( renderer );
}

void Application::DrawEverything()
{
	ImGui::Render();
	SDL_RenderSetScale(renderer, RENDER_SCALE, RENDER_SCALE); // Ajustar la escala del renderer
	ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), renderer);
	SDL_SetRenderDrawColor( renderer, 209, 204, 220, 255 );
	SDL_RenderPresent(renderer);
}

void Application::Input() /* Teclas e interacciones con la ventana */
{
	SDL_Event event;
	while ( SDL_PollEvent(&event))
	{
		ImGui_ImplSDL2_ProcessEvent(&event);
		switch (event.type)
		{
			case SDL_QUIT:
				done = true;
			break;
			case SDL_KEYDOWN:
				InputPressed(&event);
			break;
			case SDL_KEYUP:
				InputReleased(&event);
			break;
			case SDL_MOUSEBUTTONDOWN:
				switch(event.button.button)
				{
				case SDL_BUTTON_LEFT:
					mbLeft = true;
				break;
				case SDL_BUTTON_RIGHT:
					mbRight = true;
				break;
				}

			break;
			case SDL_MOUSEMOTION:
				SDL_GetMouseState(&mouseX, &mouseY);
			break;
			case SDL_MOUSEBUTTONUP:
				mbLeft = false;
				mbRight = false;
			break;
			case SDL_MOUSEWHEEL:

				if (event.wheel.y > 0)
				{
        			zoom =  lerp(zoom, zoom * 1.2f, 0.05f);
				}
				else if (event.wheel.y < 0)
				{
        			zoom =  lerp(zoom, zoom * 0.8f, 0.05f);
				}
				
			break;
        }
    }
}

void Application::InputReleased(SDL_Event* event)
{
	switch (event->key.keysym.sym)
	{
		case SDLK_ESCAPE:
			done = true;
		break;
		case SDLK_SPACE:
			space = false;
			dash = false;
		break;
		case SDLK_LSHIFT:
			dash = false;
		break;
		case SDLK_w:
			mover_arriba = false;
		break;
		case SDLK_s:
			mover_abajo = false;
		break;
		case SDLK_a:
			mover_izquierda = false;
		break;
		case SDLK_d:
			mover_derecha = false;
		break;
	}
}

void Application::InputPressed(SDL_Event* event)
{
	switch (event->key.keysym.sym)
	{
		case SDLK_SPACE:
			space = true;
			dash = true;
		break;
		case SDLK_LSHIFT:
			dash = true;
		break;
		case SDLK_w:
			mover_arriba = true;
		break;
		case SDLK_s:
			mover_abajo = true;
		break;
		case SDLK_a:
			mover_izquierda = true;
		break;
		case SDLK_d:
			mover_derecha = true;
		break;
	}
}

void Application::DrawRectangle(int x, int y, int width, int height, SDL_Color color)
{
    // Establecer el color
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    // Crear area donde se va a dibujar
    SDL_Rect squareRect = { x, y, width, height }; // { x, y, ancho, alto }

    // Dibujar el rectangulo en el area
    SDL_RenderFillRect(renderer, &squareRect);
}

void Application::DrawRectangle(Camera& camera, int x, int y, int width, int height, SDL_Color color)
{
    // Establecer el color
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    // Crear area donde se va a dibujar
    SDL_Rect squareRect = { x - camera.position.x, y - camera.position.y, width, height }; // { x, y, ancho, alto }

    // Dibujar el rectangulo en el area
    SDL_RenderFillRect(renderer, &squareRect);
}

void Application::RenderImage( SDL_Texture* image, int x, int y )
{
	int width, height;
	SDL_QueryTexture(image, NULL, NULL, &width, &height);
	SDL_Rect dst = { x, y, width, height };
	SDL_RenderCopy(renderer, image, NULL, &dst);
}

void Application::RenderImage( SDL_Texture* image, int x, int y, int w, int h )
{
	SDL_Rect dst = { x, y, w, h };
}

void Application::RenderEntity(Entity& entity)
{
	SDL_RenderCopy(renderer, entity.spritesheet, &entity.sprite, &entity.position);
}

void Application::RenderEntity(Camera& camera, Entity& entity)
{
    SDL_Rect dest;
    dest.x = entity.position.x - camera.position.x;
    dest.y = entity.position.y - camera.position.y;
    dest.w = entity.position.w;
    dest.h = entity.position.h;

    //std::cout << "1 ( x, y ) :" << entity.position.x << " : " << entity.position.y << "\n";
    //SDL_RenderCopy(renderer, entity.spritesheet, &entity.sprite, &dest);
    const SDL_Point* offset = &entity.offset;
    SDL_RenderCopyEx(renderer, entity.spritesheet, &entity.sprite, &dest, entity.angle, offset, entity.flip);
}

void Application::RenderText(const char* toRenderText)
{
	
}

void Application::CalculateZoom(Camera& camera)
{
	camera.position.w = (int)(camera.position.w * zoom);
	camera.position.h = (int)(camera.position.h * zoom);
	SDL_RenderSetScale(renderer, zoom, zoom); // Ajustar la escala del renderer
}