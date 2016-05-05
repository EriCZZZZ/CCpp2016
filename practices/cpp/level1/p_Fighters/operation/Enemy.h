#ifndef ENEMY_H
#define ENEMY_H

#include "Operation.h"
#include "../classFighter/EnemyFighterFactory.h"
#include "AllShell.h"
#include "ctime"
#include "cstdlib"

class Enemy : public Operation
{
private:
  std::vector<Fighter *> enemyFighter;
  AllShell *shellContainer;
  bool collisionJudge(int x1, int y1, int x2, int y2);
  int createRandomIndex();
  int createRandomMoveVector();
  int createRandomFire();
public:
  Enemy(AllShell *shellContainer);
  void operate(sf::RenderWindow *window);
  bool collision(int ShellIndexX, int ShellIndexY);
};
#endif
