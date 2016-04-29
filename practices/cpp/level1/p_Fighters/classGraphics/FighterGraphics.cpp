#include "FighterGraphics.h"
FighterGraphics::FighterGraphics()
{
  fighterVertices[0] = sf::Vertex(sf::Vector2f(FIGHTER_COORDINATE_1_X, FIGHTER_COORDINATE_1_Y));
  fighterVertices[1] = sf::Vertex(sf::Vector2f(FIGHTER_COORDINATE_2_X, FIGHTER_COORDINATE_2_Y));
  fighterVertices[2] = sf::Vertex(sf::Vector2f(FIGHTER_COORDINATE_3_X, FIGHTER_COORDINATE_3_Y));
  fighterVertices[3] = sf::Vertex(sf::Vector2f(FIGHTER_COORDINATE_4_X, FIGHTER_COORDINATE_4_Y));
}
void FighterGraphics::setPoint(int index, sf::Vertex targetVertex)
{
  fighterVertices[index] = targetVertex;
}
void FighterGraphics::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &fighterTexture;
  // target.draw(fighterVertices, states);
  target.draw(fighterVertices, FIGHTER_COORDINATE_NUMBER, sf::TrianglesFan, states);
}
