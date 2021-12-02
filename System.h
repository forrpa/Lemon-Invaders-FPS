//Jennifer McCarthy, jemc7787

#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL.h>
#include <SDL_ttf.h>

class System
{
public:
	System();
	~System();
	SDL_Renderer* get_renderer() const;
	TTF_Font* get_font() const;
	const int get_width();
	const int get_height();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	TTF_Font* font;
	const int width = 800;
	const int height = 600;
};

extern System sys;
#endif
