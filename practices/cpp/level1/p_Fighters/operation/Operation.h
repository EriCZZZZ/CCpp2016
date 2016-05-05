#ifndef OPERATION_H
#define OPERATION_H

#include <SFML/Graphics.hpp>
#include <thread>
#include <mutex>
#include <vector>
#include "../head/GameConfig.h"

class Operation
{
public:
  virtual void operate() = 0;
};

#endif
