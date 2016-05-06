#include "AllShell.h"

#ifdef DEBUG
#include <iostream>
#endif

void AllShell::newShell(Shell *shell)
{
  allShell.push_back(shell);
}
void AllShell::operate()
{
  for(auto it = allShell.begin(); it != allShell.end();)
  {
    (*it)->move();
    int tempY = (*it)->getVertex().position.y;
    if(tempY < SCREEN_MOST_TOP || tempY > SCREEN_MOST_BOTTOM)
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
}
std::vector<Shell *> &AllShell::shellVector()
{
  return std::ref(allShell);
}
