#pragma once

#include "SDL.h"
#include "SDL_ttf.h"
#include <string>

extern SDL_Renderer* renderer;

class Util {
public:
	static bool isSameColor(SDL_Color& c1, SDL_Color& c2);
	static SDL_Texture* getText(std::string text, int fontSize, SDL_Color color);
	static SDL_Color getRenderDrawColor();
	static void setRenderDrawColor(SDL_Color color);
};
