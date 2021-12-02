//Jennifer McCarthy, jemc7787

#ifndef ENEMY_H
#define ENEMY_H
#include "Sprite.h"
#include "GameEngine.h"
#include <vector>
class Enemy:public Sprite
{
public:
	static Enemy* get_instance(int x, int y, int w, int h, const char* enemy, int num, std::vector<int> speed);
	int get_num_of_enemies() { return num_of_enemies; }
	std::vector<int> get_speed() { return speed; };
	const char* get_path_to_enemy() { return path_to_enemy; }
	void draw() const;
	void tick(GameEngine*);
	~Enemy();
protected:
	Enemy(int x, int y, int w, int h, const char* enemy, int num, std::vector<int> speed);
private:
	SDL_Texture* enemy_texture;
	int num_of_enemies;
	std::vector<int> speed;
	const char* path_to_enemy;
};
#endif

