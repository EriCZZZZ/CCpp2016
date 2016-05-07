#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Audio.hpp>

#include "Operation.h"
#include "../classFighter/EnemyFighterFactory.h"
#include "../head/GameConfig.h"
#include "AllShell.h"
#include "Status.h"
#include "ctime"
#include "cstdlib"

class Enemy : public Operation
{
private:
  sf::RenderWindow *window;
  AllShell *shellContainer;
  Status *status;
  std::vector<Fighter *> enemyFighter;
  std::vector<sf::CircleShape *> boomCircle;
  sf::SoundBuffer *boomBuffer;
  std::vector<sf::Sound *> boomSound;
  void playBoom();
  void createBoomCircle(int x, int y);
  void drawBoomCircle();
  bool collisionJudge(int x1, int y1, int x2, int y2);
  int createRandomIndex();
  int createRandomMoveVector();
  int createRandomFire();
public:
  Enemy(AllShell *shellContainer, sf::RenderWindow *window, Status *status);
  ~Enemy();
  void operate();
  bool collision(int ShellIndexX, int ShellIndexY);
};
#endif
