#include "Game.h"
Game::Game(int difficulty)
{
  window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "ERIC-FIGHTER");
  initializateItem(difficulty);
  initializateSound();
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
  status = new Status(window, difficulty);
  allShell = new AllShell(window);
  player = new Player(allShell, window, this);
  enemy = new Enemy(allShell, window, this);
  collisionJudge = new CollisionJudge(player, enemy, allShell);
  gameOperation.push_back(player);
  gameOperation.push_back(enemy);
  gameOperation.push_back(allShell);
  // gameOperation.push_back(status);
}
void Game::initializateSound()
{
  bufferBGM = new sf::SoundBuffer;
  bufferBGM->loadFromFile(SOUND_BGM);
  soundBGM = new sf::Sound;
  soundBGM->setBuffer(*bufferBGM);
  soundBGM->setLoop(true);
  soundBGM->play();
}
Game::~Game()
{
  delete status;
  delete allShell;
  delete player;
  delete enemy;
  delete collisionJudge;
  delete showText;
  delete soundBGM;
  delete bufferBGM;
  delete window;
}
void Game::setGameStatus(int gameStatus)
{
  Game::gameStatus = gameStatus;
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
        soundBGM->stop();
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
      collisionJudge->judgeAll();
      //print info
      checkScore();
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
        soundBGM->stop();
        return gameStatus;
      }
    }
    window->display();
    std::this_thread::sleep_for(std::chrono::microseconds(INTERVAL_MAIN));
  }
}
void Game::addScore(int deltaScore)
{
  score += deltaScore;
}
void Game::checkScore()
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
