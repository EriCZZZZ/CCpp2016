#ifndef DEAD_TEXT_H
#define DEAD_TEXT_H

#include "Operation.h"
#include "../head/GameConfig.h"
#include <SFML/Graphics.hpp>

class DeadText : public Operation
{
private:
  sf::RenderWindow *window;
  sf::Font *font;
  sf::Text *text;
public:
  DeadText(sf::RenderWindow *window);
  ~DeadText();
  void operate();
};
#endif
