#include "AllShell.h"

#ifdef DEBUG
#include <iostream>
#endif

AllShell::~AllShell()
{
  for(auto it = allShell.begin(); it != allShell.end();)
  {
    delete *it;
    allShell.erase(it);
  }
}
void AllShell::newShell(Shell *shell)
{
  allShell.push_back(shell);
}
void AllShell::moveAllShell()
{
  for(auto it = allShell.begin(); it != allShell.end(); it++)
  {
    (*it)->move();
  }
}
void AllShell::checkAllShell()
{
  for(auto it = allShell.begin(); it != allShell.end();)
  {
    int tempY = (*it)->getVertex().position.y;
    if(tempY < SCREEN_MOST_TOP || tempY > SCREEN_MOST_BOTTOM)
    {
      delete *it;
      allShell.erase(it);
    }
    else
    {
      it++;
    }
  }
}
void AllShell::drawAllShell()
{
  for(auto it = allShell.begin(); it != allShell.end(); it++)
  {
    window->draw(*((*it)->toDraw()));
  }
}
void AllShell::operate()
{
  moveAllShell();
  checkAllShell();
  drawAllShell();
}
