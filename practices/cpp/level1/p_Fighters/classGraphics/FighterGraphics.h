#ifndef FIGHTER_GRAPHICS_H
#define FIGHTER_GRAPHICS_H

#include "../head/ElementGraphics.h"
#include "../head/FighterGlobalConfig.h"

class FighterGraphics : public ElementGraphics
{
private:
  sf::Texture fighterTexture;
  sf::Vertex fighterVertices[FIGHTER_COORDINATE_NUMBER];
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
  FighterGraphics();
  void setPoint(int index, sf::Vertex targetVertex);
};
#endif
