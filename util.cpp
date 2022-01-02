#include "util.h"

bool Util::isSameColor(SDL_Color& c1, SDL_Color& c2) {
	return c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a;
}


SDL_Texture* Util::getText(std::string text, int fontSize, SDL_Color color) {
	static TTF_Font* font = TTF_OpenFont("fonts/SpaceMono.ttf", fontSize);
	SDL_Surface* textSurface = TTF_RenderText_Blended(font, text.c_str(), color);
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);
	return textTexture;
}


SDL_Color Util::getRenderDrawColor() {
	SDL_Color color;
	SDL_GetRenderDrawColor(renderer, &color.r, &color.g, &color.b, &color.a);
	return color;
}

void Util::setRenderDrawColor(SDL_Color color) {
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}
