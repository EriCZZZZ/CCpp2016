#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Audio.hpp>

#include "Operation.h"
#include "../classFighter/EnemyFighterFactory.h"
#include "../head/GameConfig.h"
#include "AllShell.h"
#include "ctime"
#include "cstdlib"
#include "../Game.h"

class Game;

class Enemy : public Operation
{
private:
  sf::RenderWindow *window;
  Game *game;
  PlaySound *playSound;
  AllShell *shellContainer;
  std::vector<Fighter *> enemyFighter;
  std::vector<sf::CircleShape *> boomCircle;

  static int createFighterTimeCount;

  void createBoomCircle(int x, int y);
  void drawBoomCircle();

  bool collisionJudge(Shell *target, int fighterX, int fighterY);
  void fighterCollided(std::vector<Fighter *>::iterator &targetFighter);
  void fighterDead(std::vector<Fighter *>::iterator &targetFighter);

  int createRandomIndex();
  int createRandomMoveVector();
  int createRandomFire();

  void checkAndCreateFighter();
  void Move();
  void Fire();
  void drawAllFighter();
public:
  Enemy(AllShell *shellContainer, sf::RenderWindow *window, Game *game, PlaySound *playSound);
  ~Enemy();
  void operate();
  bool collision(Shell *target);
};
#endif
