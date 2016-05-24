#ifndef FIGHTER_H
#define FIGHTER_H

#include "../head/GameConfig.h"
#include "../classGraphics/FighterGraphics.h"
#include "../classShell/Shell.h"

class Fighter
{
protected:
  bool fighterOwner;
  unsigned HP;
  FighterGraphics fighterGraphics;
private:
  void setPosition(int indexX, int indexY);
public:
  Fighter(int x, int y);
  virtual Shell *fire(int x, int y) = 0;
  virtual void move(int deltaX, int deltaY) = 0;
  sf::Vertex getPositionByVertex();
  FighterGraphics *toDraw();
  void reviseHP(int deltaHP);
  unsigned getHP(void);
  bool isFighterDie();
};
#endif
