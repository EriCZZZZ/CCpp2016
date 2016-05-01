#include "AllShell.h"
AllShell::AllShell(CollisionJudge *collisionJudgeMachine, std::vector<int> &gameStatus)
{
  AllShell::collisionJudgeMachine = collisionJudgeMachine;
  AllShell::gameStatus = gameStatus;
}
void AllShell::newShell(Shell *shell)
{
  allShell.push_back(shell);
}
void AllShell::operate(sf::RenderWindow *window, std::mutex *mt)
{
  while(gameStatus[ID_GAME_STATUS] == GAME_STATUS_GOING)
  {
    while(mt->try_lock())
    {
      if(gameStatus[ID_ALL_SHELL] == GAME_STATUS_DONE)
      {
        continue;
      }
      for(auto it = allShell.begin(); it != allShell.end(); it++)
      {
        (*it)->move();
        if((collisionJudgeMachine->judge((*it)->getVertex.position.x, (*it)->getVertex.position.y)) == COLLISION_KNOCKED)
        {
          allShell.erase(it);
          it--;
        }
        else
        {
          window->draw(((*it)->toDraw()));
        }
      }
    }
    gameStatus[ID_ALL_SHELL] = GAME_STATUS_DONE;
    mt->unlock();
  }
}
