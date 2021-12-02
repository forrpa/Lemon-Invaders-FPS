//Jennifer McCarthy, jemc7787

#include "EasyButton.h"

EasyButton::EasyButton(int x, int y, int w, int h, std::string txt, GameEngine* game, Label* lbl) :Button(x, y, w, h, txt, game), label(lbl) {

}

EasyButton* EasyButton::get_instance(int x, int y, int w, int h, std::string txt, GameEngine* game, Label* lbl) {
	return new EasyButton(x, y, w, h, txt, game, lbl);
}

void EasyButton::perform(GameEngine* game_engine) {
	game_engine->set_difficulty(1);
	label->setText("Easy");
}