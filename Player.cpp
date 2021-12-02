//Jennifer McCarthy, jemc7787

#include "Player.h"
#include "System.h"
#include <SDL.h>
#include <SDL_image.h>

Player::Player(int x, int y, int w, int h, const char* path_to_player, const char* path_to_s, int s):Sprite(x, y, w, h), path_to_sound(path_to_s), speed(s), start_pos(x) {
	SDL_Surface* player_surface = IMG_Load(path_to_player);
	texture = SDL_CreateTextureFromSurface(sys.get_renderer(), player_surface);
	SDL_FreeSurface(player_surface);
	Mix_OpenAudio(20050, AUDIO_S16SYS, 2, 4096);
	shoot_sound = Mix_LoadWAV(path_to_sound);
}

Player* Player::get_instance(int x, int y, int w, int h, const char* path_to_player, const char* path_to_s, int speed) {
	return new Player(x, y, w, h, path_to_player, path_to_s, speed);
}

void Player::draw() const
{
	SDL_RenderCopy(sys.get_renderer(), texture, NULL, &get_rectangle());
}

void Player::key_down(const SDL_Event& eve)
{
	if (eve.key.keysym.sym == SDLK_LEFT || eve.key.keysym.sym == SDLK_a) {
		if (get_rectangle().x <= 0)
			set_rectangle_x(0);
		else
			set_rectangle_x(get_rectangle().x - speed);
	}
	else if (eve.key.keysym.sym == SDLK_RIGHT || eve.key.keysym.sym == SDLK_d) {
		if (get_rectangle().x >= (sys.get_width() - get_rectangle().w))
			set_rectangle_x(sys.get_width() - get_rectangle().w);
		else
			set_rectangle_x(get_rectangle().x + speed);
	}
	else if (eve.key.keysym.sym == SDLK_SPACE) {
		Mix_PlayChannel(-1, shoot_sound, 0);
	}
}

Player::~Player()
{
	Mix_FreeChunk(shoot_sound);
	Mix_CloseAudio();
	SDL_DestroyTexture(texture);
}

