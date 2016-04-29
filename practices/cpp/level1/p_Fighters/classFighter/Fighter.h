#ifndef FIGHTER_H
#define FIGHTER_H

#include "../head/FighterGlobalConfig.h"
#include "../classGraphics/FighterGraphics.h"
#include "../classShell/Shell.h"

class Fighter : public FighterOperation
{
private:
  bool fighterOwner;
  unsigned HP;
  // bool isShellReady;
  FighterGraphics fighterGraphics;
public:
  virtual Shell *createShell() = 0;
  virtual void move(int deltaX, int deltaY) = 0;
  void setPoint(int index, sf::Vertex targetVertex);
  void setPostion(int indesX, int indexY);
  sf::Vertex getVertex();
  FighterGraphics *toDraw();
  reviseHP(int deltaHP);
};
#endif
