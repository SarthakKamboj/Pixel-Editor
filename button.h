#pragma once

#include "SDL.h"
#include <string>
#include "util.h"
#include "input.h"

extern Input input;
extern SDL_Renderer* renderer;

class Button {
public:
	Button(std::string text, SDL_Color _background, SDL_Color _hoverBackground, SDL_Color _backgroundPressedOn, int x, int y, int fontSize);

	void update();
	void render();

	bool pressedOn = false;

private:

	bool pressedOnBackground = false;

	SDL_Texture* textTexture;
	SDL_Rect textTextureRect;

	SDL_Rect renderMapping;

	SDL_Color background;
	SDL_Color backgroundPressedOn;
	SDL_Color hoverBackground;

	bool hoverOver = false;
};
