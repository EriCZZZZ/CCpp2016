#include <SFML/Graphics.hpp>
#include "./operation/Player.h"
#include "./operation/Enemy.h"
#include "./operation/AllShell.h"
#include "./operation/CollisionJudge.h"
#include "./head/GameConfig.h"

#include <thread>
#include <mutex>
#include <chrono>
#include <functional>
#include <vector>

#include <iostream>

int main()
{
  sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML");
  std::mutex mt;
  std::vector<int> gameStatus;
  gameStatus.push_back(GAME_STATUS_GOING);
  for(int count = 0; count < 3; count++)
  {
    gameStatus.push_back(GAME_STATUS_UNDONE);
  }
  AllShell allShell(std::ref(gameStatus));
  Player player(&allShell, std::ref(gameStatus));
  Enemy enemy(&allShell, std::ref(gameStatus));
  CollisionJudge collisionJudge(&player, &enemy, &allShell);
  mt.lock();
  std::thread threadPlayer(&Player::operate, &player, &window, &mt);
  std::thread threadEnemy(&Enemy::operate, &enemy, &window, &mt);
  std::thread threadAllShell(&AllShell::operate, &allShell, &window, &mt);

  // === debug ===
  std::cout << "main-main-loop up" << std::endl;
  // === end ===

  while(window.isOpen())
  {
    // === debug ===
    std::cout << "main event up" << std::endl;
    // === end ===

    sf::Event event;
    while(window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
      {
        window.close();
      }
    }

    // === debug ===
    std::cout << "main-clear up" << std::endl;
    // === end ===

    window.clear(sf::Color::Black);
    // if(gameStatus[ID_GAME_STATUS] == GAME_STATUS_STOP)
    // {
    //   mt.unlock();
    //   continue;
    // }
    mt.unlock();
    while(1)
    {
      mt.lock();
      if(gameStatus[ID_PLAYER] == GAME_STATUS_UNDONE || gameStatus[ID_ALL_SHELL] == GAME_STATUS_UNDONE || gameStatus[ID_ENEMY] == GAME_STATUS_UNDONE)
      {
        mt.unlock();
        continue;
      }
      else
      {
        break;
      }
    }
    //
    // while(mt.try_lock())
    // {
    //   // === debug ===
    //   std::cout << "main main-loop try_lock()-loop" << std::endl;
    //   // === end ===
    //
    //   bool flag = 0;
    //   for(auto it = gameStatus.begin(); it != gameStatus.end(); it++)
    //   {
    //     if(*it == GAME_STATUS_UNDONE)
    //     {
    //       mt.unlock();
    //       flag = 1;
    //       break;
    //     }
    //   }
    //   if(flag == 0)
    //   {
    //     break;
    //   }
    // }
    // collisionJudge.judgeAll();
    window.display();
    gameStatus[ID_PLAYER] = GAME_STATUS_UNDONE;
    gameStatus[ID_ALL_SHELL] = GAME_STATUS_UNDONE;
    gameStatus[ID_ENEMY] = GAME_STATUS_UNDONE;
    std::this_thread::sleep_for(std::chrono::microseconds(10));
  }
  return 0;
}
