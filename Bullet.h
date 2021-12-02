//Jennifer McCarthy, jemc7787

#ifndef BULLET_H 
#define BULLET_H
#include "Sprite.h"
#include "GameEngine.h"

class Bullet:public Sprite
{
public:
	static Bullet* get_instance(int x, int y, int w, int h, const char* path_to_bullet, int speed);
	~Bullet();
	void draw() const;
	void tick(GameEngine*);
	int get_speed() {return speed; };
	int get_launch_y() { return launch_y; }
protected:
	Bullet(int x, int y, int w, int h, const char* path_to_bullet, int speed);
private:
	SDL_Texture* texture;
	int speed, launch_y;
};

#endif 
