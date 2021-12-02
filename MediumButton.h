//Jennifer McCarthy, jemc7787

#ifndef MEDIUMBUTTON_H
#define MEDIUMBUTTON_H
#include "Button.h"
#include "Label.h"

class MediumButton : public Button
{
public:
	static MediumButton* get_instance(int x, int y, int w, int h, std::string txt, GameEngine* game, Label* lbl);
protected:
	MediumButton(int x, int y, int w, int h, std::string txt, GameEngine* game, Label* lbl);
private:
	Label* label;
	void perform(GameEngine*);
};

#endif