
#include "CollisionJudge.h"
#ifdef DEBUG
#include <iostream>
#endif

CollisionJudge::CollisionJudge(Player *player, Enemy *enemy, SpriteContainer *spriteContainer)
{
  CollisionJudge::player = player;
  CollisionJudge::enemy = enemy;
  CollisionJudge::spriteContainer = spriteContainer;
}
bool CollisionJudge::judge(Sprite *target)
{
  bool flag = COLLISION_UNKNOCKED;
  flag += player->collision(target);
  flag += enemy->collision(target);
  return flag;
}
void CollisionJudge::judgeAll()
{
  for(auto it = spriteContainer->spriteContainer.begin(); it != spriteContainer->spriteContainer.end();)
  {
    if(judge(*it) == COLLISION_KNOCKED)
    {
      delete *it;
      spriteContainer->spriteContainer.erase(it);
    }
    else
    {
      it++;
    }
  }
}
