#ifndef SHELL_GRAPHICS_H
#define SHELL_GRAPHICS_H

#include "ElementGraphics.h"
#include "../head/GameConfig.h"

class ShellGraphics : public ElementGraphics
{
private:
  sf::Texture shellTexture;
  sf::CircleShape shell;
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
  ShellGraphics();
};
#endif
