#include "Player.h"

#ifdef DEBUG
#include <iostream>
#endif

Player::Player(AllShell *shellContainer, sf::RenderWindow *window, Game *game)
{
  Player::window = window;
  Player::game = game;
  Player::shellContainer = shellContainer;

  PlayerFighterFactory *tempFactory = new PlayerFighterFactory;
  playerFighter = tempFactory->createFighter(PLAYER_CREATE_FIGHTER_X, PLAYER_CREATE_FIGHTER_Y);
  delete tempFactory;

  bufferFire = new sf::SoundBuffer;
  bufferFire->loadFromFile(SOUND_FIRE);

  bufferAttacked = new sf::SoundBuffer;
  bufferAttacked->loadFromFile(SOUND_ATTACKED);
  soundAttacked = new sf::Sound;
  soundAttacked->setBuffer(*bufferAttacked);

  bufferDead = new sf::SoundBuffer;
  bufferDead->loadFromFile(SOUND_DEAD);
  soundDead = new sf::Sound;
  soundDead->setBuffer(*bufferDead);

  initializeHPfill();
  initializeHPborder();
}
void Player::initializeHPfill()
{
  HPfill = new sf::RectangleShape;
  HPfill->setSize(sf::Vector2f(GAME_HP_LENGTH, GAME_HP_WIDTH));
  HPfill->setPosition(SCREEN_WIDTH * GAME_HP_INDEX_PERCENT_X, SCREEN_HEIGHT * GAME_HP_INDEX_PERCENT_Y);
  HPfill->setFillColor(GAME_HP_FILL_FILL_COLOR);
}
void Player::initializeHPborder()
{
  HPborder = new sf::RectangleShape;
  HPborder->setSize(HPfill->getSize());
  HPborder->setPosition(HPfill->getPosition());
  HPborder->setOutlineThickness(GAME_HP_BORDER_OUTLINE_THICKNESS);
  HPborder->setOutlineColor(GAME_HP_BORDER_BORDER_COLOR);
  HPborder->setFillColor(GAME_HP_BORDER_FILL_COLOR);
}
Player::~Player()
{
  delete bufferFire;
  delete bufferAttacked;
  delete soundAttacked;
  delete bufferDead;
  delete soundDead;

  delete HPborder;
  delete HPfill;

  deleteAllSoundFire();
}
void Player::operate()
{
  move(checkMoveAndBorder());
  if(checkFire() == SHELL_FIRE)
  {
    fire();
  }
  drawHPImage();
  window->draw(*(playerFighter->toDraw()));
}
void Player::drawHPImage()
{
  window->draw(*HPborder);
  window->draw(*HPfill);
}
bool Player::collision(Shell *target)
{
  int fighterIndexX = playerFighter->getPositionByVertex().position.x;
  int fighterIndexY = playerFighter->getPositionByVertex().position.y;
  if(collisionJudge(target, fighterIndexX, fighterIndexY) == COLLISION_KNOCKED)
  {
    return knockedOperate();
  }
  else
  {
    return COLLISION_UNKNOCKED;
  }
}
bool Player::collisionJudge(Shell *target, int x2, int y2)
{
  if(target->getOwner() != FIGHTER_OWNER_PLAYER)
  {
    int x1 = target->getPositionByVertex().position.x;
    int y1 = target->getPositionByVertex().position.y;
    int distance = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 -y2);
    if(distance <= COLLISION_KNOCK_DISTANCE)
    {
      return COLLISION_KNOCKED;
    }
    else
    {
      return COLLISION_UNKNOCKED;
    }
  }
  else
  {
    return COLLISION_UNKNOCKED;
  }
}
void Player::playFireSound()
{
  auto temp = new sf::Sound;
  temp->setBuffer(*bufferFire);
  soundFire.push_back(temp);
  temp->play();
  while(soundFire.size() > PLAYER_FIRE_MAX)
  {
    delete *(soundFire.begin());
    soundFire.erase(soundFire.begin());
  }
}
void Player::move(sf::Vertex deltaVector)
{
  playerFighter->move(deltaVector.position.x, deltaVector.position.y);
}
sf::Vertex Player::checkMoveAndBorder()
{
  int nowX = playerFighter->getPositionByVertex().position.x;
  if(sf::Keyboard::isKeyPressed(PLAYER_LEFT))
  {
    if(nowX + PLAYER_DELTA_LEFT >= SCREEN_MOST_LEFT + FIGHTER_SIZE_CORRECTED_VALUE_X)
    {
      return sf::Vector2f(PLAYER_DELTA_LEFT, PLAYER_DELTA_Y);
    }
  }
  if(sf::Keyboard::isKeyPressed(PLAYER_RIGHT))
  {
    if(nowX + PLAYER_DELTA_RIGHT <= SCREEN_MOST_RIGHT - FIGHTER_SIZE_CORRECTED_VALUE_X)
    {
      return sf::Vector2f(PLAYER_DELTA_RIGHT, PLAYER_DELTA_Y);
    }
  }
  else
  {
    return sf::Vector2f(PLAYER_DELTA_NO_MOVE, PLAYER_DELTA_Y);
  }
}
bool Player::checkFire()
{
  if(sf::Keyboard::isKeyPressed(PLAYER_FIRE))
  {
    return SHELL_FIRE;
  }
  else
  {
    return SHELL_UNFIRE;
  }
}
void Player::fire()
{
  // Shell *tempShell = playerFighter->fire(SHELL_SPEED_PLAYER_X, SHELL_SPEED_PLAYER_Y);
  // shellContainer->addShell(tempShell);
  std::vector<Shell *> newShellContainer = playerFighter->fire();
  for(auto it = newShellContainer.begin(); it != newShellContainer.end(); it++)
  {
    shellContainer->addShell(*it);
  }
  playFireSound();
}
bool Player::knockedOperate()
{
  playerFighter->reviseHP(COLLISION_HP_DELTA);

  auto HP = playerFighter->getHP();
  HPfill->setSize(sf::Vector2f((static_cast<float>(HP) / FIGHTER_HP_MAX) * GAME_HP_LENGTH, GAME_HP_WIDTH));

  auto isFighterDie = playerFighter->isFighterDie();
  if(isFighterDie == COLLISION_FIGHTER_DEAD)
  {
    soundDead->play();
    game->setGameStatus(GAME_STOP);
  }
  else
  {
    soundAttacked->play();
  }
  return COLLISION_KNOCKED;
}
void Player::deleteAllSoundFire()
{
  for(auto it = soundFire.begin(); it != soundFire.end();)
  {
    delete *it;
    soundFire.erase(it);
  }
}
