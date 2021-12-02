//Jennifer McCarthy, jemc7787

#include "Bullet.h"
#include "System.h"
#include <SDL.h>
#include <SDL_image.h>

Bullet::Bullet(int x, int y, int w, int h, const char* path_to_bullet, int s):Sprite(x, y, w, h), launch_y(y), speed(s) {
	texture = IMG_LoadTexture(sys.get_renderer(), path_to_bullet);
}

Bullet* Bullet::get_instance(int x, int y, int w, int h, const char* path_to_bullet, int speed) {
	return new Bullet(x, y, w, h, path_to_bullet, speed);
}

Bullet::~Bullet() {
	SDL_DestroyTexture(texture);
}
void Bullet::draw() const {
	SDL_RenderCopy(sys.get_renderer(), texture, NULL, &get_rectangle());
}
void Bullet::tick(GameEngine* game_engine) {
	if (get_rectangle().y <= 0) {
		game_engine->remove(this);
	}
	else {
		set_rectangle_y(get_rectangle().y - speed);
	}
}
