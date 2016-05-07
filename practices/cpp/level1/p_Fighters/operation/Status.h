#ifndef STATUS_H
#define STATUS_H

#include "Operation.h"
#include <SFML/Graphics.hpp>
#include <string>

class Status : public Operation
{
private:
  bool gameStatus;
  int score;
  int HP;
  sf::RenderWindow *window;
  sf::RectangleShape *HPborder;
  sf::RectangleShape *HPfill;
  sf::Font *font;
  sf::Text *text;
public:
  Status(sf::RenderWindow *window);
  ~Status();
  void operate();
  void addHP(int deltaHP);
  void addScore(int deltaScore);
  void setGameStatus(bool status);
  bool checkGameStatus();
};
#endif