#include "PlaySound.h"
PlaySound::PlaySound()
{
  fire = new sf::SoundBuffer;
  fire->loadFromFile(SOUND_FIRE);

  attackedPlayer = new sf::SoundBuffer;
  attackedPlayer->loadFromFile(SOUND_ATTACKED);

  lose = new sf::SoundBuffer;
  lose->loadFromFile(SOUND_DEAD);
  soundLose = new sf::Sound;
  soundLose->setBuffer(*lose);
  soundLose->setLoop(true);

  win = new sf::SoundBuffer;
  /*todo
  ==========add win sound buffer=========
  */

  boom = new sf::SoundBuffer;
  boom->loadFromFile(SOUND_BOOM);

  BGM = new sf::SoundBuffer;
  BGM->loadFromFile(SOUND_BGM);
  soundBGM = new sf::Sound;
  soundBGM->setBuffer(*BGM);
  soundBGM->setLoop(true);
}
PlaySound::~PlaySound()
{
  delete fire;
  delete attackedPlayer;
  delete boom;
  delete win;
  delete lose;
  delete BGM;

  stopLose();
  stopBGM();
  delete soundBGM;
  delete soundLose;

  for(auto it = soundContainer.begin(); it != soundContainer.end(); it++)
  {
    delete (*it);
  }
}
void PlaySound::checkContainer()
{
  while(soundContainer.size() > SOUND_CONTAINER_MAX)
  {
    delete *(soundContainer.begin());
    soundContainer.erase(soundContainer.begin());
  }
}
void PlaySound::addNewSound(sf::Sound *targetSound)
{
  targetSound->play();
  soundContainer.push_back(targetSound);
}
void PlaySound::playAttackedPlayer()
{
  sf::Sound *temp = new sf::Sound;
  temp->setBuffer(*attackedPlayer);
  checkContainer();
  addNewSound(temp);
}
void PlaySound::playBoom()
{
  sf::Sound *temp = new sf::Sound;
  temp->setBuffer(*boom);
  checkContainer();
  addNewSound(temp);
}
void PlaySound::playFire()
{
  sf::Sound *temp = new sf::Sound;
  temp->setBuffer(*fire);
  checkContainer();
  addNewSound(temp);
}
void PlaySound::playWin()
{
  ;
}
void PlaySound::playLose()
{
  soundLose->play();
}
void PlaySound::stopLose()
{
  soundLose->stop();
}
void PlaySound::playBGM()
{
  soundBGM->play();
}
void PlaySound::stopBGM()
{
  soundBGM->stop();
}
