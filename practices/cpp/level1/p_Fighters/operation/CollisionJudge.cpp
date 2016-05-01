#include "CollisionJudge.h"

CollisionJudge::CollisionJudge(Player *player, Enemy *enmey)
{
  CollisionJudge::player = player;
  CollisionJudge::enemy = enemy;
}
bool CollisionJudge::judge(int shellIndexX, int shellIndexY)
{
  bool flag = COLLISION_UNKNOCKED;
  flag += player->collision(shellIndexX, shellIndexY);
  flag += enemy->collision(shellIndexX, shellIndexY);
  return flag;
}
