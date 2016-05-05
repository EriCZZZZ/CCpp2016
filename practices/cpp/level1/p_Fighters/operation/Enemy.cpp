#include "Enemy.h"

#ifdef DEBUG
#include <iostream>
#include <thread>
#include <chrono>
#endif

Enemy::Enemy(AllShell *shellContainer, sf::RenderWindow *window)
{
  Enemy::shellContainer = shellContainer;
  Enemy::window = window;
  boomBuffer = new sf::SoundBuffer;
  boomBuffer->loadFromFile("./source/boom.wav");
}
void Enemy::operate()
{
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
    (*it)->move(createRandomMoveVector(), 1);
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
  drawBoomCircle();
}
bool Enemy::collision(int ShellIndexX, int ShellIndexY)
{
  bool flag = COLLISION_UNKNOCKED;
  for(auto it = enemyFighter.begin(); it != enemyFighter.end();)
  {
    int enemyFighterIndexX = (*it)->getVertex().position.x;
    int enemyFighterIndexY = (*it)->getVertex().position.y;
    if(collisionJudge(ShellIndexX, ShellIndexY, enemyFighterIndexX, enemyFighterIndexY) == COLLISION_KNOCKED)
    {
      if(((*it)->reviseHP(COLLISION_HP_DELTA)) == COLLISION_FIGHTER_DEAD)
      {
        createBoomCircle(enemyFighterIndexX, enemyFighterIndexY);
        delete *it;
        enemyFighter.erase(it);

        //play boom
        playBoom();
      }
      else
      {
        it++;
      }
      flag = COLLISION_KNOCKED;
    }
    else
    {
      it++;
    }
  }
  return flag;
}
void Enemy::playBoom()
 {
  sf::Sound *temp = new sf::Sound;
  temp->setBuffer(*boomBuffer);
  temp->play();
  boomSound.push_back(temp);
  while(boomSound.size() > 50)
  {
    boomSound.erase(boomSound.begin());
  }
}
void Enemy::createBoomCircle(int x, int y)
{
  auto tempBoom = new sf::CircleShape(10);
  tempBoom->setFillColor(sf::Color::Red);
  tempBoom->setPosition(x, y - 30);
  boomCircle.push_back(tempBoom);
}
void Enemy::drawBoomCircle()
{
  for(auto it = boomCircle.begin(); it != boomCircle.end();)
  {
    auto radius = (*it)->getRadius();
    if(radius < 50)
    {
      (*it)->setRadius(radius + 5);
      window->draw(*(*it));
      it++;
    }
    else
    {
      delete *it;
      boomCircle.erase(it);
    }
  }
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
  return rand() % 1000;
}
