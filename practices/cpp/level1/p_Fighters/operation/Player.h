#ifndef PLAYER_H
#define PLAYER_H

#include "Operation.h"
#include "../classFighter/PlayerFighterFactory.h"
#include "AllShell.h"
#include "../head/GameConfig.h"
#include <SFML/Audio.hpp>
#include "../Game.h"

class Game;

class Player : public Operation
{
private:
  Fighter *playerFighter;
  AllShell *shellContainer;
  sf::RenderWindow *window;
  Game *game;

  sf::SoundBuffer *bufferFire;
  sf::SoundBuffer *bufferAttacked;
  sf::SoundBuffer *bufferDead;
  std::vector<sf::Sound *> soundFire;
  sf::Sound *soundAttacked;
  sf::Sound *soundDead;

  sf::RectangleShape *HPborder;
  sf::RectangleShape *HPfill;

  void initializeHPfill();
  void initializeHPborder();
  void drawHPImage();

  void playFireSound();
  bool collisionJudge(Shell *target , int x2, int y2);

  sf::Vertex checkMoveAndBorder();
  void move(sf::Vertex deltaVector);
  bool checkFire();
  void fire();
  bool knockedOperate();
  void deleteAllSoundFire();
public:
  Player(AllShell *shellContainer, sf::RenderWindow *window, Game *game);
  ~Player();
  void operate();
  bool collision(Shell *target);
};
#endif
