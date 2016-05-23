#ifndef SHOW_TEXT_H
#define SHOW_TEXT_H

#include "../head/GameConfig.h"
#include <SFML/Graphics.hpp>

class ShowText
{
private:
  sf::RenderWindow *window;
  sf::Font *font;
  sf::Text *text;
public:
  ShowText(sf::RenderWindow *window);
  ~ShowText();
  void showDeadInfo();
  void showWinInfo();
};
#endif
