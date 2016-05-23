#include "DeadText.h"
DeadText::DeadText(sf::RenderWindow *window)
{
  DeadText::window = window;
  font = new sf::Font;
  font->loadFromFile(FONT_PATH);

  text = new sf::Text;
  text->setFont(*font);
  text->setPosition(DEAD_TEXT_INDEX_X, DEAD_TEXT_INDEX_Y);
  text->setCharacterSize(DEAD_TEXT_CHARACTER_SIZE);
  text->setColor(DEAD_TEXT_COLOR);
  text->setString("DONE");
}
DeadText::~DeadText()
{
  delete font;
  delete text;
}
void DeadText::showDeadInfo()
{
  window->draw(*text);
}
