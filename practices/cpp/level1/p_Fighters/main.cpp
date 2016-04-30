#include <SFML/Graphics.hpp>
#include "classGraphics/FighterGraphics.h"
#include "classGraphics/ShellGraphics.h"
#include "classShell/Shell.h"
#include "classFighter/PlayerFighter.h"
#include "classFighter/PlayerFighterFactory.h"
#include <thread>
#include <chrono>
int main()

{
  sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML");
  Shell shell;
  shell.setPosition(1, 1);
  shell.setDeltaVector(sf::Vector2f(1, 1));
  // PlayerFighter fighter(200, 200);
  PlayerFighterFactory pff;
  auto fighter = pff.createFighter(200, 200);
  auto fighterCShell = fighter->createShell();
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
    // shell.move();
    // fighterCShell->move();
    // fighter.move(1, 0);
    window.draw(*(shell.toDraw()));
    window.draw(*(fighter->toDraw()));
    window.draw(*(fighterCShell->toDraw()));
    window.display();
    std::this_thread::sleep_for(std::chrono::microseconds(100000));
  }
  return 0;
}
