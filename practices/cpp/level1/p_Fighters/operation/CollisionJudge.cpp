
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
bool CollisionJudge::judge(int shellIndexX, int shellIndexY)
{
  bool flag = COLLISION_UNKNOCKED;
  flag += player->collision(shellIndexX, shellIndexY);
  flag += enemy->collision(shellIndexX, shellIndexY);
  return flag;
}
void CollisionJudge::judgeAll()
{
  for(auto it = allShell->allShell.begin(); it != allShell->allShell.end();)
  {
    if(judge((*it)->().position.x, ((*it)->getPositionByVertex().position.y)) == COLLISION_KNOCKED)
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
