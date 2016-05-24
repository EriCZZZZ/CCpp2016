#ifndef STATUS_H
#define STATUS_H

#include "Operation.h"
#include <SFML/Graphics.hpp>
#include <string>

class Status : public Operation
{
private:
  int gameStatus;
  int score;
  sf::RenderWindow *window;

  sf::Font *font;
  sf::Text *text;

  int difficultyBase;
  std::vector<int> difficulty;
  void setDifficulty();

  void initializeStatus();
  void initializeText();

  void refreshString();
  void refreshHPfill();
  void drawStatus();
  void checkIsWinAndRefresh();
public:
  Status(sf::RenderWindow *window, int difficultyBase = 1);
  ~Status();
  void operate();
  void reviseHP(int deltaHP);
  void addScore(int deltaScore);
  void setGameStatus(bool status);
  int checkGameStatus();
  int getDifficulty(int index);
};
#endif
