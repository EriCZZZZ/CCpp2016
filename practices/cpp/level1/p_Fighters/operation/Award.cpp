#include "Award.h"

#ifdef DEBUG
#include <iostream>
#endif

Award::Award(SpriteContainer *spriteContainer, sf::RenderWindow *window)
{
  Award::spriteContainer = spriteContainer;
  Award::window = window;
}
void Award::operate()
{
  if(createRandomAward() == AWARD_CREATE_AWARD)
  {
    auto newAward = new SpriteWeaponSpread;
    newAward->setPosition(createRandomIndex(), AWARD_INDEX_Y);
    spriteContainer->addSprite(newAward);
  }
}
int Award::createRandomAward()
{
  srand(clock());
  return abs(rand() % AWARD_CREATE_RATE);
}
int Award::createRandomIndex()
{
  srand(clock());
  return (abs(rand() % AWARD_RANDOM_INDEX_X));
}
