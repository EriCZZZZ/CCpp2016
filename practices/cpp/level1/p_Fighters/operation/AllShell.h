#ifndef ALL_SHELL_H
#define ALL_SHELL_H

#include "Operation.h"
#include "../classShell/Shell.h"
#include <functional>

class AllShell : public Operation
{
private:
  std::vector<Shell *> allShell;
  std::vector<int> &gameStatus;
public:
  AllShell(std::vector<int> &gameStatus) : gameStatus(gameStatus) {}
  void newShell(Shell *shell);
  void operate(sf::RenderWindow *window, std::mutex *mt);
  std::vector<Shell *> &shellVector();
};
#endif
