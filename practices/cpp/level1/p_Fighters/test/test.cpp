#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>

#include <thread>
#include <mutex>

std::mutex mt;
bool flag = 1;
int mainFlag = 0;
int func1(sf::RenderWindow *window)
{
  sf::CircleShape circle(50);
  circle.setFillColor(sf::Color::Red);
  while(flag)
  {
    if(!mt.try_lock())
      continue;

    std::cout << "func1 " << mainFlag << std::endl;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
      circle.move(1, 0);
    }
    window->draw(circle);
    mainFlag = 1;
    std::cout << "func1 " << mainFlag << std::endl;
    mt.unlock();
    while(mainFlag != 0);
  }
}

void func2(sf::RenderWindow *window)
{
  sf::CircleShape circle(50);
  circle.setFillColor(sf::Color::White);
  circle.setPosition(200, 200);
  while(flag)
  {
    if(!mt.try_lock())
      continue;

    std::cout << "func2 " << mainFlag << std::endl;

    window->draw(circle);
    std::cout << mainFlag << std::endl;
    std::cout << mainFlag + 1 << std::endl;
    mainFlag = 2;
    std::cout << mainFlag << std::endl;
    std::cout << "func2 " << mainFlag << std::endl;
    mt.unlock();
    while(!(mainFlag == 1));
  }
}
int main()
{
  sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML");
  mt.lock();
  std::thread t1(func1, &window);
  std::thread t2(func2, &window);
  while(window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    std::cout << "main up clear" << std::endl;
    window.clear(sf::Color::Black);
    mt.unlock();
    while(mainFlag < 2)
    {
      // std::cout << "main in loop : mainFlag < 2" << std::endl;
      ;
    }
    std::cout << "main unlock" << std::endl;
    while(!mt.try_lock());
    mainFlag = 0;
    window.display();
  }
  return 0;
}
