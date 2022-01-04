#include "colorPicker.h"

ColorPicker::ColorPicker() :
	//: redSlider(0, 255, 100),
	//redLabel(std::to_string(redSlider.cur), 16)
	red(ColorPicker::ColorInput(Slider(0, 255, 100), Label("0", 16), Label("Red", 16))),
	green(ColorPicker::ColorInput(Slider(0, 255, 100), Label("0", 16), Label("Green", 16))),
	blue(ColorPicker::ColorInput(Slider(0, 255, 100), Label("0", 16), Label("Blue", 16)))
{
	colors[0] = { 217, 40, 1, 255 };
	colors[1] = { 136,113,1, 255 };
	colors[2] = { 252,153,57, 255 };
	colors[3] = { 255, 0, 255, 255 };
	colors[4] = { 255, 255, 0, 255 };
	colors[5] = { 255, 255, 255, 255 };

	// selectedColor = colors[0];
	selectedColor = getSelectedColor();
	selectedIdx = 0;

	/*
	red.slider = Slider(0, 255, 100);
	red.label = Label(std::to_string(red.slider.cur), 16);

	green.slider = Slider(0, 255, 100);
	green.label = Label(std::to_string(red.slider.cur), 16);

	blue.slider = Slider(0, 255, 100);
	blue.label = Label(std::to_string(red.slider.cur), 16);
	*/

}


SDL_Color ColorPicker::getSelectedColor() {
	SDL_Color color;
	color.r = red.slider.cur;
	color.g = green.slider.cur;
	color.b = blue.slider.cur;
	color.a = 255;
	return color;
}


ColorPicker::ColorPicker(const ColorPicker& other) :
	red(ColorPicker::ColorInput(Slider(0, 255, 100), Label("0", 16), Label("Red", 16))),
	green(ColorPicker::ColorInput(Slider(0, 255, 100), Label("0", 16), Label("Green", 16))),
	blue(ColorPicker::ColorInput(Slider(0, 255, 100), Label("0", 16), Label("Blue", 16)))
	//: redSlider(0, 255, 100),
	//redLabel(std::to_string(redSlider.cur), 16)
{
	colors[0] = { 217, 40, 1, 255 };
	colors[1] = { 136,113,1, 255 };
	colors[2] = { 252,153,57, 255 };
	colors[3] = { 255, 0, 255, 255 };
	colors[4] = { 255, 255, 0, 255 };
	colors[5] = { 255, 255, 255, 255 };

	// selectedColor = colors[0];
	// selectedColor = { red.slider.cur, green.slider.cur, blue.slider.cur, 255 };

	selectedColor = getSelectedColor();
	selectedIdx = 0;

	/*
	red.slider = Slider(0, 255, 100);
	red.label = Label(std::to_string(red.slider.cur), 16);

	green.slider = Slider(0, 255, 100);
	green.label = Label(std::to_string(red.slider.cur), 16);

	blue.slider = Slider(0, 255, 100);
	blue.label = Label(std::to_string(red.slider.cur), 16);
	*/
}

void ColorPicker::update(int x, int y) {

	red.update(x, y + 400);
	green.update(x, y + 500);
	blue.update(x, y + 600);

	// selectedColor = { red.slider.cur, green.slider.cur, blue.slider.cur, 255 };

	selectedColor = getSelectedColor();
	/*
	if (!input.mousePressed) return;

	int bottomYPadding = 10;
	int size = 30;

	for (int i = 0; i < 6; i++) {
		SDL_Color& color = colors[i];

		int colorY = y + ((size + bottomYPadding) * i);

		if (input.mouseState.x >= x && input.mouseState.x <= x + size && input.mouseState.y >= colorY && input.mouseState.y <= colorY + size) {
			selectedColor = color;
			selectedIdx = i;
		}
	}
	*/
}

void ColorPicker::render(int x, int y) {

	// redSlider.render(x, y + 400);
	// redLabel.render(x, y + 450);
	red.render(x, y + 400);
	green.render(x, y + 500);
	blue.render(x, y + 600);

	uint8_t r, g, b, a;
	SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);

	/*
	int yPadding = 5;
	int size = 30;

	for (int i = 0; i < 6; i++) {

		int colorCellStartY = y + ((size + (2 * yPadding)) * i) + yPadding;

		if (i == selectedIdx) {

			SDL_SetRenderDrawColor(renderer, 125, 125, 125, 255);

			int borderWidth = 5;

			SDL_Rect position;
			position.x = x - borderWidth;
			position.y = colorCellStartY - borderWidth;
			position.w = size + (2 * borderWidth);
			position.h = size + (2 * borderWidth);

			SDL_RenderFillRect(renderer, &position);
		}

		SDL_Color& color = colors[i];
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

		SDL_Rect position;
		position.x = x;
		position.y = colorCellStartY;
		position.w = size;
		position.h = size;

		SDL_RenderFillRect(renderer, &position);


	}
	*/

	SDL_Color prev = Util::getRenderDrawColor();
	SDL_Color colorSelected = { red.slider.cur, green.slider.cur, blue.slider.cur, 255 };
	Util::setRenderDrawColor(colorSelected);
	SDL_Rect colorMapping = { x, y + 675, 50, 50 };
	SDL_RenderFillRect(renderer, &colorMapping);

	Util::setRenderDrawColor(prev);

	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}