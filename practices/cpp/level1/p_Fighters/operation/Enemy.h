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
  std::vector<EnemyFighter *> enemyFighter;
  Allshell *shellContainer;
  std::vector<int> &gameStatus;
  bool collisionJudge(int x1, int y1, int x2, int y2);
  int createRandomIndex();
  int createRandomMoveVector();
public:
  Enemy(AllShell *shellContainer, std::vector<int> &gameStatus);
  void operate(sf::RenderWindow *window, std::mutex *mt);
  bool collision(int ShellIndexX, int ShellIndexY);
};
#endif
