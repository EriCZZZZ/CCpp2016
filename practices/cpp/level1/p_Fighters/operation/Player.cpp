#include "Player.h"

#ifdef DEBUG
#include <iostream>
#endif

Player::Player(AllShell *shellContainer, sf::RenderWindow *window, Status *status)
{
  Player::status = status;
  Player::window = window;
  PlayerFighterFactory *tempFactory = new PlayerFighterFactory;
  playerFighter = tempFactory->createFighter(PLAYER_CREATE_FIGHTER_X, PLAYER_CREATE_FIGHTER_Y);
  Player::shellContainer = shellContainer;
  delete tempFactory;

  bufferFire = new sf::SoundBuffer;
  bufferAttacked = new sf::SoundBuffer;
  bufferFire->loadFromFile(SOUND_FIRE);
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
  for(auto it = soundFire.begin(); it != soundFire.end();)
  {
    delete *it;
    soundFire.erase(it);
  }
}
void Player::operate()
{
  int tempX = playerFighter->getVertex().position.x;

  if(sf::Keyboard::isKeyPressed(PLAYER_LEFT))
  {
    if(tempX + PLAYER_DELTA_LEFT >= SCREEN_MOST_LEFT + FIGHTER_SIZE_CORRECTED_VALUE_X)
    {
      playerFighter->move(PLAYER_DELTA_LEFT, PLAYER_DELTA_Y);
    }
  }
  if(sf::Keyboard::isKeyPressed(PLAYER_RIGHT))
  {
    if(tempX + PLAYER_DELTA_RIGHT <= SCREEN_MOST_RIGHT - FIGHTER_SIZE_CORRECTED_VALUE_X)
    {
      playerFighter->move(PLAYER_DELTA_RIGHT, PLAYER_DELTA_Y);
    }
  }

  if(sf::Keyboard::isKeyPressed(PLAYER_FIRE))
  {
    auto tempShell = playerFighter->createShell();
    shellContainer->newShell(tempShell);
    playFire();
  }
  window->draw(*(playerFighter->toDraw()));
}
bool Player::collision(int ShellIndexX, int ShellIndexY)
{
  int fighterIndexX = playerFighter->getVertex().position.x;
  int fighterIndexY = playerFighter->getVertex().position.y;
  if(collisionJudge(ShellIndexX, ShellIndexY, fighterIndexX, fighterIndexY) == COLLISION_KNOCKED)
  {
    if(playerFighter->reviseHP(COLLISION_HP_DELTA) == COLLISION_FIGHTER_DEAD)
    {
      soundDead->play();
      status->setGameStatus(GAME_STOP);
      #ifdef DEBUG
      std::cout << "Aaa~" << std::endl;
      #endif
    }
    else
    {
      soundAttacked->play();
      status->addHP(COLLISION_HP_DELTA);
    }
    return COLLISION_KNOCKED;
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
void Player::playFire()
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
