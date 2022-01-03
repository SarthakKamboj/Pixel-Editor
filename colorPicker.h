#pragma once

#include "SDL.h"
#include "input.h"
#include "slider.h"
#include "label.h"
#include <string>

extern SDL_Renderer* renderer;
extern Input input;

class ColorPicker {
public:
	ColorPicker();
	ColorPicker(const ColorPicker& other);

	void render(int x, int y);
	void update(int x, int y);
	SDL_Color selectedColor;

private:

	struct ColorInput {

		ColorInput(Slider _slider, Label _label) : slider(_slider), label(_label)
		{
			label.setLabel(std::to_string(slider.cur));
		}

		Slider slider;
		Label label;

		void update(int x, int y) {
			int prevCur = slider.cur;
			slider.update(x, y);
			int newCur = slider.cur;

			if (prevCur != newCur) {
				label.setLabel(std::to_string(newCur));
			}
		}

		void render(int x, int y) {
			slider.render(x, y);
			label.render(x, y + 50);
		}
	};

	SDL_Color colors[6];
	int selectedIdx;

	ColorInput red;
	ColorInput green;
	ColorInput blue;
};
