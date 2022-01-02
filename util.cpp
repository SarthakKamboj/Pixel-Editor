#include "util.h"

bool Util::isSameColor(SDL_Color& c1, SDL_Color& c2) {
	return c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a;
}