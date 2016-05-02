#include "AllShell.h"
void AllShell::newShell(Shell *shell)
{
  allShell.push_back(shell);
}
void AllShell::operate(sf::RenderWindow *window, std::mutex *mt)
{
  while(gameStatus[ID_GAME_STATUS] == GAME_STATUS_GOING)
  {
    while(1)
    {
      mt->lock();
      if(gameStatus[ID_ALL_SHELL] == GAME_STATUS_DONE)
      {
        mt->unlock();
        continue;
      }
      else
      {
        break;
      }
    }
    for(auto it = allShell.begin(); it != allShell.end();)
    {
      (*it)->move();
      int tempY = (*it)->getVertex().position.y;
      if(tempY < 0 || tempY > 720)
      {
        delete *it;
        allShell.erase(it);
      }
      else
      {
        window->draw(*((*it)->toDraw()));
        it++;
      }
    }
    gameStatus[ID_ALL_SHELL] = GAME_STATUS_DONE;
    mt->unlock();
  }
}
std::vector<Shell *> &AllShell::shellVector()
{
  return std::ref(allShell);
}
