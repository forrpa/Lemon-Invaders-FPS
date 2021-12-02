//Jennifer McCarthy, jemc7787

#ifndef EASYBUTTON_H
#define EASYBUTTON_H
#include "Button.h"
#include "Label.h"

class EasyButton : public Button
{
public:
	static EasyButton* get_instance(int x, int y, int w, int h, std::string txt, GameEngine* game, Label* lbl);
protected:
	EasyButton(int x, int y, int w, int h, std::string txt, GameEngine* game, Label* lbl);
private:
	Label* label;
	void perform(GameEngine*);
};

#endif

