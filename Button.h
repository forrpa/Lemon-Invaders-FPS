//Jennifer McCarthy, jemc7787

#ifndef BUTTON_H
#define BUTTON_H
#include "Sprite.h"
#include "GameEngine.h"
#include <SDL.h>
#include <string>

class Button : public Sprite
{
public:
	static Button* get_instance(int x, int y, int w, int h, std::string txt, GameEngine* game);
	void mouse_down(const SDL_Event&);
	void mouse_up(const SDL_Event&); 
	void draw() const;
	virtual void perform(GameEngine*) {};
	std::string get_text();
	~Button();
protected:
	Button(int x, int y, int w, int h, std::string txt, GameEngine* game);
private:
	std::string text;
	SDL_Texture* texture;
	GameEngine* current_game;
	SDL_Texture* down_icon; 
	bool is_down = false; 
	void tick(GameEngine*) {};
};


#endif
