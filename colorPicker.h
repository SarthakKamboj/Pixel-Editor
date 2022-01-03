#pragma once

#include "SDL.h"
#include "input.h"
#include "slider.h"
#include "label.h"
#include <string>
#include "util.h"

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

	class ColorInput {
	public:
		ColorInput(Slider _slider, Label _valLabel, Label _colorLabel) : slider(_slider), valLabel(_valLabel),
			colorlabel(_colorLabel)
		{
			valLabel.setLabel(std::to_string(slider.cur));
		}

		void update(int x, int y) {
			int prevCur = slider.cur;
			slider.update(x, y + 30);
			int newCur = slider.cur;

			if (prevCur != newCur) {
				valLabel.setLabel(std::to_string(newCur));
			}
		}

		void render(int x, int y) {
			colorlabel.render(x, y);
			slider.render(x, y + 30);
			valLabel.render(x, y + 50);
		}

		Slider slider;

	private:

		Label valLabel;
		Label colorlabel;
	};

	SDL_Color colors[6];
	int selectedIdx;

	SDL_Color getSelectedColor();

	ColorInput red;
	ColorInput green;
	ColorInput blue;
};
