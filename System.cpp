//Jennifer McCarthy, jemc7787

#include "System.h"
#include <SDL.h>
#include <SDL_image.h>

System::System() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Lemon invaders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);
	TTF_Init();
	font = TTF_OpenFont("c:/Windows/Fonts/cour.ttf", 36);
}

System::~System() {
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

SDL_Renderer* System::get_renderer() const {
	return renderer;
}

TTF_Font* System::get_font() const {
	return font;
}

const int System::get_width() {
	return width;
}

const int System::get_height() {
	return height;
}

System sys;
