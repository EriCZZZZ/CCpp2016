#include "Player.h"

#ifdef DEBUG
#include <iostream>
#endif

Player::Player(AllShell *shellContainer)
{
  PlayerFighterFactory *tempFactory = new PlayerFighterFactory;
  playerFighter = tempFactory->createFighter(500, 650);
  Player::shellContainer = shellContainer;
}
void Player::operate(sf::RenderWindow *window)
{
  if(sf::Keyboard::isKeyPressed(PLAYER_LEFT))
  {
    playerFighter->move(PLAYER_DELTA_LEFT, 0);
  }
  if(sf::Keyboard::isKeyPressed(PLAYER_RIGHT))
  {
    playerFighter->move(PLAYER_DELTA_RIGHT, 0);
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
      // gameStatus[ID_GAME_STATUS] = GAME_STATUS_STOP;
      #ifdef DEBUG
      std::cout << "Aaa~" << std::endl;
      #endif
    }
    else
    {
      //to show HP-decrease
      ;
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
