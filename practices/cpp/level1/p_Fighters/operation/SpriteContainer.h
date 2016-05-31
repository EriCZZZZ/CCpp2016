#ifndef ALL_SHELL_H
#define ALL_SHELL_H

#include "Operation.h"
#include "../classSprite/Sprite.h"
#include <functional>
#include "../head/GameConfig.h"

class CollisionJudge;

class SpriteContainer : public Operation
{
  friend CollisionJudge;
private:
  std::vector<Sprite *> spriteContainer;
  sf::RenderWindow *window;

  void moveSpriteContainer();
  void checkSpriteContainer();
  void drawSpriteContainer();
public:
  SpriteContainer(sf::RenderWindow *window) : window(window) {}
  ~SpriteContainer();
  void addShell(Sprite *sprite);
  void operate();
};
#endif
