//Jennifer McCarthy, jemc7787

#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <vector>
#include <string>
#include <SDL_mixer.h>
#include "Sprite.h"
#include "Player.h"
class Enemy;
class Bullet;

class GameEngine
{
public:
	static GameEngine* get_instance(const char* bg, const char* enemy, const char* player_img, const char* bullet, const char* sound, const char* music, Player* player, Bullet* b, Enemy* e, std::vector<int> diffs, std::vector<Sprite*> &menu, std::vector<Sprite*> &restart);
	void set_difficulty(int difficulty);
	int get_difficulty();
	std::string get_difficulty_name(int diff);
	void add(Sprite* sprite);
	void remove(Sprite* sprite);
	void run();
	void play();
	void restart_menu();
	~GameEngine();
protected:
	GameEngine(const char* bg, const char* enemy, const char* player_img, const char* bullet, const char* sound, const char* music, Player* player, Bullet* b, Enemy* e, std::vector<int> diffs, std::vector<Sprite*> &menu, std::vector<Sprite*> &restart);
private:
	void generate_enemies(int counter, int speed, int enemy_kill_count);
	std::vector<Sprite*> sprites, added, removed, bullets, enemies;
	SDL_Texture* texture;
	int difficulty;
	Mix_Chunk* music;
	const char* path_to_enemy;
	const char* path_to_player;
	const char* path_to_bullet;
	const char* path_to_sound;
	Player* player;
	Bullet* bullet;
	Enemy* enemy;
	std::vector<int> difficulty_settings;
	std::vector<Sprite*> &menu;
	std::vector<Sprite*> &restart;
};

#endif