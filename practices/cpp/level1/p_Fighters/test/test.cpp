#include <iostream>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <vector>

// class ElementGraphics : public sf::Drawable, public sf::Transformable
// {
// public:
//   virtual void draw(sf::RenderTarget& target, sf::RenderStates state) = 0;
// };

class FighterGraphics : public sf::Drawable, public sf::Transformable
{
private:
  sf::VertexArray fighterVertices;
  sf::Texture fighterTexture;
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
  FighterGraphics();
  void setPoint(int index, sf::Vertex targetVertex);
};
int main()
{
  sf::VertexArray fighterVertices(sf::TrianglesFan, 4);
  std::cout << TEST << std::endl;
  return 0;
}
