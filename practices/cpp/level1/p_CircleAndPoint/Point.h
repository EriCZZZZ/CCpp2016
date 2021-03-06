#ifndef POINT_H
#define POINT_H

#ifdef DEBUG
#include <iostream>
#endif

#include <vector>
#define BY_HUMAN 1
#define BY_POINT 0
class Point
{
private:
  int coorX = 0;
  int coorY = 0;
public:
  Point();
  Point(int X, int Y) : coorX(X), coorY(Y) {}
  void move(int deltaX, int deltaY);
#ifdef DEBUG
  void printStatus()
  {
    std::cout << "===========start=========" << std::endl;
    std::cout << "(x, y)" << coorX << "," << coorY << std::endl;
    std::cout << "============end===========" << std::endl;
  }
#endif
};
#endif
