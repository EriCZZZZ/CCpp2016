#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "./operation/Player.h"
#include "./operation/Enemy.h"
#include "./operation/AllShell.h"
#include "./operation/CollisionJudge.h"
#include "./head/GameConfig.h"
#include "./operation/Status.h"

#include <thread>
#include <chrono>
#include <functional>
#include <vector>

#include <iostream>

#define DEBUG

int main()
{
  sf::SoundBuffer buffer;
  buffer.loadFromFile("./source/BGM.wav");
  sf::Sound sound;
  sound.setBuffer(buffer);
  sound.setLoop(true);
  sound.play();

  sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML");
  Status* status = new Status(&window);
  AllShell* allShell = new AllShell(&window);
  Player* player = new Player(allShell, &window, status);
  Enemy* enemy = new Enemy(allShell, &window, status);
  CollisionJudge collisionJudge(player, enemy, allShell);
  std::vector<Operation *> gameOperation;
  gameOperation.push_back(player);
  gameOperation.push_back(enemy);
  gameOperation.push_back(allShell);
  gameOperation.push_back(status);

  sf::Font font;
  font.loadFromFile("./source/font.ttf");

  sf::Text text;
  text.setFont(font);
  text.setPosition(400, 300);
  text.setColor(sf::Color::Red);
  text.setString("YEAH, YOU DIED.");
  text.setCharacterSize(50);

  while(window.isOpen())
  {
    sf::Event event;
    while(window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
      {
        #ifdef DEBUG
        std::cout << "end" << std::endl;
        #endif
        window.close();
      }
    }
    if(status->checkGameStatus() == GAME_STOP)
    {
      break;
    }
    window.clear(sf::Color::Black);
    for(auto it = gameOperation.begin(); it != gameOperation.end(); it++)
    {
      (*it)->operate();
    }
    collisionJudge.judgeAll();
    window.display();
    std::this_thread::sleep_for(std::chrono::microseconds(5000));
  }
  while(window.isOpen())
  {
    sf::Event event;
    while(window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
      {
        window.close();
      }
      window.clear(sf::Color::Black);
      window.draw(text);
      window.display();
    }
  }
  return 0;
}
