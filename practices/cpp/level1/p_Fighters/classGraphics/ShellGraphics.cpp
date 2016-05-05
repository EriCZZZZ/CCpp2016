#include "ShellGraphics.h"
ShellGraphics::ShellGraphics()
{
  shell.setRadius(SHELL_CIRCLE_RADIUS);
  shell.setFillColor(sf::Color::SHELL_FILL_COLOR);
  shell.setOrigin(SHELL_ORIGIN_COORDINATE_X, SHELL_ORIGIN_COORDINATE_Y);
}
void ShellGraphics::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &shellTexture;
  target.draw(shell, states);
}
