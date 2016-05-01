#include "Enemy.h"
Enemy::Enemy(AllShell *shellContainer, std::vector<int> &gameStatus)
{
  Enemy::shellContainer = shellContainer;
  Enemy::gameStatus = gameStatus;
}
void Enemy::operate(sf::RenderWindow *window, std::mutex *mt)
{
  while(mt->try_lock())
  {
    if(gameStatus[ID_ENEMY] == GAME_STATUS_DONE)
    {
      mt->unlock();
      continue;
    }
    if(enemyFighter.size() < ENEMY_MAX_NUMBER_FIGHTER)
    {
      EnemyFighterFactory tempFactory;
      while(enemyfighter.size() < ENEMY_MAX_NUMBER_FIGHTER)
      {
        enemyFighter.push_back(tempFactory.createFighter(createRAndomIndex(), 0));
      }
    }
    for(auto it = enemyFighter.begin(); it != enemyFighter.end();)
    {
      (*it)->move(createRandomMoveVector(), createRandomMoveVector());
      int tempX = (*it)->getVertex().position.x;
      int tempY = (*it)->getVertex().position.y;
      if(tempY <= 0 || tempY >= 700)
      {
        delete *it;
        enemyFighter.erase(it);
        continue;
      }
      if(tempX <= 30)
      {
        (*it)->setPosition(0, tempY);
      }
      else if(tempX >= 1050)
      {
        (*it)->setPositon(1050, tempY);
      }
      shellContainer->newShell((*it)->createShell());
      window->draw(*((*it)->toDraw()));
      it++;
    }
  }
}
bool Enemy::collision(int ShellIndexX, int ShellIndexY)
{
  bool flag = COLLISION_UNKNOCKED;
  for(auto it = enemyFighter.begin(); it != enemyFighter.end(); it++)
  {
    int enemyFighterIndexX = (*it)->getVertex().position.x;
    int enemyFighterIndexY = (*it)->getVertex().position.y;
    if(collisionJudge(ShellIndexX, ShellIndexY, enemyFighterIndexX, enemyFighterIndexY) == COLLISION_KNOCKED)
    {
      if(((*it)->reviseHP(COLLISION_HP_DELTA)) == COLLISION_FIGHTER_DEAD)
      {
        enemyFighter.erase(it);
        flag = COLLISION_KNOCKED;
        it--;
      }
      else
      {
        ;//DO NOTHING
      }
    }
  }
  return flag;
}
bool Enemy::collisionJudge(int x1, int y1, int x2, int y2)
{
  int distance = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 -y2);
  if(distance <= COLLISION_KNOCK_DISTANCE)
  {
    return COLLISION_KNOCKED;
  }
  else
  {
    return COLLISION_UNKNOCKED;
  }
}
int createRandomIndex()
{
  srand(clock());
  return (100 + (rand() % 800));
}
int createRandomMoveVector()
{
  srand(clock());
  return (-1 + (rand() % 2));
}
