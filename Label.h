//Jennifer McCarthy, jemc7787

#ifndef LABEL_H
#define LABEL_H
#include "Sprite.h"
#include <string>

class Label:public Sprite
{
public:
	static Label* get_instance(int x, int y, int w, int h, std::string txt); 
	void draw() const;
	std::string getText() const;
	void setText(std::string newText);
	~Label();
protected:
	Label(int x, int y, int w, int h, std::string txt); 
private:
	void tick(GameEngine*) {};
	std::string text;
	SDL_Texture* texture;
};

#endif

