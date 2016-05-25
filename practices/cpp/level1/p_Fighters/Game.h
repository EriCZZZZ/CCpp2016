#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "./operation/Player.h"
#include "./operation/Enemy.h"
#include "./operation/AllShell.h"
#include "./operation/Status.h"
#include "./operation/CollisionJudge.h"
#include "./operation/ShowText.h"
#include "./head/GameConfig.h"
#include <thread>
#include <vector>

class Player;
class Game;

class Game
{
private:
  sf::RenderWindow *window;

  int difficulty;
  int score = 0;
  int gameStatus;
  std::vector<int> difficultyContainer;

  ShowText *showText;
  Status *status;
  AllShell *allShell;
  Player *player;
  Enemy *enemy;
  CollisionJudge *collisionJudge;
  std::vector<Operation *> gameOperation;

  sf::SoundBuffer *bufferBGM;
  sf::Sound *soundBGM;

  void initializateItem(int difficulty);
  void initializateSound();
  void initializeInfo();
  void initializeDifficulty();
  void checkScore();
public:
  Game(int difficulty);
  ~Game();
  int play();
  void addScore(int deltaScore);
  void setGameStatus(int gameStatus);
  int getDifficulty(int index);
};
#endif
