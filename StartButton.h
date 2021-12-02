//Jennifer McCarthy, jemc7787

#ifndef STARTBUTTON_H
#define STARTBUTTON_H
#include "Button.h"

class StartButton : public Button
{
public:
	static StartButton* get_instance(int x, int y, int w, int h, std::string txt, GameEngine* game);
protected:
	StartButton(int x, int y, int w, int h, std::string txt, GameEngine* game);
private:
	void perform(GameEngine*);
};

#endif

