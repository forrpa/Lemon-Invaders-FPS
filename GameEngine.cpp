//Jennifer McCarthy, jemc7787

#include "GameEngine.h"
#include "System.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "StartButton.h"
#include "QuitButton.h"
#include "EasyButton.h"
#include "MediumButton.h"
#include "HardButton.h"
#include <SDL.h>
#include <SDL_image.h>
#include <time.h>
#include <iostream>
#define FPS 60;

GameEngine* GameEngine::get_instance(const char* bg, const char* enemy, const char* player_img, const char* bullet, const char* sound, const char* bgmusic, Player* player, Bullet* b, Enemy* e, std::vector<int> diffs, std::vector<Sprite*> &menu, std::vector<Sprite*> &restart) {
	return new GameEngine(bg, enemy, player_img, bullet, sound, bgmusic, player, b, e, diffs, menu, restart);
}

void GameEngine::set_difficulty(int d) {
	difficulty = d;
}

int GameEngine::get_difficulty() {
	return difficulty;
}

std::string GameEngine::get_difficulty_name(int diff) {
	if (diff == 1) {
		return "Easy";
	} else if (diff == 2) {
		return "Medium";
	} else if (diff == 3) {
		return "Hard";
	} else {
		return std::to_string(diff);
	}
}

GameEngine::GameEngine(const char* bg, const char* enemy_img, const char* player_img, const char* bullet_img, const char* sound, const char* bgmusic, Player* p, Bullet* b, Enemy* e, std::vector<int> diffs, std::vector<Sprite*> &men, std::vector<Sprite*> &rest):difficulty(2), path_to_enemy(enemy_img), path_to_player(player_img), path_to_bullet(bullet_img), path_to_sound(sound), menu(men), restart(rest){
	SDL_Surface* bg_surface = SDL_LoadBMP(bg);
	texture = SDL_CreateTextureFromSurface(sys.get_renderer(), bg_surface);
	SDL_FreeSurface(bg_surface);
	srand((unsigned int)time(0));
	Mix_OpenAudio(20050, AUDIO_S16SYS, 2, 4096);
	music = Mix_LoadWAV(bgmusic);
	Mix_Volume(-1, 20);
	Mix_PlayChannel(-1, music, -1);

	if (p != nullptr) {
		player = p;
	}
	else {
		player = Player::get_instance((sys.get_width() - 100) / 2, sys.get_height() - 130, 100, 130, path_to_player, path_to_sound, 60); //default-spelare
	}

	if (b != nullptr) {
		bullet = b;
	}
	else {
		bullet = Bullet::get_instance(player->get_rectangle().x, 500, 30, 30, path_to_bullet, 20); //default-bullet
	}

	if (e != nullptr) {
		enemy = e;
	}
	else {
		int random = rand() % 720;
		std::vector<int> e_speed{ 1,2,3 };
		enemy = Enemy::get_instance(random, 0, 71, 102, path_to_enemy, 1000, e_speed); //default enemy
	}

	if (diffs.empty()) {
		std::vector<int> default_settings{ 5,30,500, 10,20,300, 15,10,200 }; //default difficulty settings
		difficulty_settings = default_settings;
	}
	else {
		difficulty_settings = diffs;
	}
}

void GameEngine::add(Sprite* sprite) {
	added.push_back(sprite);
}

void GameEngine::remove(Sprite* sprite) {
	removed.push_back(sprite);
}

void GameEngine::generate_enemies(int counter, int speed, int enemy_kill_count) {

	if (enemy_kill_count < enemy->get_num_of_enemies()) {
		if (counter % speed == 0) {
			int random = rand() % (sys.get_width() - enemy->get_rectangle().w);
			Enemy* enemy2 = Enemy::get_instance(random, enemy->get_rectangle().y, enemy->get_rectangle().w, enemy->get_rectangle().h, path_to_enemy, enemy->get_num_of_enemies(), enemy->get_speed());
			add(enemy2);
			enemies.push_back(enemy2);
		}
	}
}

