#ifndef ALL_SHELL_H
#define ALL_SHELL_H

#include "Operation.h"
#include "CollisionJudge.h"
#include "../classShell/Shell.h"

class AllShell : public Operation
{
private:
  std::vector<Shell *> allShell;
  std::vector<int> &gameStatus;
  CollisionJudge *collisionJudgeMachine;
public:
  AllShell(CollisionJudge *collisionJudgeMachine, std::vecotr<int> &gameStatus);
  void newShell(Shell *shell);
  void operate(sf::RenderWindow *window, std:::mutex *mt);
};
#endif
