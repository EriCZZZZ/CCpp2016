#include "Player.h"

#include <SFML/Audio.hpp>

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
      sf::SoundBuffer bufferDead;
      bufferDead.loadFromFile(SOUND_DEAD);
      sf::Sound soundDead;
      soundDead.setBuffer(bufferDead);
      soundDead.play();
      status->setGameStatus(GAME_STOP);
      #ifdef DEBUG
      std::cout << "Aaa~" << std::endl;
      #endif
    }
    else
    {
      //add hp
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
