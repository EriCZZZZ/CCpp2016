#ifndef PLAYER_H
#define PLAYER_H

#include "Operation.h"
#include "../classFighter/PlayerFighterFactory.h"
#include "AllShell.h"
#include "../head/GameConfig.h"
#include "Status.h"

class Player : public Operation
{
private:
  Fighter *playerFighter;
  AllShell *shellContainer;
  Status *status;
  sf::RenderWindow *window;
  bool collisionJudge(int x1, int y1, int x2, int y2);
public:
  Player(AllShell *shellContainer, sf::RenderWindow *window, Status *status);
  void operate();
  bool collision(int ShellIndexX, int ShellIndexY);
};
#endif
