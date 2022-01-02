#include "label.h"

Label::Label(std::string _label, int _fontSize) : fontSize(_fontSize), label(_label) {
	labelTexture = Util::getText(label, fontSize, { 255, 255, 255, 255 });
}

void Label::render(int x, int y) {
	SDL_Rect mapping;
	mapping.x = x;
	mapping.y = y;
	SDL_QueryTexture(labelTexture, NULL, NULL, &mapping.w, &mapping.h);
	SDL_RenderCopy(renderer, labelTexture, NULL, &mapping);
}
