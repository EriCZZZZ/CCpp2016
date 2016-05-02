#include "Enemy.h"

#ifdef DEBUG
#include <iostream>
#endif

Enemy::Enemy(AllShell *shellContainer, std::vector<int> &gameStatus) : gameStatus(gameStatus)
{
  Enemy::shellContainer = shellContainer;
}
void Enemy::operate(sf::RenderWindow *window, std::mutex *mt)
{
  while(gameStatus[ID_GAME_STATUS] == GAME_STATUS_GOING)
  {
    while(1)
    {
      #ifdef DEBUG
      std::cout << "========enemy==========" << std::endl;
      #endif
      mt->lock();
      if(gameStatus[ID_ENEMY] == GAME_STATUS_DONE)
      {
        mt->unlock();
        continue;
      }
      else
      {
        break;
      }
    }
    if(enemyFighter.size() < ENEMY_MAX_NUMBER_FIGHTER)
    {
      EnemyFighterFactory tempFactory;
      while(enemyFighter.size() < ENEMY_MAX_NUMBER_FIGHTER)
      {
        auto temp = tempFactory.createFighter(createRandomIndex(), 50);
        enemyFighter.push_back(temp);
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
        (*it)->setPosition(1050, tempY);
      }
      // ==== create shell
      if(createRandomFire() == 50)
        shellContainer->newShell((*it)->createShell());
      window->draw(*((*it)->toDraw()));
      it++;
    }
    gameStatus[ID_ENEMY] = GAME_STATUS_DONE;
    mt->unlock();
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
        delete *it;
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
int Enemy::createRandomIndex()
{
  srand(clock());
  return (300 + (rand() % 1000));
}
int Enemy::createRandomMoveVector()
{
  srand(clock());
  return (-2 + (rand() % 5));
}
int Enemy::createRandomFire()
{
  srand(clock());
  return rand() % 100;
}
