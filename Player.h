//Jennifer McCarthy, jemc7787

#ifndef PLAYER_H
#define PLAYER_H
#include "Sprite.h"
#include <SDL_mixer.h>

class Player : public Sprite
{
public:
	static Player* get_instance(int x, int y, int w, int h, const char* path_to_player, const char* path_to_s, int speed);
	void draw() const;
	void key_down(const SDL_Event&);
	int get_speed() { return speed; }
	int get_start_pos() { return start_pos; }
	~Player();
protected:
	Player(int x, int y, int w, int h, const char* path_to_player, const char* path_to_s, int speed);
private:
	SDL_Texture* texture;
	void tick(GameEngine*) {}
	const char* path_to_sound;
	Mix_Chunk* shoot_sound;
	int speed;
	int start_pos;
};

#endif