#include "history.h"

void History::update() {
	if (input.inputPressed.u) {
		for (unsigned i = 0; i < stateChanges.size(); i++) {
			PixelChange& pixelChange = stateChanges[i];
			int row = pixelChange.row;
			int col = pixelChange.col;
			SDL_Color prevColor = pixelChange.prevColor;

			// canvas->pixels[row][col].color = prevColor;
		}
	}
}