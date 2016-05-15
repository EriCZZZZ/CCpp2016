#include "BeatFighter.h"
void BeatFighter::playGame()
{
  auto game = new Game(difficulty);
  while(game->play() != GAME_STOP)
  {
    delete game;
    game = new Game(++difficulty);
  }
  delete game;
}
