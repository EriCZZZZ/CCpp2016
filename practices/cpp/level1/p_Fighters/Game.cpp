#include "Game.h"
#ifdef DEBUG
#include <iostream>
#endif
Game::Game(int difficulty)
{
  window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "ERIC-FIGHTER");
  initializateSound();
  initializateItem(difficulty);
  initializeInfo();
  Game::difficulty = difficulty;
  initializeDifficulty();
  //dead text
  showText = new ShowText(window);
}
void Game::initializeDifficulty()
{
  difficultyContainer.push_back(difficulty * DIFFICULTY_K_SHELL_SPEED);
  difficultyContainer.push_back(difficulty * DIFFICULTY_K_SHELL_FIRE_RATE);
  difficultyContainer.push_back(difficulty * DIFFICULTY_K_ENEMY_FIGHTER_MAX_NUMBER);
}
void Game::initializeInfo()
{
  score = 0;
  gameStatus = GAME_GOING;
}
void Game::initializateItem(int difficulty)
{
  spriteContainer = new SpriteContainer(window);
  player = new Player(spriteContainer, window, this, playSound);
  enemy = new Enemy(spriteContainer, window, this, playSound);
  collisionJudge = new CollisionJudge(player, enemy, spriteContainer);
  gameOperation.push_back(player);
  gameOperation.push_back(enemy);
  gameOperation.push_back(spriteContainer);
}
void Game::initializateSound()
{
  playSound = new PlaySound;
  playSound->playBGM();
}
Game::~Game()
{
  delete spriteContainer;
  delete player;
  delete enemy;
  delete collisionJudge;
  delete showText;
  delete playSound;
  delete window;
}
int Game::play()
{
  while(window->isOpen())
  {
    sf::Event eventClosed;
    while(window->pollEvent(eventClosed))
    {
      if(eventClosed.type == sf::Event::Closed)
      {
        playSound->stopBGM();
        window->close();
        return GAME_STOP;
      }
    }
    window->clear(SCREEN_COLOR_BACKGROUND);
    if(gameStatus == GAME_GOING)
    {
      for(auto it = gameOperation.begin(); it != gameOperation.end(); it++)
      {
        (*it)->operate();
      }
      createAward();
      collisionJudge->judgeAll();
      //print info
      checkScoreAndSetGameStatus();
      showText->showInfo(difficulty, score);
    }
    else
    {
      if(gameStatus == GAME_STOP)
      {
        showText->showDeadInfo();
      }
      else
      {
        showText->showWinInfo();
      }
      if(sf::Keyboard::isKeyPressed(KEYBOARD_RETURN))
      {
        window->close();
        playSound->stopBGM();
        return gameStatus;
      }
    }
    window->display();
    std::this_thread::sleep_for(std::chrono::microseconds(INTERVAL_MAIN));
  }
}

void Game::createAward()
{
  auto temp = new SpriteWeaponSpread;
  temp->setPosition(200, 200);
  spriteContainer->addSprite(temp);
}
void Game::addScore(int deltaScore)
{
  score += deltaScore;
}
void Game::checkScoreAndSetGameStatus()
{
  if(score >= GAME_MAX_SCORE)
  {
    gameStatus = GAME_NEXT_DIFFICULTY;
  }
}
int Game::getDifficulty(int index)
{
  return difficultyContainer[index];
}
void Game::setGameStatus(int gameStatus)
{
  Game::gameStatus = gameStatus;
}
