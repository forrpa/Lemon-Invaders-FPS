# Lemon-Invaders-FPS
You play as a cat and your mission is to shoot evil lemons with hair balls to stay alive.

INSTALL GAME

Download necessary images and sounds (or make your own).

Background music: "bg_music.wav"
Shoot sound: "meow.wav"
Player image: "cat.png"
Enemy image: "lemon2.png"
Bullet: "fluffball.png"
Background image: "bg.bmp"
Open "Main.cpp".

There are six paths to change so that they lead to the necessary images and sounds. Per default the paths are "C:/images/" or "C:/sounds/", but if they are located elsewhere on your computer just replace the path to where they are located.

For example: const char* path_to_background = "c:/images/bg.bmp"; change to -> const char* path_to_background = "";

The paths that can be changed and the corresponding filename of the image or sound: path_to_background(bg.bmp), path_to_player(cat.png), path_to_bullet(fluffball.png), path_to_enemy(lemon2.png), path_to_bg_music(bg_music.wav) and path_to_shoot_sound(meow.wav).

Save the file "Main.cpp" (if you changed the paths).

Run the file "Main.cpp".

HOW TO PLAY

Move left with A or left arrow and move right with D or right arrow.
Shoot with SPACE.
Don't make the enemies touch the ground or the player. Otherwise the player dies.
STARTING THE GAME

In the main menu the player can start a new game or quit by clicking their buttons. When starting a new game the player can choose a difficulty: Easy, Medium or Hard. Medium is the default chosen difficulty, but if the player click on another difficulty it will change to that.

Easy difficulty: Enemies have the slowest speed, they generate slower and the max generate-speed is the lowest.

Medium difficulty: In between easy and hard.

Hard difficulty: Hard difficulty with the fastest speed on enemies, they generate faster and the max generate-speed is very fast.

INSTRUCTIONS TO CREATE A GAME / OVERRIDE DEFAULT SPRITES

Player, Bullet, Enemy and difficulty can be changed in Main.cpp by replacing variables in game_engine = GameEngine::get_instance();

Override player: Replace the first nullptr to player, and change the values under /PLAYER/

Override bullet: Replace the second nullptr to bullet, and change the values under /BULLET/

Override enemy: Replace the third nullptr to enemy, and change the values under /ENEMY/

Override difficulty: Replace vector() with difficulty_settings and change the values under /SET DIFFICULTY/

Change name of the game: Enter System.cpp and replace "Lemon invaders"

Change screen size: Enter System.h and change width and height

Change menu and/or restart menu: Remove, modify or add buttons, labels or own class of Sprite in Main.cpp under /MENU/ and /RESTART MENU/. Menu sprites is added with menu.push_back(Sprite*) and restart menu sprites is added with restart.push_back(Sprite*). Comment out menu and/or restart menu code lines in Main.cpp for starting game without menu and/or restart menu.

Comments:

This game engine supports games where there is one player that shoots at a number of enemies of the same type with at least three difficulty levels.

Constraints: The enemies can only appear at a random x-coordinate and move downwards, and the bullets can only be shot from the players x-coordinate and move upwards. There can't be more than one player and there can be only one type of enemy. The player can only move left and right within the screens width.

The game itself is in Main.cpp and the rest of the classes is the game engine.

If the player dies you can start a new game (restart) with a new chosen difficulty. If not chosen it will be the same as previous game.

The game will run with default Player, Bullet, Enemy and difficulty settings if they are not overritten in Main.cpp. See instructions above.
