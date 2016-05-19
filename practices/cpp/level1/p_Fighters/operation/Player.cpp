#include "Player.h"

#ifdef DEBUG
#include <iostream>
#endif

Player::Player(AllShell *shellContainer, sf::RenderWindow *window, Status *status)
{
  Player::status = status;
  Player::window = window;
  Player::shellContainer = shellContainer;

  PlayerFighterFactory *tempFactory = new PlayerFighterFactory;
  playerFighter = tempFactory->createFighter(PLAYER_CREATE_FIGHTER_X, PLAYER_CREATE_FIGHTER_Y);
  delete tempFactory;

  bufferFire = new sf::SoundBuffer;
  bufferFire->loadFromFile(SOUND_FIRE);

  bufferAttacked = new sf::SoundBuffer;
  bufferAttacked->loadFromFile(SOUND_ATTACKED);
  soundAttacked = new sf::Sound;
  soundAttacked->setBuffer(*bufferAttacked);

  bufferDead = new sf::SoundBuffer;
  bufferDead->loadFromFile(SOUND_DEAD);
  soundDead = new sf::Sound;
  soundDead->setBuffer(*bufferDead);
}
Player::~Player()
{
  delete bufferFire;
  delete bufferAttacked;
  delete soundAttacked;
  delete bufferDead;
  delete soundDead;
  deleteAllSoundFire();
}
void Player::operate()
{
  move(checkMoveAndBorder());
  if(checkFire() == SHELL_FIRE)
  {
    fire();
  }
  window->draw(*(playerFighter->toDraw()));
}

bool Player::collision(int ShellIndexX, int ShellIndexY)
{
  int fighterIndexX = playerFighter->getPositionByVertex().position.x;
  int fighterIndexY = playerFighter->getPositionByVertex().position.y;
  if(collisionJudge(ShellIndexX, ShellIndexY, fighterIndexX, fighterIndexY) == COLLISION_KNOCKED)
  {
    return knockedOperate();
  }
  else
  {
    return COLLISION_UNKNOCKED;
  }
}
bool Player::collisionJudge(int x1, int y1, int x2, int y2)
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
void Player::playFireSound()
{
  auto temp = new sf::Sound;
  temp->setBuffer(*bufferFire);
  soundFire.push_back(temp);
  temp->play();
  while(soundFire.size() > PLAYER_FIRE_MAX)
  {
    delete *(soundFire.begin());
    soundFire.erase(soundFire.begin());
  }
}
void Player::move(sf::Vertex deltaVector)
{
  playerFighter->move(deltaVector.position.x, deltaVector.position.y);
}
sf::Vertex Player::checkMoveAndBorder()
{
  int nowX = playerFighter->getPositionByVertex().position.x;
  if(sf::Keyboard::isKeyPressed(PLAYER_LEFT))
  {
    if(nowX + PLAYER_DELTA_LEFT >= SCREEN_MOST_LEFT + FIGHTER_SIZE_CORRECTED_VALUE_X)
    {
      return sf::Vector2f(PLAYER_DELTA_LEFT, PLAYER_DELTA_Y);
    }
  }
  if(sf::Keyboard::isKeyPressed(PLAYER_RIGHT))
  {
    if(nowX + PLAYER_DELTA_RIGHT <= SCREEN_MOST_RIGHT - FIGHTER_SIZE_CORRECTED_VALUE_X)
    {
      return sf::Vector2f(PLAYER_DELTA_RIGHT, PLAYER_DELTA_Y);
    }
  }
  else
  {
    return sf::Vector2f(PLAYER_DELTA_NO_MOVE, PLAYER_DELTA_Y);
  }
}

bool Player::checkFire()
{
  if(sf::Keyboard::isKeyPressed(PLAYER_FIRE))
  {
    return SHELL_FIRE;
  }
  else
  {
    return SHELL_UNFIRE;
  }
}
void Player::fire()
{
  Shell *tempShell = playerFighter->createShell(SHELL_SPEED_PLAYER_X, SHELL_SPEED_PLAYER_Y);
  shellContainer->newShell(tempShell);
  playFireSound();
}
bool Player::knockedOperate()
{
  playerFighter->reviseHP(COLLISION_HP_DELTA);
  auto isFighterDie = playerFighter->isFighterDie();
  if(isFighterDie == COLLISION_FIGHTER_DEAD)
  {
    soundDead->play();
    status->setGameStatus(GAME_STOP);
  }
  else
  {
    soundAttacked->play();
    status->addHP(COLLISION_HP_DELTA);
  }
  return COLLISION_KNOCKED;
}
void Player::deleteAllSoundFire()
{
  for(auto it = soundFire.begin(); it != soundFire.end();)
  {
    delete *it;
    soundFire.erase(it);
  }
}
