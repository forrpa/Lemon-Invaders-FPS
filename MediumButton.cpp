//Jennifer McCarthy, jemc7787

#include "MediumButton.h"

MediumButton::MediumButton(int x, int y, int w, int h, std::string txt, GameEngine* game, Label* lbl):Button(x, y, w, h, txt, game), label(lbl) {

}

MediumButton* MediumButton::get_instance(int x, int y, int w, int h, std::string txt, GameEngine* game, Label* lbl) {
	return new MediumButton(x, y, w, h, txt, game, lbl);
}

void MediumButton::perform(GameEngine* game_engine) {
	game_engine->set_difficulty(2);
	label->setText("Medium");
}