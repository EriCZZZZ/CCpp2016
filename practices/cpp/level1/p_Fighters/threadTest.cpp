#include <thread>
#include <iostream>

void func()
{
  for(int count = 0; count != 100; count++)
  {
    std::cout << count << std::endl;
  }
}
int main()
{
  std::thread t1(func);
  std::cout << "main thread" << std::endl;
  t1.join();
  return 0;
}
