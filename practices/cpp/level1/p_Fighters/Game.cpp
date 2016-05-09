#include "Game.h"
Game::Game()
{
  window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "ERIC-FIGHTER");
  status = new Status(window, 3);
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
  deadText = new DeadText(window);
}
Game::~Game()
{
  delete status;
  delete allShell;
  delete player;
  delete enemy;
  delete collisionJudge;
  delete deadText;
  delete soundBGM;
  delete bufferBGM;
  delete window;
}
void Game::play()
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
      deadText->operate();
      if(sf::Keyboard::isKeyPressed(KEYBOARD_RETURN))
      {
        delete window;
        soundBGM->stop();
        return;
      }
    }
    window->display();
    std::this_thread::sleep_for(std::chrono::microseconds(INTERVAL_MAIN));
  }
}
