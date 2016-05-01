#ifndef GAME_CONFIG_H
#define GAME_CONFIG_H

// === game status vector ===
#define ID_GAME_STATUS 0
#define ID_PLAYER 1
#define ID_ENEMY 2
#define ID_ALL_SHELL 3
#define ID_SCORE 4

#define GAME_STATUS_STOP 1
#define GAME_STATUS_GOING 0

#define GAME_STATUS_DONE 1
#define GAME_STATUS_UNDONE 0

// === class-Player config ===
#define PLAYER_LEFT sf::Keyboard::Left
#define PLAYER_RIGHT sf::Keyboard::Right
#define PLAYER_FIRE sf::Keyboard::Space
#define PLAYER_DELTA_LEFT -1
#define PLAYER_DELTA_RIGHT 1

// === collision related config ===
#define COLLISION_KNOCKED 1
#define COLLISION_UNKNOCKED 0

#define COLLISION_HP_DELTA -20
#define COLLISION_FIGHTER_DEAD 0
#define COLLISION_FIGHTER_UNDEAD 1

//The square of real-distance
#define COLLISION_KNOCK_DISTANCE 600

// === class-enemy config ===
#define ENEMY_MAX_NUMBER_FIGHTER 5

#endif
