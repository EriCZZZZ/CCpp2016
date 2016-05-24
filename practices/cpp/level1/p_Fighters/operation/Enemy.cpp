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
Enemy::~Enemy()
{
  delete boomBuffer;
  for(auto it = enemyFighter.begin(); it != enemyFighter.end();)
  {
    delete *it;
    enemyFighter.erase(it);
  }
  for(auto it = boomCircle.begin(); it != boomCircle.end();)
  {
    delete *it;
    boomCircle.erase(it);
  }
  for(auto it = boomSound.begin(); it != boomSound.end();)
  {
    delete *it;
    boomSound.erase(it);
  }
}
void Enemy::checkAndCreateFighter()
{
  if(enemyFighter.size() < status->getDifficulty(DIFFICULTY_INDEX_ENEMY_FIGHTER_MAX_NUMBER))
  {
    EnemyFighterFactory tempFactory;
    while(enemyFighter.size() < status->getDifficulty(DIFFICULTY_INDEX_ENEMY_FIGHTER_MAX_NUMBER))
    {
      auto temp = tempFactory.createFighter(createRandomIndex(), ENEMY_CREATE_FIGHER_ORIGIN_Y);
      enemyFighter.push_back(temp);
    }
  }
}
void Enemy::Move()
{
  for(auto it = enemyFighter.begin(); it != enemyFighter.end();)
  {
    (*it)->move(ENEMY_MOVE_DELTA_X, ENEMY_MOVE_DELTA_Y);
    int tempX = (*it)->getPositionByVertex().position.x;
    int tempY = (*it)->getPositionByVertex().position.y;

    if(tempY <= SCREEN_MOST_TOP || tempY >= SCREEN_MOST_BOTTOM)
    {
      delete *it;
      enemyFighter.erase(it);
      continue;
    }
    it++;
  }
}
void Enemy::Fire()
{
  for(auto it = enemyFighter.begin(); it != enemyFighter.end();)
  {
    if(createRandomFire() <= ENEMY_FIRE * status->getDifficulty(DIFFICULTY_INDEX_SHELL_FIRE_RATE))
    {
      shellContainer->addShell((*it)->fire(SHELL_SPEED_ENEMY_X, status->getDifficulty(DIFFICULTY_INDEX_SHELL_SPEED)));
    }
    it++;
  }
}
void Enemy::drawAllFighter()
{
  for(auto it = enemyFighter.begin(); it != enemyFighter.end();)
  {
    window->draw(*((*it)->toDraw()));
    it++;
  }
}
void Enemy::operate()
{
  checkAndCreateFighter();
  Move();
  Fire();
  drawAllFighter();
  drawBoomCircle();
}
void Enemy::fighterCollided(std::vector<Fighter *>::iterator &targetFighter)
{
  (*targetFighter)->reviseHP(COLLISION_HP_DELTA);
  if((*targetFighter)->isFighterDie() == COLLISION_FIGHTER_DEAD)
  {
    fighterDead(targetFighter);
  }
  else
  {
    targetFighter++;
  }
}
void Enemy::fighterDead(std::vector<Fighter *>::iterator &targetFighter)
{
  int enemyFighterIndexX = (*targetFighter)->getPositionByVertex().position.x;
  int enemyFighterIndexY = (*targetFighter)->getPositionByVertex().position.y;
  createBoomCircle(enemyFighterIndexX, enemyFighterIndexY);
  delete *targetFighter;
  enemyFighter.erase(targetFighter);
  status->addScore(ENEMY_ADD_SCORE);
  playBoom();
}
bool Enemy::collision(Shell *target)
{
  bool flag = COLLISION_UNKNOCKED;
  for(auto it = enemyFighter.begin(); it != enemyFighter.end();)
  {
    int enemyFighterIndexX = (*it)->getPositionByVertex().position.x;
    int enemyFighterIndexY = (*it)->getPositionByVertex().position.y;
    if(collisionJudge(target, enemyFighterIndexX, enemyFighterIndexY) == COLLISION_KNOCKED)
    {
      fighterCollided(it);
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
    delete *(boomSound.begin());
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
bool Enemy::collisionJudge(Shell *target, int x2, int y2)
{
  if(target->getOwner() != FIGHTER_OWNER_ENEMY)
  {
    int x1 = target->getPositionByVertex().position.x;
    int y1 = target->getPositionByVertex().position.y;
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
  else
  {
    return COLLISION_UNKNOCKED;
  }
}
int Enemy::createRandomIndex()
{
  srand(clock());
  return (abs(rand() % ENEMY_RANDOM_INDEX) + ENEMY_RANDOM_INDEX_BASE);
}
int Enemy::createRandomFire()
{
  srand(clock());
  return rand() % ENEMY_RANDOM_FIRE;
}
