//Jennifer McCarthy, jemc7787

#include "QuitButton.h"

QuitButton::QuitButton(int x, int y, int w, int h, std::string txt, GameEngine* game) :Button(x, y, w, h, txt, game) {

}

QuitButton* QuitButton::get_instance(int x, int y, int w, int h, std::string txt, GameEngine* game) {
	return new QuitButton(x, y, w, h, txt, game);
}

void QuitButton::perform(GameEngine* game_engine) {
	exit(0);
}