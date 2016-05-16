#ifndef FIGHTER_GRAPHICS_H
#define FIGHTER_GRAPHICS_H

#include "ElementGraphics.h"
#include "../head/GameConfig.h"

class FighterGraphics : public ElementGraphics
{
private:
  sf::Texture fighterTexture;
  sf::Vertex fighterVertices[FIGHTER_COORDINATE_NUMBER];
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
  FighterGraphics();
  void designOutlookByPoint(int index, sf::Vertex targetVertex);
};
#endif
