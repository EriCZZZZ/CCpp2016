#ifndef OPERATION_H
#define OPERATION_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "../head/GameConfig.h"
#include "PlaySound.h"
class Operation
{
public:
  virtual void operate() = 0;
};

#endif
