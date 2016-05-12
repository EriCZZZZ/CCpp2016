#include "Game.h"
#include <iostream>

int main()
{
  Game *game = new Game(2);
  game->play();
  // delete game;
  return 0;
}
