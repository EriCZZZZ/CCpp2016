#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <functional>
// #include "head/conio.h"
#include <SFML/Window/Keyboard.hpp>
// #include<SFML/Window.hpp>
char order = 's';
void func(sf::CircleShape &shape)
{
  while(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    shape.move(5, 0);
  }
}
int main()
{
  sf::RenderWindow window(sf::VideoMode(1080, 720), "My window");
  sf::CircleShape shape(50);
  shape.setFillColor(sf::Color(100, 250, 50));
  shape.setPosition(10, 50);
  std::thread getOrder(func, std::ref(shape));
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
    window.clear(sf::Color::White);
    window.draw(shape);
    window.display();
    if(order != 's')
    {
      if(order == 'a')
      {
        shape.move(-10, 0);
        order = 's';
      }
      else if(order == 'd')
      {
        shape.move(10, 0);
        order = 's';
      }
      else
        order = 's';
    }

    // char temp;
    // while(temp = getch())
    // {
    //   shape.move(5, 5);
    // }
    // std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  return 0;
}
