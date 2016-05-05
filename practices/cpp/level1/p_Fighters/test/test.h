#include <SFML/Graphics.hpp>
#include <functional>

class shapeClass
{
private:
  sf::CircleShape *temp = new sf::CircleShape(50);
  // static sf::CircleShape temp;
public:
  void showShape(sf::RenderWindow *window, std::mutex *mt, bool *flag);
};
// sf::CircleShape shapeClass::temp(50);
void shapeClass::showShape(sf::RenderWindow *window, std::mutex *mt, bool *flag)
{
  while(1)
  {
    std::cout << "class 1" << std::endl;
    while(1)
    {
      mt->lock();
      if(*flag == 1)
      {
        mt->unlock();
        continue;
      }
      else
      {
        break;
      }
    }
    std::cout << "class 2" << std::endl;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
      temp->move(-1, 0);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
      temp->move(1, 0);
    }
    window->draw(*temp);
    std::cout << "class 3" << std::endl;
    *flag = 1;
    mt->unlock();
  }
}
