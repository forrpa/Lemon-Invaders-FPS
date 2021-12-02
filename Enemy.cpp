//Jennifer McCarthy, jemc7787

#include "Enemy.h"
#include "System.h"
#include <SDL_image.h>

Enemy* Enemy::get_instance(int x, int y, int w, int h, const char* enemy, int num, std::vector<int> s) {
	return new Enemy(x, y, w, h, enemy, num, s);
}

Enemy::Enemy(int x, int y, int w, int h, const char* enemy, int num, std::vector<int> s) :Sprite(x, y, w, h), num_of_enemies(num), speed(s), path_to_enemy(enemy) {
	SDL_Surface* lemon_surface = IMG_Load(enemy);
	enemy_texture = SDL_CreateTextureFromSurface(sys.get_renderer(), lemon_surface);
	SDL_FreeSurface(lemon_surface);
}

void Enemy::draw() const {
	SDL_RenderCopy(sys.get_renderer(), enemy_texture, NULL, &get_rectangle());
}

void Enemy::tick(GameEngine* game_engine) {
	if (game_engine->get_difficulty() == 1) {
		set_rectangle_y(get_rectangle().y + speed[0]);
	} else if (game_engine->get_difficulty() == 2) {
		set_rectangle_y(get_rectangle().y + speed[1]);
	} else {
		set_rectangle_y(get_rectangle().y + speed[2]);
	}
}

Enemy::~Enemy() {
	SDL_DestroyTexture(enemy_texture);
}

