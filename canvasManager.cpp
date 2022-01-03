#include "canvasManager.h"

CanvasManager::CanvasManager(ColorPicker& _colorPicker) :
	colorPicker(_colorPicker)
	, canvas(Canvas(64, 48, 10, 10, renderer, colorPicker))
{
	created = true;
}

void CanvasManager::createCanvas(int rows, int cols, int widthPerCell, int heightPerCell) {
	canvas = Canvas(rows, cols, widthPerCell, heightPerCell, renderer, colorPicker);
	created = true;
}

void CanvasManager::update(int x, int y) {
	if (created) {
		canvas.update(x, y);
	}
}

void CanvasManager::render(int x, int y) {
	if (created) {
		canvas.render(x, y);
	}
}

Canvas* CanvasManager::getCanvas() {
	if (!created) return NULL;
	return &canvas;
}
