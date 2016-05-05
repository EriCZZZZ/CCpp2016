#include <SFML/Graphics.hpp>
#include "./operation/Player.h"
#include "./operation/Enemy.h"
#include "./operation/AllShell.h"
#include "./operation/CollisionJudge.h"
#include "./head/GameConfig.h"

#include <thread>
#include <chrono>
#include <functional>
#include <vector>

#include <iostream>

#define DEBUG

int main()
{
  sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML");
  AllShell* allShell = new AllShell();
  Player* player = new Player(allShell);
  Enemy* enemy = new Enemy(allShell);
  #ifdef DEBUG
  std::cout << player << " " << enemy << std::endl;
  #endif
  CollisionJudge collisionJudge(player, enemy, allShell);
  std::vector<Operation *> gameOperation;
  gameOperation.push_back(allShell);
  gameOperation.push_back(player);
  gameOperation.push_back(enemy);
  while(window.isOpen())
  {
    sf::Event event;
    while(window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
      {
        window.close();
      }
    }
    window.clear(sf::Color::Black);
    for(auto it = gameOperation.begin(); it != gameOperation.end(); it++)
    {
      (*it)->operate(&window);
    }
    collisionJudge.judgeAll();
    window.display();
    std::this_thread::sleep_for(std::chrono::microseconds(10));
  }
  return 0;
}
