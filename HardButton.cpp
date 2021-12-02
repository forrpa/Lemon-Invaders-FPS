//Jennifer McCarthy, jemc7787

#include "HardButton.h"

HardButton::HardButton(int x, int y, int w, int h, std::string txt, GameEngine* game, Label* lbl):Button(x, y, w, h, txt, game), label(lbl) {

}

HardButton* HardButton::get_instance(int x, int y, int w, int h, std::string txt, GameEngine* game, Label* lbl) {
	return new HardButton(x, y, w, h, txt, game, lbl);
}

void HardButton::perform(GameEngine* game_engine) {
	game_engine->set_difficulty(3);
	label->setText("Hard");
}