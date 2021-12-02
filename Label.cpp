//Jennifer McCarthy, jemc7787

#include "Label.h"
#include "System.h"
#include <string>

Label* Label::get_instance(int x, int y, int w, int h, std::string txt) {
	return new Label(x, y, w, h, txt);
}

Label::Label(int x, int y, int w, int h, std::string txt) :Sprite(x, y, w, h), text(txt) {
	SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), text.c_str(), { 199, 186, 236 });
	texture = SDL_CreateTextureFromSurface(sys.get_renderer(), surf);
	SDL_FreeSurface(surf);
}

void Label::draw() const {
	SDL_RenderCopy(sys.get_renderer(), texture, NULL, &get_rectangle());
}

Label::~Label() {
	SDL_DestroyTexture(texture);
}

std::string Label::getText() const {
	return text;
}

void Label::setText(std::string newText) {
	text = newText;
	SDL_DestroyTexture(texture);
	SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), text.c_str(), { 199, 186, 236 });
	texture = SDL_CreateTextureFromSurface(sys.get_renderer(), surf);
	SDL_FreeSurface(surf);
}