#ifndef AWARD_H
#define AWARD_H

#include "Operation.h"
#include "SpriteContainer.h"
#include "../classSprite/SpriteWeaponSpread.h"
#include <ctime>
#include <cstdlib>

class Award : public Operation
{
private:
  SpriteContainer *spriteContainer;
  sf::RenderWindow *window;
  int createRandomAward();
  int createRandomIndex();
public:
  Award(SpriteContainer *spriteContainer, sf::RenderWindow *window);
  void operate();
};
#endif
