#include "AllShell.h"
void AllShell::newShell(Shell *shell)
{
  allShell.push_back(shell);
}
void AllShell::operate(sf::RenderWindow *window)
{
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
}
std::vector<Shell *> &AllShell::shellVector()
{
  return std::ref(allShell);
}
