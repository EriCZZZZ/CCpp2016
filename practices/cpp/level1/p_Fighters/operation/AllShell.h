#ifndef ALL_SHELL_H
#define ALL_SHELL_H

#include "Operation.h"
#include "../classShell/Shell.h"
#include <functional>

class AllShell : public Operation
{
private:
  std::vector<Shell *> allShell;
public:
  void newShell(Shell *shell);
  void operate(sf::RenderWindow *window);
  std::vector<Shell *> &shellVector();
};
#endif
