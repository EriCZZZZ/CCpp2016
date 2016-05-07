#include "Enemy.h"

#ifdef DEBUG
#include <iostream>
#include <thread>
#include <chrono>
#endif

Enemy::Enemy(AllShell *shellContainer, sf::RenderWindow *window, Status *status)
{
  Enemy::status = status;
  Enemy::shellContainer = shellContainer;
  Enemy::window = window;
  boomBuffer = new sf::SoundBuffer;
  boomBuffer->loadFromFile(SOUND_BOOM);
}
void Enemy::operate()
{
  if(enemyFighter.size() < ENEMY_MAX_NUMBER_FIGHTER)
  {
    EnemyFighterFactory tempFactory;
    while(enemyFighter.size() < ENEMY_MAX_NUMBER_FIGHTER)
    {
      auto temp = tempFactory.createFighter(createRandomIndex(), ENEMY_CREATE_FIGHER_ORIGIN_Y);
      enemyFighter.push_back(temp);
    }
  }

  for(auto it = enemyFighter.begin(); it != enemyFighter.end();)
  {
    (*it)->move(ENEMY_MOVE_DELTA_X, ENEMY_MOVE_DELTA_Y);
    int tempX = (*it)->getVertex().position.x;
    int tempY = (*it)->getVertex().position.y;

    if(tempY <= SCREEN_MOST_TOP || tempY >= SCREEN_MOST_BOTTOM)
    {
      delete *it;
      enemyFighter.erase(it);
      continue;
    }
    if(tempX <= SCREEN_MOST_LEFT + FIGHTER_SIZE_CORRECTED_VALUE_X)
    {
      (*it)->setPosition(SCREEN_MOST_LEFT + FIGHTER_SIZE_CORRECTED_VALUE_X, tempY);
    }
    else if(tempX >= SCREEN_MOST_RIGHT - FIGHTER_SIZE_CORRECTED_VALUE_X)
    {
      (*it)->setPosition(SCREEN_MOST_RIGHT - FIGHTER_SIZE_CORRECTED_VALUE_X, tempY);
    }
    // ==== create shell
    if(createRandomFire() == ENEMY_FIRE)
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
        //add score
        status->addScore(ENEMY_ADD_SCORE);
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
  while(boomSound.size() > BOOM_CONTAINER_MAX)
  {
    delete *boomSound.begin();
    boomSound.erase(boomSound.begin());
  }
}
void Enemy::createBoomCircle(int x, int y)
{
  auto tempBoom = new sf::CircleShape(BOOM_SIZE_ORIGIN);
  tempBoom->setFillColor(sf::Color::Red);
  tempBoom->setPosition(x, y - FIGHTER_SIZE_CORRECTED_VALUE_Y);
  boomCircle.push_back(tempBoom);
}
void Enemy::drawBoomCircle()
{
  for(auto it = boomCircle.begin(); it != boomCircle.end();)
  {
    auto radius = (*it)->getRadius();
    if(radius < BOOM_SIZE_MAX)
    {
      (*it)->setRadius(radius + BOOM_SIZE_DELTA);
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
  return (rand() % ENEMY_RANDOM_INDEX);
  // #ifdef DEBUG
  // std::cout << rand()%800 << std::endl;
  // #endif
  // return (rand() % 800);
}
int Enemy::createRandomFire()
{
  srand(clock());
  return rand() % ENEMY_RANDOM_FIRE;
}
