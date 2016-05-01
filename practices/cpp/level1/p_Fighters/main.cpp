#include <SFML/Graphics.hpp>
#include "./classFighter/EnemyFighter.h"
#include <thread>
#include <chrono>
int main()

{
  sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML");

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
    window.display();
    std::this_thread::sleep_for(std::chrono::microseconds(100000));
  }
  return 0;
}
