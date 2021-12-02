//Jennifer McCarthy, jemc7787

#include "GameEngine.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include "Label.h"
#include "Button.h"
#include "StartButton.h"
#include "System.h"
#include "EasyButton.h"
#include "MediumButton.h"
#include "HardButton.h"
#include "QuitButton.h"
using namespace std;

int main(int argc, char** argv) {

	//Change images and sounds of the game
	const char* path_to_background = "c:/images/bg.bmp";
	const char* path_to_player = "c:/images/cat.png";
	const char* path_to_bullet = "C:/images/fluffball.png";
	const char* path_to_enemy = "C:/images/lemon2.png";
	const char* path_to_bg_music = "C:/sounds/bg_music.wav";
	const char* path_to_shoot_sound = "C:/sounds/meow.wav";

	/*PLAYER*/
	/*To use custom player replace the first nullptr with player in game_engine parameters*/
	int num_of_players = 1; //Change number of players, 1 or 2. Default is 1
	int speed = 60; //Change player speed, 60 is default. Higher number = faster
	int h = 130; //Change height of player image
	int w = 100; //Change width of player image
	int x = (sys.get_width() - w) / 2; //Change start-position x. Default is center of screen.
	int y = sys.get_height() - h; //Change start-position y. 
	Player* player = Player::get_instance(x, y, w, h, path_to_player, path_to_shoot_sound, speed);

	/*ENEMY*/
	/*To use custom enemy replace the third nullptr with enemy in game_engine parameters*/
	int num_of_enemies = 1000; //Change number of total enemies per game
	vector<int> e_speed{1,2,3}; //Change enemy speed for different difficulties. 1 (easy), 2 (medium) and 3(hard) is default.
	int e_y = 0; //Change where the enemies will drop, y-coordinate, 0 is default
	int e_w = 71; //Change width of enemy image
	int e_h = 102; //Change height of enemy image
	//Where the enemy drops (x-coordinate) cant be changed, it's random. Default is that x is random between 0 and the screen width - enemy width. 
	Enemy* enemy = Enemy::get_instance((rand() % (sys.get_width() - e_w)), e_y, e_w, e_h, path_to_enemy, num_of_enemies, e_speed);

	/*BULLET*/
	/*To use custom bullet replace the second nullptr with bullet in game_engine parameters*/
	int b_speed = 20; //Change bullet speed
	//Where the bullet fires from cant be changed. It will always launch from the players x-position.
	int launch_y = 500; //Change where bullet launches, y-coordinate
	int b_w = 30; //Change bullet witdh
	int b_h = 30; //Change bullet height
	Bullet* bullet = Bullet::get_instance(player->get_rectangle().x, launch_y, b_w, b_h, path_to_bullet, b_speed);

	/*DIFFICULTY*/
	//The difficulty depends on enemy speed, acceleration speed, how fast enemy spawn and max acceleration speed (fastest level).

	//DEFAULT: Every difficulty starts with speed 200 and counts down.
	//Easy: Monster speed 1. Acc speed 2. Max acc speed 30. Spawn speed 1000.
	//Medium: Monster speed 2. Acc speed 5. Max acc speed 20. Spawn speed 500.
	//Hard: Monster speed 3 Acc speed 10. Max acc speed 10. Spawn speed 300.

	/*SET DIFFICULTY*/
	/*To use custom difficulty settings please replace vector<int>() with difficulty_settings*/

	//In the vector difficulty_settings there are 9 values. Value 0-2 is easy difficulty, value 3-5 is medium and value 6-8 hard.
	//For each difficulty, there is values for acceleration speed, max acceleration speed and acceleration time. 
	vector<int> difficulty_settings{5,30,500, 10,20,300, 15,10,200}; //easy acc speed, easy max acc, easy acc time, medium acc speed osv...

	vector<Sprite*> menu; 
	vector<Sprite*> restart;

	//GameEngine* game_engine = GameEngine::get_instance(path_to_background, path_to_enemy, path_to_player, path_to_bullet, path_to_shoot_sound, path_to_bg_music, nullptr, nullptr, nullptr, vector<int>(), menu, restart); //default Sprites/difficulty
	GameEngine* game_engine = GameEngine::get_instance(path_to_background, path_to_enemy, path_to_player, path_to_bullet, path_to_shoot_sound, path_to_bg_music, player, bullet, enemy, difficulty_settings, menu, restart); //custom Sprites/difficulty

	/*MENU*/ 
	//If no menu is wanted, just comment out the lines below.
	//The menu can be changed and more elements can be added.
	Button* b1 = StartButton::get_instance(sys.get_width() - 500, 100, 200, 70, "Start Game", game_engine); 
	Label* l = Label::get_instance(sys.get_width() / 4, 200, 250, 70, "Difficulty: ");
	Label* l2 = Label::get_instance(sys.get_width() - 350, 200, 150, 70, "Medium");
	Button* b2 = EasyButton::get_instance(sys.get_width() / 4, 300, 100, 70, "Easy", game_engine, l2);
	Button* b3 = MediumButton::get_instance(sys.get_width() - 470, 300, 150, 70, "Medium", game_engine, l2);
	Button* b4 = HardButton::get_instance(sys.get_width() - 280, 300, 100, 70, "Hard", game_engine, l2);
	Button* b5 = QuitButton::get_instance(sys.get_width() - 480, 400, 150, 70, "Quit", game_engine);
	menu.push_back(b1);
	menu.push_back(l);
	menu.push_back(l2);
	menu.push_back(b2);
	menu.push_back(b3);
	menu.push_back(b4);
	menu.push_back(b5);
	
	/*RESTART MENU*/
	//If no restart menu is wanted, just comment out the lines below.
	//The restart menu can be changed and more elements can be added.
	Label* label = Label::get_instance(300, 100, 250, 70, "You died...");
	Button* button = StartButton::get_instance(300, 200, 200, 70, "Restart", game_engine);
	Label* l3 = Label::get_instance(sys.get_width() / 4, 300, 250, 70, "Difficulty: ");
	Label* l4 = Label::get_instance(sys.get_width() - 350, 300, 150, 70, "Not chosen");
	Button* b6 = EasyButton::get_instance(sys.get_width() / 4, 400, 100, 70, "Easy", game_engine, l4);
	Button* b7 = MediumButton::get_instance(sys.get_width() - 470, 400, 150, 70, "Medium", game_engine, l4);
	Button* b8 = HardButton::get_instance(sys.get_width() - 280, 400, 100, 70, "Hard", game_engine, l4);
	restart.push_back(label);
	restart.push_back(button);
	restart.push_back(l3);
	restart.push_back(l4);
	restart.push_back(b6);
	restart.push_back(b7);
	restart.push_back(b8);

	game_engine->run();
	return 0;
}

