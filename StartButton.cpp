//Jennifer McCarthy, jemc7787

#include "StartButton.h"

StartButton::StartButton(int x, int y, int w, int h, std::string txt, GameEngine* game):Button(x, y, w, h, txt, game) {

}

StartButton* StartButton::get_instance(int x, int y, int w, int h, std::string txt, GameEngine* game) {
	return new StartButton(x,y,w,h,txt,game);
}

void StartButton::perform(GameEngine* game_engine) {
	game_engine->play();
}