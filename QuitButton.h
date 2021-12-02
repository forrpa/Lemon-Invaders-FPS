//Jennifer McCarthy, jemc7787

#ifndef QUITBUTTON_H
#define QUITBUTTON_H
#include "Button.h"

class QuitButton:public Button
{
public:
	static QuitButton* get_instance(int x, int y, int w, int h, std::string txt, GameEngine* game);
protected:
	QuitButton(int x, int y, int w, int h, std::string txt, GameEngine* game);
private:
	void perform(GameEngine*);
};

#endif

