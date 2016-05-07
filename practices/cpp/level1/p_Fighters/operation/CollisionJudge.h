#ifndef COLLISION_JUDGE_H
#define COLLISION_JUDGE_H

#include "Player.h"
#include "Enemy.h"
#include "AllShell.h"
#include "Status.h"
#include "../head/GameConfig.h"

class CollisionJudge
{
private:
  Player *player;
  Enemy *enemy;
  AllShell *allShell;
  bool judge(int shellIndexX, int shellIndexY);
public:
  CollisionJudge(Player *player, Enemy *enemy, AllShell *allShell);
  void judgeAll();
};
#endif
