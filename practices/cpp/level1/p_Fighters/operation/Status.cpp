#include "Status.h"

#ifdef DEBUG
#include <iostream>
#endif

Status::Status(sf::RenderWindow *window)
{
  gameStatus = GAME_GOING;
  score = 0;
  HP = FIGHTER_HP_MAX;

  Status::window = window;

  font = new sf::Font;
  font->loadFromFile(FONT_PATH);

  text = new sf::Text;
  text->setFont(*font);
  text->setPosition(SCREEN_WIDTH * GAME_FONT_INDEX_PERCENT_X, SCREEN_HEIGHT * GAME_FONT_INDEX_PERCENT_Y);
  text->setCharacterSize(FONT_SIZE);
  text->setColor(FONT_COLOR);

  HPfill = new sf::RectangleShape;
  HPfill->setSize(sf::Vector2f(GAME_HP_LENGTH, GAME_HP_WIDTH));
  HPfill->setPosition(SCREEN_WIDTH * GAME_HP_INDEX_PERCENT_X, SCREEN_HEIGHT * GAME_HP_INDEX_PERCENT_Y);
  HPfill->setFillColor(GAME_HP_FILL_FILL_COLOR);

  HPborder = new sf::RectangleShape;
  HPborder->setSize(HPfill->getSize());
  HPborder->setPosition(HPfill->getPosition());
  HPborder->setOutlineThickness(GAME_HP_BORDER_OUTLINE_THICKNESS);
  HPborder->setOutlineColor(GAME_HP_BORDER_BORDER_COLOR);
  HPborder->setFillColor(GAME_HP_BORDER_FILL_COLOR);
}
Status::~Status()
{
  delete HPborder;
  delete HPfill;
  delete HPborder;
  delete font;
  delete text;
}
void Status::operate()
{
  text->setString("Score : " + std::to_string(score));
  HPfill->setSize(sf::Vector2f((static_cast<float>(HP) / FIGHTER_HP_MAX) * GAME_HP_LENGTH, GAME_HP_WIDTH));
  window->draw(*text);
  window->draw(*HPborder);
  window->draw(*HPfill);
}
void Status::addHP(int deltaHP)
{
  int temp = deltaHP + HP;
  if(temp < 0)
  {
    HP = 0;
  }
  else
  {
    HP = temp;
  }
}
void Status::addScore(int deltaScore)
{
  score += deltaScore;
}
void Status::setGameStatus(bool status)
{
  gameStatus = status;
}
bool Status::checkGameStatus()
{
  return gameStatus;
}
