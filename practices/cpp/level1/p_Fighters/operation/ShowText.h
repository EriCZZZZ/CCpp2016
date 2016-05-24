#ifndef SHOW_TEXT_H
#define SHOW_TEXT_H

#include "../head/GameConfig.h"
#include <SFML/Graphics.hpp>
#include <string>

class ShowText
{
private:
  sf::RenderWindow *window;
  sf::Font *font;
  sf::Text *textCenter;
  sf::Text *textInfo;
public:
  ShowText(sf::RenderWindow *window);
  ~ShowText();
  void showDeadInfo();
  void showWinInfo();
  void showInfo(std::string info, int textStatus);
  void showInfo(int difficulty, int score);
};
#endif
