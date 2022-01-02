#include "canvasManager.h"

CanvasManager::CanvasManager() : canvas(0, 0, 0, 0, renderer) {

}

void CanvasManager::createCanvas(int rows, int cols, int widthPerCell, int heightPerCell) {
	canvas = Canvas(rows, cols, widthPerCell, heightPerCell, renderer);
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