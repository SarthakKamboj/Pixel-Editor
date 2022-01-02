
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
#include "toolBar.h"
#include "numberInput.h"
#include "canvasCreationModal.h"

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

	bool running = true;

	Canvas canvas(64, 48, 8, 8, renderer);
	ToolBar toolBar(0, 0, windowWidth, 30);
	// NumberInput numberInput(16, 100, { 255, 255, 255, 255 }, { 0,0,0,255 });

	while (!input.quit) {

		uint32_t start = SDL_GetTicks();

		input.update();
		canvas.update(40, 40);
		colorPicker.update(700, 40);
		toolBar.update();

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		canvas.render(40, 40);
		colorPicker.render(700, 40);
		toolBar.render();

		SDL_RenderPresent(renderer);

		uint32_t msFrameTime = SDL_GetTicks() - start;

		if (msFrameTime < expectedMSPerFrame) {
			SDL_Delay(expectedMSPerFrame - msFrameTime);
		}
	}

	return 0;
}