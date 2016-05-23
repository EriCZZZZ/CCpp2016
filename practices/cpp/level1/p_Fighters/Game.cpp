#include "Game.h"

Game::Game(int difficulty)
{
  window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "ERIC-FIGHTER");
  status = new Status(window, difficulty);
  allShell = new AllShell(window);
  player = new Player(allShell, window, status);
  enemy = new Enemy(allShell, window, status);
  collisionJudge = new CollisionJudge(player, enemy, allShell);
  gameOperation.push_back(player);
  gameOperation.push_back(enemy);
  gameOperation.push_back(allShell);
  gameOperation.push_back(status);
  //BGM
  bufferBGM = new sf::SoundBuffer;
  bufferBGM->loadFromFile(SOUND_BGM);
  soundBGM = new sf::Sound;
  soundBGM->setBuffer(*bufferBGM);
  soundBGM->setLoop(true);
  soundBGM->play();

  //dead text
  showText = new ShowText(window);
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
int Game::play()
{
  int gameFlag = GAME_GOING;
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
    if(status->checkGameStatus() == GAME_GOING)
    {
      for(auto it = gameOperation.begin(); it != gameOperation.end(); it++)
      {
        (*it)->operate();
      }
      collisionJudge->judgeAll();
    }
    else
    {
      gameFlag = status->checkGameStatus();
      if(gameFlag == GAME_STOP)
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
        return gameFlag;
      }
    }
    window->display();
    std::this_thread::sleep_for(std::chrono::microseconds(INTERVAL_MAIN));
  }
}
