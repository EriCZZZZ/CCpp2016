#ifndef SHELL_GRAPHICS_H
#define SHELL_GRAPHICS_H

#include "../head/ElementGraphics.h"
#include "../head/ShellGlobalConfig.h"

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
