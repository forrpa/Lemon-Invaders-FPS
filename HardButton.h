//Jennifer McCarthy, jemc7787

#ifndef HARDBUTTON_H
#define HARDBUTTON_H
#include "Button.h"
#include "Label.h"

class HardButton : public Button
{
public:
	static HardButton* get_instance(int x, int y, int w, int h, std::string txt, GameEngine* game, Label* lbl);
protected:
	HardButton(int x, int y, int w, int h, std::string txt, GameEngine* game, Label* lbl);
private:
	Label* label;
	void perform(GameEngine*);
};

#endif

