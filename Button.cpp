//Jennifer McCarthy, jemc7787

#include "Button.h"
#include "System.h"
#include <SDL_image.h>

Button::Button(int x, int y, int w, int h, std::string txt, GameEngine* game_engine) :Sprite(x, y, w, h),current_game(game_engine) {
	SDL_Color color = { 255,255,255 };
	SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), txt.c_str(), color);
	texture = SDL_CreateTextureFromSurface(sys.get_renderer(), surf);
	SDL_FreeSurface(surf);
	down_icon = IMG_LoadTexture(sys.get_renderer(), "c:/images/nerknapp.png");
	text = txt;
}

Button::~Button() {
	SDL_DestroyTexture(texture);
	SDL_DestroyTexture(down_icon);
}

Button* Button::get_instance(int x, int y, int w, int h, std::string txt, GameEngine* game_engine) {
	return new Button(x, y, w, h, txt, game_engine);
}

void Button::mouse_down(const SDL_Event& eve) {
	SDL_Point p = { eve.button.x, eve.button.y }; 
	if (SDL_PointInRect(&p, &get_rectangle())) {
		is_down = true; 
	}
}

void Button::mouse_up(const SDL_Event& eve) {
	SDL_Point p = { eve.button.x, eve.button.y };
	if (SDL_PointInRect(&p, &get_rectangle())) {
		perform(current_game);
	}
	is_down = false;
}

void Button::draw() const {
	if (is_down) {
		SDL_RenderCopy(sys.get_renderer(), down_icon, NULL, &get_rectangle());
	}
	SDL_RenderCopy(sys.get_renderer(), texture, NULL, &get_rectangle());
}

std::string Button::get_text() {
	return text;
}

