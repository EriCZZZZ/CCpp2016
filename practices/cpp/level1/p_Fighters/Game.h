#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "./operation/Player.h"
#include "./operation/Enemy.h"
#include "./operation/AllShell.h"
#include "./operation/Status.h"
#include "./operation/CollisionJudge.h"
#include "./head/GameConfig.h"
#include <thread>
#include <vector>

class Game
{
private:
  sf::RenderWindow *window;
  Status *status;
  AllShell *allShell;
  Player *player;
  Enemy *enemy;
  CollisionJudge *collisionJudge;
  std::vector<Operation *> gameOperation;

  sf::SoundBuffer *bufferBGM;
  sf::Sound *soundBGM;
public:
  Game();
  ~Game();
  void play();
};
#endif
