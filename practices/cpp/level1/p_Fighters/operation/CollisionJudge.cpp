
#include "CollisionJudge.h"
#ifdef DEBUG
#include <iostream>
#endif

CollisionJudge::CollisionJudge(Player *player, Enemy *enemy, AllShell *allShell)
{
  #ifdef DEBUG
  std::cout << player << " " << enemy << std::endl;
  #endif
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
  std::vector<Shell *> &shellContainer = allShell->shellVector();
  for(auto it = shellContainer.begin(); it != shellContainer.end();)
  {
    if(judge((*it)->getVertex().position.x, ((*it)->getVertex().position.y)) == COLLISION_KNOCKED)
    {
      delete *it;
      shellContainer.erase(it);
    }
    else
    {
      it++;
    }
  }
}
