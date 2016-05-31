#include "SpriteContainer.h"

#ifdef DEBUG
#include <iostream>
#endif

SpriteContainer::~SpriteContainer()
{
  for(auto it = spriteContainer.begin(); it != spriteContainer.end();)
  {
    delete *it;
    spriteContainer.erase(it);
  }
}
void SpriteContainer::addShell(Sprite *sprite)
{
  spriteContainer.push_back(sprite);
}
void SpriteContainer::moveSpriteContainer()
{
  for(auto it = spriteContainer.begin(); it != spriteContainer.end(); it++)
  {
    (*it)->move();
  }
}
void SpriteContainer::checkSpriteContainer()
{
  for(auto it = spriteContainer.begin(); it != spriteContainer.end();)
  {
    int tempY = (*it)->getPositionByVertex().position.y;
    if(tempY < SCREEN_MOST_TOP || tempY > SCREEN_MOST_BOTTOM)
    {
      delete *it;
      spriteContainer.erase(it);
    }
    else
    {
      it++;
    }
  }
}
void SpriteContainer::drawSpriteContainer()
{
  for(auto it = spriteContainer.begin(); it != spriteContainer.end(); it++)
  {
    window->draw(*((*it)->toDraw()));
  }
}
void SpriteContainer::operate()
{
  moveSpriteContainer();
  checkSpriteContainer();
  drawSpriteContainer();
}
