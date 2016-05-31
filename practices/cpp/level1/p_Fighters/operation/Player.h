#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Audio.hpp>
#include "Operation.h"
#include "SpriteContainer.h"
#include "../classFighter/PlayerFighterFactory.h"
#include "../head/GameConfig.h"
#include "../Game.h"

class Game;

class Player : public Operation
{
private:
  Fighter *playerFighter;
  SpriteContainer *shellContainer;
  sf::RenderWindow *window;
  Game *game;

  // sf::SoundBuffer *bufferFire;
  // sf::SoundBuffer *bufferAttacked;
  // sf::SoundBuffer *bufferDead;
  // std::vector<sf::Sound *> soundFire;
  // sf::Sound *soundAttacked;
  // sf::Sound *soundDead;
  PlaySound *playSound;

  sf::RectangleShape *HPborder;
  sf::RectangleShape *HPfill;

  void initializeHPfill();
  void initializeHPborder();
  void drawHPImage();

  // void playFireSound();
  bool collisionJudge(Shell *target , int x2, int y2);

  sf::Vertex checkMoveAndBorder();
  void move(sf::Vertex deltaVector);
  bool checkFireAndRefreshShell();
  void fire();
  bool knockedOperate();
  // void deleteAllSoundFire();
  void checkAndChangeWeapon();
public:
  Player(SpriteContainer *shellContainer, sf::RenderWindow *window, Game *game, PlaySound *playSound);
  ~Player();
  void operate();
  bool collision(Shell *target);
};
#endif
