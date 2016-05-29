#ifndef PLAY_SOUND_H
#define PLAY_SOUND_H
#include <SFML/Audio.hpp>
#include "../head/GameConfig.h"
#include <vector>
class PlaySound
{
private:
  sf::SoundBuffer *fire;
  sf::SoundBuffer *attackedPlayer;
  sf::SoundBuffer *boom;
  sf::SoundBuffer *win;
  sf::SoundBuffer *lose;
  sf::SoundBuffer *BGM;
  std::vector<sf::Sound *> soundContainer;
  sf::Sound *soundBGM;
  sf::Sound *soundLose;
  void checkContainer();
  void addNewSound(sf::Sound *targetSound);
public:
  PlaySound();
  ~PlaySound();
  void playBoom();
  void playFire();
  void playWin();
  void playLose();
  void stopLose();
  void playAttackedPlayer();
  void playBGM();
  void stopBGM();
};
#endif
