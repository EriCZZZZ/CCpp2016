#ifndef ALL_SHELL_H
#define ALL_SHELL_H

#include "Operation.h"
#include "../classShell/Shell.h"
#include <functional>
#include "../head/GameConfig.h"

class AllShell : public Operation
{
private:
  std::vector<Shell *> allShell;
  sf::RenderWindow *window;
public:
  AllShell(sf::RenderWindow *window) : window(window) {}
  void newShell(Shell *shell);
  void operate();
  std::vector<Shell *> &shellVector();
};
#endif
