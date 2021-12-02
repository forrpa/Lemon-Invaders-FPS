//Jennifer McCarthy, jemc7787

#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
class GameEngine;

class Sprite
{
public:
	virtual ~Sprite();
	virtual void mouse_down(const SDL_Event&) {};
	virtual void mouse_up(const SDL_Event&) {};
	virtual void key_down(const SDL_Event&) {};
	virtual void key_up(const SDL_Event&) {};
	virtual void draw() const = 0;
	const SDL_Rect& get_rectangle() const;
	void set_rectangle_x(int);
	void set_rectangle_y(int);
	virtual void tick(GameEngine*) = 0;
protected:
	Sprite(int x, int y, int w, int h); 
private:
	SDL_Rect rectangle;
	Sprite(const Sprite& other) = delete; 
	const Sprite& operator=(const Sprite&) = delete; 
};
#endif

