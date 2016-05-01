include "Player.h"
Player::Player(AllShell *shellContainer, std::std::vector<<int> &gameStatus;)
{
  playerFighter = PlayerFighterFactory.createFighter(500, 700);
  Player::shellContainer = shellContainer;
  Player::gameStatus = gameStatus;
}
void Player::operate(sf::RenderWindow *window, std::mutex *mt)

  while(gameStatus[ID_GAME_STATUS] == GAME_STATUS_GOING)
  {
    while(mt->try_lock())
    {
      if(gameStatus[ID_PLAYER] == GAME_STATUS_DONE)
      {
        mt->unlock();
        continue;
      }
      if(sf::Keyboard::isKeyPressed(PLAYER_LEFT))
      {
        playerFighter->move(PLAYER_DELTA_LEFT, 0);
      }
      else if(sf::Keyboard::isKeyPressed(PLAYER_RIGHT))
      {
        playerFighter->move(PLAYER_DELTA_RIGHT);
      }
      else if(sf::Keyboard::isKeyPressed(PLAYER_FIRE))
      {
        auto tempShell = playerFighter->createShell();
        shellContainer->newShell(tempShell);
      }
      else
      {
        ;
      }
      window->draw(*(palyerFighter->toDraw()))
      gameStatus[ID_PLAYER] == GAME_STATUS_DONE;
      mt->unlock();
    }
  }
}
bool Player::collision(int ShellIndexX, int ShellIndexY)
{
  int fighterIndexX = playerFighter->getVertex().position.x;
  int fighterIndexY = playerFighter->getVertex().position.y;
  if(collisionJudge(ShellIndexX, ShellIndexY, fighterIndexX, fighterIndexY) == COLLISION_KNOCKED)
  {
    if(playerFighter->reviseHP(COLLISION_HP_DELTA) == COLLISION_FIGHTER_DEAD)
    {
      gameStatus[ID_GAME_STATUS] = GAME_STATUS_STOP;
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
