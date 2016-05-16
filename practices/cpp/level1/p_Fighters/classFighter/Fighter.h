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
public:
  Fighter(int x, int y);
  virtual Shell *createShell(int x, int y) = 0;
  virtual void move(int deltaX, int deltaY) = 0;
  void designAppearanceByPoint(int index, sf::Vertex targetVertex);
  void setPosition(int indexX, int indexY);
  sf::Vertex getVertex();
  FighterGraphics *toDraw();
  void reviseHP(int deltaHP);
  bool isFighterDie();
};
#endif
