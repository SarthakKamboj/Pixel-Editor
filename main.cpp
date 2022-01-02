
#include <iostream>
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include <vector>
#include "input.h"
#include "colorPicker.h"
#include "pixel.h"
#include "history.h"
#include "canvas.h"

Input input;
SDL_Renderer* renderer;
ColorPicker colorPicker;
History history;

int main(int argc, char* args[]) {


	if (SDL_Init(SDL_INIT_EVERYTHING) != 0 || TTF_Init() == -1) {
		std::cout << "failed setup" << std::endl;
	}

	int FPS = 60;
	float expectedMSPerFrame = 1000.0f / FPS;

	int windowWidth = 800;
	int windowHeight = 700;

	SDL_Window* window = SDL_CreateWindow("Pixel Editor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);

	std::cout << renderer << std::endl;

	bool running = true;

	Canvas canvas(64, 48, 10, 10, renderer);

	// history.canvas = &canvas;
	// canvas.history = &history;
	// Pixel::history = &history;

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

		uint32_t msFrameTime = SDL_GetTicks() - start;

		if (msFrameTime < expectedMSPerFrame) {
			SDL_Delay(expectedMSPerFrame - msFrameTime);
		}
	}

	return 0;
}