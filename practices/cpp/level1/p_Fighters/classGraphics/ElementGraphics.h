#ifndef ELEMENT_GRAPHICS_H
#define ELEMENT_GRAPHICS_H

#include <SFML/Graphics.hpp>
#include "../head/GameConfig.h"

class ElementGraphics : public sf::Drawable, public sf::Transformable
{
public:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const = 0 ;
};
#endif
