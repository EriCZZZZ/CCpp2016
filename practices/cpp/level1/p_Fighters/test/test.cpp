#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "test.h"

int main()
{
  bool flag = 0;
  sf::RenderWindow window(sf::VideoMode(1000, 1000), "sfml");
  std::mutex mt;
  mt.lock();
  shapeClass tempShape;
  std::thread t1(&shapeClass::showShape, &tempShape, &window, &mt, &flag);
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
    mt.unlock();
    std::cout << "1" << std::endl;
    while(1)
    {
      mt.lock();
      if(flag == 0)
      {
        mt.unlock();
        continue;
      }
      else
      {
        break;
      }
    }
    std::cout << "2" << std::endl;
    flag = 0;
    window.display();
    std::cout << "3" << std::endl;
    std::this_thread::sleep_for(std::chrono::microseconds(10000));
  }
  return 0;
}
