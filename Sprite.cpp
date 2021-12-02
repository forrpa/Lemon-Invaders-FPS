//Jennifer McCarthy, jemc7787

#include "Sprite.h"

Sprite::Sprite(int x, int y, int w, int h) :rectangle{ x,y,w,h } {

}

const SDL_Rect& Sprite::get_rectangle() const {
	return rectangle;
}

void Sprite::set_rectangle_x(int i) {
	rectangle.x = i;
}

void Sprite::set_rectangle_y(int i) {
	rectangle.y = i;
}

Sprite::~Sprite() {
}