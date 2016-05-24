
#include "CollisionJudge.h"
#ifdef DEBUG
#include <iostream>
#endif

CollisionJudge::CollisionJudge(Player *player, Enemy *enemy, AllShell *allShell)
{
  CollisionJudge::player = player;
  CollisionJudge::enemy = enemy;
  CollisionJudge::allShell = allShell;
}
bool CollisionJudge::judge(Shell *target)
{
  bool flag = COLLISION_UNKNOCKED;
  flag += player->collision(target);
  flag += enemy->collision(target);
  return flag;
}
void CollisionJudge::judgeAll()
{
  for(auto it = allShell->allShell.begin(); it != allShell->allShell.end();)
  {
    if(judge(*it) == COLLISION_KNOCKED)
    {
      delete *it;
      allShell->allShell.erase(it);
    }
    else
    {
      it++;
    }
  }
}
