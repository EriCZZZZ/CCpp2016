#include "ShowText.h"
ShowText::ShowText(sf::RenderWindow *window)
{
  ShowText::window = window;
  font = new sf::Font;
  font->loadFromFile(FONT_PATH);

  textCenter = new sf::Text;
  textCenter->setFont(*font);
  textCenter->setPosition(SHOW_TEXT_MID_INDEX_X, SHOW_TEXT_MID_INDEX_Y);
  textCenter->setCharacterSize(SHOW_TEXT_MID_CHARACTER_SIZE);
  textCenter->setColor(SHOW_TEXT_MID_COLOR);

  textInfo = new sf::Text;
  textInfo->setFont(*font);
  textInfo->setPosition(SHOW_TEXT_GAME_STATUS_INDEX_X, SHOW_TEXT_GAME_STATUS_INDEX_Y);
  textInfo->setCharacterSize(SHOW_TEXT_GAME_STATUS_CHARACTER_SIZE);
  textInfo->setColor(SHOW_TEXT_GAME_STATUS_COLOR);
}
ShowText::~ShowText()
{
  delete font;
  delete textCenter;
  delete textInfo;
}
void ShowText::showDeadInfo()
{
  textCenter->setString("DEAD");
  window->draw(*textCenter);
}
void ShowText::showWinInfo()
{
  textCenter->setString("WIN");
  window->draw(*textCenter);
}
void ShowText::showInfo(int difficulty, int score)
{
  textInfo->setString("Class : " + std::to_string(difficulty) + " Score : " + std::to_string(score));
  window->draw(*textInfo);
}
