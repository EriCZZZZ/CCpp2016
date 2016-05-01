#ifndef COLLISION_JUDGE_H
#define COLLISION_JUDGE_H

#include "Player.h"
#include "Enemy.h"
#include "AllShell.h"
#include "../head/GameConfig.h"

class CollisionJudge
{
private:
  Player *player;
  Enemy *enemy;
public:
  CollisionJudge(Player *player, Enemy *enemy);
  bool judge(int shellIndexX, shellIndexY);
};
#endif
