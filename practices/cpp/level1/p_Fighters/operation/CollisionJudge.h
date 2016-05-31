#ifndef COLLISION_JUDGE_H
#define COLLISION_JUDGE_H

#include "Player.h"
#include "Enemy.h"
#include "SpriteContainer.h"
#include "../head/GameConfig.h"

class Player;
class Enemy;

class CollisionJudge
{
private:
  Player *player;
  Enemy *enemy;
  SpriteContainer *spriteContainer;
  bool judge(Shell *target);
public:
  CollisionJudge(Player *player, Enemy *enemy, SpriteContainer *spriteContainer);
  void judgeAll();
};
#endif
