#pragma once

#include "SDL.h"
#include <string>
#include "util.h"

extern SDL_Renderer* renderer;

class Label {
public:
	Label(std::string label, int fontSize);
	void render(int x, int y);

private:
	int fontSize;
	SDL_Texture* labelTexture;
	std::string label;
};
