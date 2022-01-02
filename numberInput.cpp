#include "numberInput.h"

NumberInput::NumberInput(int _fontSize, int _width, SDL_Color _background, SDL_Color _textColor) : fontSize(_fontSize), width(_width),
background(_background), textColor(_textColor)
{
	SDL_Texture* numberTexture = Util::getText("1", fontSize, { 255, 255, 255, 255 });
	SDL_QueryTexture(numberTexture, NULL, NULL, NULL, &height);
	SDL_DestroyTexture(numberTexture);
}

void NumberInput::update(int x, int y) {

	if (input.mousePressed) {
		active = input.isMousePressedOn(x, y, width, height);
	}


	if (active) {
		for (int i = (int)SDLK_0; i <= (int)SDLK_9; i++) {
			if (input.pressed[(SDL_KeyCode)i]) {
				int number = i - ((int)SDLK_0);
				std::string numberString = std::to_string(number);
				inputString += numberString;
				SDL_Texture* numberTexture = Util::getText(numberString, fontSize, textColor);
				int numberTextureWidth;
				SDL_QueryTexture(numberTexture, NULL, NULL, &numberTextureWidth, NULL);
				numberTextures.push_back(numberTexture);
				numberInputWidth += numberTextureWidth;
				return;
			}
		}

		if (input.down[SDLK_BACKSPACE] && numberTextures.size() > 0) {
			SDL_Texture* numberToRemoveTexture = numberTextures[numberTextures.size() - 1];
			int textureWidth;
			SDL_QueryTexture(numberToRemoveTexture, NULL, NULL, &textureWidth, NULL);
			numberInputWidth -= textureWidth;
			numberTextures.erase(numberTextures.begin() + numberTextures.size() - 1);
			inputString = inputString.substr(0, inputString.size() - 1);
		}
	}
}

void NumberInput::render(int x, int y) {

	int startX = fmin(width - numberInputWidth, 0);
	int runningX = startX;
	SDL_Rect rect = { x, y , width, 20 };

	SDL_Color prevColor = Util::getRenderDrawColor();

	int borderWidth = 5;
	if (active) {
		SDL_Rect borderRect = { rect.x - borderWidth, rect.y - borderWidth , rect.w + (2 * borderWidth), rect.h + (2 * borderWidth) };
		Util::setRenderDrawColor({ 125, 125, 125, 255 });
		SDL_RenderFillRect(renderer, &borderRect);
	}

	Util::setRenderDrawColor(background);
	SDL_RenderFillRect(renderer, &rect);

	for (SDL_Texture* numberTexture : numberTextures) {
		int width, height;
		SDL_QueryTexture(numberTexture, NULL, NULL, &width, &height);

		if (runningX + width < 0) {
			runningX += width;
			continue;
		}


		SDL_Rect mapping = { runningX + x , y, width, height };
		if (runningX > 0) {
			SDL_RenderCopy(renderer, numberTexture, NULL, &mapping);
		}
		else {
			SDL_Rect numberTextureSection = { -runningX, 0, width + runningX, height };
			SDL_RenderCopy(renderer, numberTexture, &numberTextureSection, &mapping);
		}

		runningX += width;
	}

	Util::setRenderDrawColor(prevColor);
}