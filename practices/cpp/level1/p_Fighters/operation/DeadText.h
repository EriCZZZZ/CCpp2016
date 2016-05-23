#ifndef DEAD_TEXT_H
#define DEAD_TEXT_H

#include "../head/GameConfig.h"
#include <SFML/Graphics.hpp>

class DeadText
{
private:
  sf::RenderWindow *window;
  sf::Font *font;
  sf::Text *text;
public:
  DeadText(sf::RenderWindow *window);
  ~DeadText();
  void showDeadInfo();
};
#endif
