#ifndef PLAYER_H
#define PLAYER_H

#include "Operation.h"
#include "../classFighter/PlayerFighterFactory.h"
#include "AllShell.h"

class Player : public Operation
{
private:
  Fighter *playerFighter;
  AllShell *shellContainer;
  bool collisionJudge(int x1, int y1, int x2, int y2);
public:
  Player(AllShell *shellContainer);
  void operate(sf::RenderWindow *window);
  bool collision(int ShellIndexX, int ShellIndexY);
};
#endif
