#include "ShowText.h"
ShowText::ShowText(sf::RenderWindow *window)
{
  ShowText::window = window;
  font = new sf::Font;
  font->loadFromFile(FONT_PATH);

  text = new sf::Text;
  text->setFont(*font);
  text->setPosition(SHOW_TEXT_INDEX_X, SHOW_TEXT_INDEX_Y);
  text->setCharacterSize(SHOW_TEXT_CHARACTER_SIZE);
  text->setColor(SHOW_TEXT_COLOR);
}
ShowText::~ShowText()
{
  delete font;
  delete text;
}
void ShowText::showDeadInfo()
{
  text->setString("DEAD");
  window->draw(*text);
}
void ShowText::showWinInfo()
{
  text->setString("WIN");
  window->draw(*text);
}
