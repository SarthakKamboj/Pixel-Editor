#pragma once

#include <map>
#include<vector>
#include <algorithm>

#include "input.h"

extern Input input;

class UIComponentRegistrar;

class UIComponent {
public:
	UIComponent(int x, int y, int z, int width, int height, UIComponentRegistrar* uiRegistrar);
	virtual void update();
	virtual void render();

	int x, y, z;
	int width, height;
protected:
	bool focused = false;

private:
	UIComponentRegistrar* uiRegistrar;
};

class UIComponentRegistrar {
public:
	UIComponentRegistrar();
	void addUIComponent(UIComponent* uiComponent);

	void update();
	void render();

	std::map<int, std::vector<UIComponent*>> uiComponentLayers;
	std::vector<int> zLayers;

};
