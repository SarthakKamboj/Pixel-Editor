#pragma once

#include "SDL.h"
#include "input.h"
#include <vector>
#include "util.h"
#include "math.h"

extern Input input;
extern SDL_Renderer* renderer;

class NumberInput {
public:
	NumberInput(int fontSize, int width, SDL_Color background, SDL_Color textColor);
	void update(int x, int y);
	void render(int x, int y);

	bool active = false;

	int getInputNumber();

private:
	int fontSize, width, height;
	std::vector<SDL_Texture*> numberTextures;
	SDL_Color background, textColor;

	std::string inputString = "";

	int numberInputWidth = 0;
};
