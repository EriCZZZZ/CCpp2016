#ifndef ALL_SHELL_H
#define ALL_SHELL_H

#include "Operation.h"
#include "../classSprite/Shell.h"
#include <functional>
#include "../head/GameConfig.h"

class CollisionJudge;

class AllShell : public Operation
{
  friend CollisionJudge;
private:
  std::vector<Shell *> allShell;
  sf::RenderWindow *window;

  void moveAllShell();
  void checkAllShell();
  void drawAllShell();
public:
  AllShell(sf::RenderWindow *window) : window(window) {}
  ~AllShell();
  void addShell(Shell *shell);
  void operate();
};
#endif
