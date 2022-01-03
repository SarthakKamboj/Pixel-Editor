
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
#include "canvasManager.h"
#include <string>
#include "clearButton.h"

// TODO: create canvas dynamically

Input input;
SDL_Renderer* renderer;
History history;

// TODO: add z-index collision input detection

int main(int argc, char* args[]) {

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0 || TTF_Init() == -1) {
		std::cout << "failed setup" << std::endl;
	}

	int FPS = 60;
	float expectedMSPerFrame = 1000.0f / FPS;

	int windowWidth = 800;
	int windowHeight = 775;

	SDL_Window* window = SDL_CreateWindow("Pixel Editor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);

	bool running = true;

	ColorPicker colorPicker;
	CanvasManager canvasManager(colorPicker);

	ToolBar toolBar(0, 0, windowWidth, 30, canvasManager);
	ClearButton clearButton(canvasManager);

	SDL_Rect canvasManagerRect = {};
	canvasManagerRect.x = 100;
	canvasManagerRect.y = 40;

	SDL_Rect colorPickerRect = {};
	colorPickerRect.x = 600;
	colorPickerRect.y = 40;


	while (!input.quit) {

		uint32_t start = SDL_GetTicks();

		input.update();
		canvasManager.update(canvasManagerRect.x, canvasManagerRect.y);
		colorPicker.update(colorPickerRect.x, colorPickerRect.y);
		toolBar.update();
		clearButton.update();

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		canvasManager.render(canvasManagerRect.x, canvasManagerRect.y);
		colorPicker.render(colorPickerRect.x, colorPickerRect.y);
		toolBar.render();
		clearButton.render();

		SDL_RenderPresent(renderer);

		uint32_t msFrameTime = SDL_GetTicks() - start;

		if (msFrameTime < expectedMSPerFrame) {
			SDL_Delay(expectedMSPerFrame - msFrameTime);
		}
	}

	return 0;
}