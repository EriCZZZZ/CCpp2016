#ifndef PLAYER_H
#define PLAYER_H

#include "Operation.h"
#include "../classFighter/PlayerFighterFactory.h"
#include "AllShell.h"

class Player : public Operation
{
private:
  PlayerFighter *playerFighter;
  Allshell *shellContainer;
  std::vector<int> &gameStatus;
  bool collisionJudge(int x1, int y1, int x2, int y2);
public:
  Player(AllShell *shellContainer, std::vector<int> &gameStatus);
  void operate(sf::RenderWindow *window, std::mutex *mt);
  bool collision(int ShellIndexX, int ShellIndexY);
};
#endif
