
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

  #ifdef DEBUG
  std::cout << target->getSpriteClass() << std::endl;
  #endif

  flag += player->collision(target);

  #ifdef DEBUG
  if(target->getSpriteClass() == SPRITE_WEAPON_SPREAD)
  {
    std::cout << "==============" << std::endl;
  }
  #endif
  
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
