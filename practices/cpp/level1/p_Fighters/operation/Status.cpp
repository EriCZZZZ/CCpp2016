#include "Status.h"

#ifdef DEBUG
#include <iostream>
#endif

Status::Status(sf::RenderWindow *window, int difficultyBase)
{
  Status::window = window;
  initializeStatus();
  initializeText();

  Status::difficultyBase = difficultyBase;
  setDifficulty();
}
void Status::initializeStatus()
{
  gameStatus = GAME_GOING;
  score = 0;
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

Status::~Status()
{
  delete font;
  delete text;
}
void Status::operate()
{
  refreshString();
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
}
void Status::refreshString()
{
  text->setString("Class : " + std::to_string(difficultyBase) + " Score : " + std::to_string(score));
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
