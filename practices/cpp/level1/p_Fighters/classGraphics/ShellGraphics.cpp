#include "ShellGraphics.h"
ShellGraphics::ShellGraphics()
{
  shell.setRadius(SHELL_CIRCLE_RADIUS);
  shell.setFillColor(sf::Color::SHELL_FILL_COLOR);
}
void ShellGraphics::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &shellTexture;
  target.draw(shell, states);
}
