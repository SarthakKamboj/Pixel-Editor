
#include <iostream>
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include <vector>
#include "canvas.h"
#include "input.h"
#include "colorPicker.h"

Input input;
SDL_Renderer* renderer;
ColorPicker colorPicker;

int main(int argc, char* args[]) {


	if (SDL_Init(SDL_INIT_EVERYTHING) != 0 || TTF_Init() == -1) {
		std::cout << "failed setup" << std::endl;
	}

	int FPS = 60;
	float secPerFrame = 1000.0f / FPS;

	int windowWidth = 800;
	int windowHeight = 700;

	SDL_Window* window = SDL_CreateWindow("Pixel Editor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);

	TTF_Font* font = TTF_OpenFont("fonts/SpaceMono.ttf", 16);
	SDL_Surface* surface = TTF_RenderText_Blended(font, "Image Editor", { 255, 255, 255, 255 });
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	int textWidth, textHeight;
	SDL_QueryTexture(texture, NULL, NULL, &textWidth, &textHeight);

	bool running = true;

	SDL_Event evnt;

	SDL_Rect dest = { 0,0, textWidth, textHeight };

	Canvas canvas(64, 48, 10, 10);

	while (!input.quit) {

		uint32_t start = SDL_GetTicks();

		input.update();
		canvas.update(0, 0);
		colorPicker.update(700, 0);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		canvas.render(0, 0);
		colorPicker.render(700, 0);

		SDL_RenderPresent(renderer);

		uint32_t frameTime = SDL_GetTicks() - start;

		if (frameTime < secPerFrame) {
			SDL_Delay(secPerFrame - frameTime);
		}
	}

	return 0;
}