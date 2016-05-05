#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Main.hpp>
#include <SFML/Config.hpp>

int main()
{
  sf::RenderWindow window(sf::VideoMode(1000, 1000), "sfml");
  sf::SoundBuffer buffer;
  buffer.loadFromFile("../source/BGM.wav");
  // sf::Music music;
  // music.openFromFile("aaa");
  sf::Texture texture;
  texture.loadFromFile("aaa");
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
  }
  return 0;
}
