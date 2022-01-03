#include "label.h"

Label::Label(std::string _label, int _fontSize) : fontSize(_fontSize), label(_label) {
	// labelTexture = Util::getText(label, fontSize, { 255, 255, 255, 255 });
	setLabel(label);
}


Label& Label::operator=(const Label& other) {
	fontSize = other.fontSize;
	label = other.label;
	setLabel(label);
	return *this;
}

void Label::render(int x, int y) {
	SDL_Rect mapping;
	mapping.x = x;
	mapping.y = y;
	SDL_QueryTexture(labelTexture, NULL, NULL, &mapping.w, &mapping.h);
	SDL_RenderCopy(renderer, labelTexture, NULL, &mapping);
}

void Label::setLabel(std::string _label) {
	if (labelTexture != NULL) {
		SDL_DestroyTexture(labelTexture);
	}
	label = _label;
	labelTexture = Util::getText(label, fontSize, { 255, 255, 255, 255 });
	int w, h;
	SDL_QueryTexture(labelTexture, NULL, NULL, &w, &h);
}
