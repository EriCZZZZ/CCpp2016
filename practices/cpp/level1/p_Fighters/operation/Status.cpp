#include "Status.h"

#ifdef DEBUG
#include <iostream>
#endif

Status::Status(sf::RenderWindow *window, int difficultyBase)
{
  Status::window = window;
  initializeStatus();
  initializeText();
  initializeHPfill();
  initializeHPborder();

  Status::difficultyBase = difficultyBase;
  setDifficulty();
}
void Status::initializeStatus()
{
  gameStatus = GAME_GOING;
  score = 0;
  HP = FIGHTER_HP_MAX;
}
void Status::initializeText()
{
  font = new sf::Font;
  font->loadFromFile(FONT_PATH);

  text = new sf::Text;
  text->setFont(*font);
  text->setPosition(SCREEN_WIDTH * GAME_FONT_INDEX_PERCENT_X, SCREEN_HEIGHT * GAME_FONT_INDEX_PERCENT_Y);
  text->setCharacterSize(FONT_SIZE);
  text->setColor(FONT_COLOR);
}
void Status::initializeHPfill()
{
  HPfill = new sf::RectangleShape;
  HPfill->setSize(sf::Vector2f(GAME_HP_LENGTH, GAME_HP_WIDTH));
  HPfill->setPosition(SCREEN_WIDTH * GAME_HP_INDEX_PERCENT_X, SCREEN_HEIGHT * GAME_HP_INDEX_PERCENT_Y);
  HPfill->setFillColor(GAME_HP_FILL_FILL_COLOR);
}
void Status::initializeHPborder()
{
  HPborder = new sf::RectangleShape;
  HPborder->setSize(HPfill->getSize());
  HPborder->setPosition(HPfill->getPosition());
  HPborder->setOutlineThickness(GAME_HP_BORDER_OUTLINE_THICKNESS);
  HPborder->setOutlineColor(GAME_HP_BORDER_BORDER_COLOR);
  HPborder->setFillColor(GAME_HP_BORDER_FILL_COLOR);
}
Status::~Status()
{
  delete HPfill;
  delete HPborder;
  delete font;
  delete text;
}
void Status::operate()
{
  refreshString();
  refreshHPfill();
  drawStatus();
  checkIsWinAndRefresh();
}
void Status::checkIsWinAndRefresh()
{
  if(score >= GAME_MAX_SCORE)
  {
    gameStatus = GAME_NEXT_DIFFICULTY;
  }
}
void Status::drawStatus()
{
  window->draw(*text);
  window->draw(*HPborder);
  window->draw(*HPfill);
}
void Status::refreshString()
{
  text->setString("Score : " + std::to_string(score));
}
void Status::refreshHPfill()
{
  HPfill->setSize(sf::Vector2f((static_cast<float>(HP) / FIGHTER_HP_MAX) * GAME_HP_LENGTH, GAME_HP_WIDTH));
}
void Status::addHP(int deltaHP)
{
  int temp = deltaHP + HP;
  if(temp < FIGHTER_HP_MIN)
  {
    HP = FIGHTER_HP_MIN;
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
int Status::checkGameStatus()
{
  return gameStatus;
}
void Status::setDifficulty()
{
  difficulty.push_back(difficultyBase * DIFFICULTY_K_SHELL_SPEED);
  difficulty.push_back(difficultyBase * DIFFICULTY_K_SHELL_FIRE_RATE);
  difficulty.push_back(difficultyBase * DIFFICULTY_K_ENEMY_FIGHTER_MAX_NUMBER);
}
int Status::getDifficulty(int index)
{
  return difficulty[index];
}
