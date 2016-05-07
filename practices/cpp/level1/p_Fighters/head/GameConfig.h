#ifndef GAME_CONFIG_H
#define GAME_CONFIG_H
// === screen size ===
#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 720

#define SCREEN_MOST_LEFT 0
#define SCREEN_MOST_RIGHT SCREEN_WIDTH
#define SCREEN_MOST_TOP 0
#define SCREEN_MOST_BOTTOM SCREEN_HEIGHT

#define SCREEN_COLOR_BACKGROUND sf::Color::Black

// === fighter ===
#define FIGHTER_COORDINATE_NUMBER 4
#define FIGHTER_COORDINATE_INDEX_MAX 3
#define FIGHTER_COORDINATE_INDEX_MIN 0
#define FIGHTER_COORDINATE_1_X 30
#define FIGHTER_COORDINATE_1_Y 50
#define FIGHTER_COORDINATE_2_X 0
#define FIGHTER_COORDINATE_2_Y 60
#define FIGHTER_COORDINATE_3_X 30
#define FIGHTER_COORDINATE_3_Y 0
#define FIGHTER_COORDINATE_4_Y 60
#define FIGHTER_COORDINATE_4_X 60

#define FIGHTER_COORDINATE_ORIGIN_X 30
#define FIGHTER_COORDINATE_ORIGIN_Y 30

#define FIGHTER_ENEMY 1
#define FIGHTER_PLAYER 0

#define FIGHTER_HP_MAX 100
#define FIGHTER_HP_MIN 0

#define FIGHTER_CREATE_SHELL_CORRECTED_VALUE_PLAYER_Y -30
#define FIGHTER_CREATE_SHELL_CORRECTED_VALUE_ENEMY_Y 30

#define FIGHTER_SIZE_CORRECTED_VALUE_X 30
#define FIGHTER_SIZE_CORRECTED_VALUE_Y 30

#define FIGHTER_PLAYER_FILL_COLOR sf::Color::Magenta
#define FIGHTER_PLAYER_OUTLINE_COLOR sf::Color::Red

#define FIGHTER_ENEMY_ROTATION 180

#define FIGHTER_PLAYER_MOVE_DELTA_Y 0
#define FIGHTER_ENEMY_MOVE_X_DELTA_Y 0

// === shell ===
#define SHELL_CIRCLE_RADIUS 5
#define SHELL_FILL_COLOR Red
#define SHELL_ORIGIN_COORDINATE_X SHELL_CIRCLE_RADIUS
#define SHELL_ORIGIN_COORDINATE_Y SHELL_CIRCLE_RADIUS

#define SHELL_SPEED_PLAYER_X 0
#define SHELL_SPEED_PLAYER_Y -3
#define SHELL_SPEED_ENEMY_X 0
#define SHELL_SPEED_ENEMY_Y 3

// === Player ===
#define PLAYER_LEFT sf::Keyboard::Left
#define PLAYER_RIGHT sf::Keyboard::Right
#define PLAYER_FIRE sf::Keyboard::Space
#define PLAYER_DELTA_LEFT -1
#define PLAYER_DELTA_RIGHT 1
#define PLAYER_DELTA_Y 0

#define PLAYER_CREATE_FIGHTER_X SCREEN_WIDTH / 2
#define PLAYER_CREATE_FIGHTER_Y SCREEN_HEIGHT - FIGHTER_SIZE_CORRECTED_VALUE_Y

// === Enemy ===
#define ENEMY_MAX_NUMBER_FIGHTER 5
#define ENEMY_CREATE_FIGHER_ORIGIN_Y 50

#define ENEMY_MOVE_DELTA_X 0
#define ENEMY_MOVE_DELTA_Y 1

#define ENEMY_FIRE 1

#define ENEMY_RANDOM_INDEX 1080
#define ENEMY_RANDOM_FIRE 1000

#define ENEMY_ADD_SCORE 10

// === BOOM ===
#define BOOM_SIZE_MAX 50
#define BOOM_SIZE_ORIGIN 10
#define BOOM_SIZE_DELTA 5

#define BOOM_CONTAINER_MAX 50
// === collision related config ===
#define COLLISION_KNOCKED 1
#define COLLISION_UNKNOCKED 0

#define COLLISION_HP_DELTA -10
#define COLLISION_FIGHTER_DEAD 0
#define COLLISION_FIGHTER_UNDEAD 1

#define COLLISION_KNOCK_DISTANCE 600


// === interval ===
#define INTERVAL_MAIN 5000

// === sound location ===
#define SOUND_BGM "./source/BGM.wav"
#define SOUND_FIRE "./source/fire.wav"
#define SOUND_BOOM "./source/boom.wav"
#define SOUND_DEAD "./source/dead.wav"

// === font location ===
#define FONT_PATH "./source/font.ttf"
#define FONT_SIZE 24
#define FONT_COLOR sf::Color::White

// === game status ===
#define GAME_GOING 1
#define GAME_STOP 0

#define GAME_FONT_INDEX_PERCENT_X 0.03
#define GAME_FONT_INDEX_PERCENT_Y 0.9

#define GAME_HP_LENGTH 50
#define GAME_HP_WIDTH 25
#define GAME_HP_INDEX_PERCENT_X 0.2
#define GAME_HP_INDEX_PERCENT_Y 0.9
#define GAME_HP_FILL_FILL_COLOR FONT_COLOR
#define GAME_HP_BORDER_FILL_COLOR SCREEN_COLOR_BACKGROUND
#define GAME_HP_BORDER_BORDER_COLOR FONT_COLOR
#define GAME_HP_BORDER_OUTLINE_THICKNESS 1

#endif