void GameEngine::play() { 
	sprites.clear();
	player->set_rectangle_x(player->get_start_pos()); //For restarting a new game
	add(player);

	bool quit = false;
	bool dead = false;
	int counter = 0;
	int enemy_kill_count = 0;
	int speed = 200;
	Uint32 tick_interval = 1000 / FPS;
	while (!quit) {
		Uint32 next_tick = SDL_GetTicks() + tick_interval; 	
		if (!dead) {
			generate_enemies(counter, speed, enemy_kill_count);
		}
		SDL_Event event;
		while (SDL_PollEvent(&event)) { 
			switch (event.type) {
			case SDL_QUIT: exit(0); break;
			case SDL_MOUSEBUTTONDOWN:
				for (Sprite* sprite : sprites)
					sprite->mouse_down(event);
				break;
			case SDL_MOUSEBUTTONUP:
				for (Sprite* sprite : sprites)
					sprite->mouse_up(event);
				break;
			case SDL_KEYDOWN:
				for (Sprite* sprite : sprites)
					sprite->key_down(event);
				if (event.key.keysym.sym == SDLK_SPACE) {
					if (!dead) {
						Bullet* bullet2 = Bullet::get_instance(player->get_rectangle().x, bullet->get_launch_y(), bullet->get_rectangle().w, bullet->get_rectangle().h, path_to_bullet, bullet->get_speed()); 
						add(bullet2);
						bullets.push_back(bullet2);
					}
				}
				break;
			case SDL_KEYUP:
				for (Sprite* sprite : sprites)
					sprite->key_up(event);
				break;
			} 
		}

		for (Sprite* sprite : sprites) {
			sprite->tick(this); 
		}

		for (Sprite* sprite : added) {
			sprites.push_back(sprite);
		}
		added.clear();

		//Döda monster
		for (Sprite* b : bullets) {
			for (Sprite* e : enemies) {
				if (SDL_HasIntersection(&(b->get_rectangle()), &(e->get_rectangle()))) {
					remove(e);
					remove(b);
					enemy_kill_count++;
				}
			}
		}

		//Om Spelaren dör
		for (Sprite* sprite : enemies) {
			if (SDL_HasIntersection(&(sprite->get_rectangle()), &(player->get_rectangle())) || sprite->get_rectangle().y >= (sys.get_height() - enemy->get_rectangle().h)){
				enemies.clear();
				bullets.clear();
				sprites.clear();
				dead = true;
				if (!restart.empty()) {
					restart_menu();
				}
			}
		}

		for (Sprite* sprite : removed) {
			for (std::vector<Sprite*>::iterator iterator = sprites.begin(); iterator != sprites.end(); ) {
				if (*iterator == sprite) {
					iterator = sprites.erase(iterator);
				}
				else {
					iterator++;
				}
			}

			for (std::vector<Sprite*>::iterator iter = bullets.begin(); iter != bullets.end(); ) {
				if (*iter == sprite) {
					iter = bullets.erase(iter);
				}
				else {
					iter++;
				}
			}

			for (std::vector<Sprite*>::iterator iter = enemies.begin(); iter != enemies.end(); ) {
				if (*iter == sprite) {
					iter = enemies.erase(iter);
				}
				else {
					iter++;
				}
			}
		}
		removed.clear();

		SDL_RenderClear(sys.get_renderer());
		SDL_RenderCopy(sys.get_renderer(), texture, NULL, NULL);
		for (Sprite* sprite : sprites) {
			sprite->draw(); 
		}
		SDL_RenderPresent(sys.get_renderer()); 

		int delay = next_tick - SDL_GetTicks();
		if (delay > 0) {
			SDL_Delay(delay);
		}

		counter++;
		if (difficulty == 1) {
			if (counter % difficulty_settings[2] == 0) {
				if (speed == difficulty_settings[1])
					speed = difficulty_settings[1];
				else
					speed -= difficulty_settings[0];
			}
		}
		else if (difficulty == 2) {
			if (counter % difficulty_settings[5] == 0) {
				if (speed == difficulty_settings[4])
					speed = difficulty_settings[4];
				else
					speed -= difficulty_settings[3];
			}
		}
		else if (difficulty == 3) {
			if (counter % difficulty_settings[8] == 0) {
				if (speed == difficulty_settings[7])
					speed = difficulty_settings[7];
				else
					speed -= difficulty_settings[6];
			}
		}
	} 
}

void GameEngine::restart_menu() {
	
	bool quit = false;
	while (!quit) {

		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_MOUSEBUTTONDOWN:
				for (Sprite* sprite : restart)
					sprite->mouse_down(event);
				break;
			case SDL_MOUSEBUTTONUP:
				for (Sprite* sprite : restart)
					sprite->mouse_up(event);
				break;
			case SDL_QUIT:
				exit(0);
				break;
			}
		}

		SDL_RenderClear(sys.get_renderer());
		SDL_RenderCopy(sys.get_renderer(), texture, NULL, NULL);
		for (Sprite* sprite : restart) {
			sprite->draw();
		}
		SDL_RenderPresent(sys.get_renderer());
	}
	
}

void GameEngine::run() {

	if (menu.empty()) {
		play();
	}
	else {
		bool quit = false;
		while (!quit) {

			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_MOUSEBUTTONDOWN:
					for (Sprite* sprite : menu)
						sprite->mouse_down(event);
					break;
				case SDL_MOUSEBUTTONUP:
					for (Sprite* sprite : menu)
						sprite->mouse_up(event);
					break;
				case SDL_QUIT:
					quit = true;
					break;
				}
			}
			SDL_RenderClear(sys.get_renderer());
			SDL_RenderCopy(sys.get_renderer(), texture, NULL, NULL);
			for (Sprite* sprite : menu) {
				sprite->draw();
			}
			SDL_RenderPresent(sys.get_renderer());
		}
	}
}

GameEngine::~GameEngine() {
	menu.clear();
	restart.clear();
	Mix_FreeChunk(music);
	Mix_CloseAudio();
	SDL_DestroyTexture(texture);
}
