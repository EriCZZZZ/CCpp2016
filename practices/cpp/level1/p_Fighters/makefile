OBJ = main.o ./classGraphics/FighterGraphics.o ./classGraphics/ShellGraphics.o \
 ./classSprite/Shell.o ./classFighter/Fighter.o ./classFighter/PlayerFighter.o \
 ./classFighter/PlayerFighterFactory.o ./classFighter/EnemyFighter.o \
 ./classFighter/EnemyFighterFactory.o ./operation/Player.o ./operation/Enemy.o \
 ./operation/SpriteContainer.o ./operation/CollisionJudge.o  ./classSprite/WeaponSingle.o\
 ./Game.o ./operation/ShowText.o ./BeatFighter.o ./classSprite/ShellFactory.o \
 ./classSprite/WeaponSpread.o ./operation/PlaySound.o

edit: $(OBJ)

	g++ $(OBJ) -std=c++11 -g -o game.out -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

# main.o : main.cpp ./operation/Player.o ./operation/Enemy.o ./operation/SpriteContainer.o ./operation/CollisionJudge.o
main.o : main.cpp BeatFighter.o

	g++ -c -g -std=c++11 -o main.o main.cpp

./BeatFighter.o : ./BeatFighter.cpp ./Game.o
	g++ -c -g -DDEBUG -std=c++11 -o ./BeatFighter.o ./BeatFighter.cpp

./Game.o : ./Game.cpp ./operation/SpriteContainer.o ./operation/CollisionJudge.o ./operation/Enemy.o ./operation/Player.o  ./operation/ShowText.o ./operation/PlaySound.o

	g++ -c -g -DDEBUG -std=c++11 -o ./Game.o ./Game.cpp

./operation/SpriteContainer.o : ./operation/SpriteContainer.cpp ./classSprite/Shell.o

	g++ -c -g -DDEBUG -std=c++11 -o ./operation/SpriteContainer.o ./operation/SpriteContainer.cpp

./classGraphics/FighterGraphics.o : ./classGraphics/FighterGraphics.cpp ./head/GameConfig.h

	g++ -c -g -DDEBUG -std=c++11 -o ./classGraphics/FighterGraphics.o ./classGraphics/FighterGraphics.cpp

./classGraphics/ShellGraphics.o : ./classGraphics/ShellGraphics.cpp ./head/GameConfig.h

	g++ -c -g -DDEBUG -std=c++11 -o ./classGraphics/ShellGraphics.o ./classGraphics/ShellGraphics.cpp

./classSprite/Shell.o : ./classSprite/Shell.cpp ./classGraphics/ShellGraphics.o ./classSprite/Sprite.h

	g++ -c -g -DDEBUG -std=c++11 -o ./classSprite/Shell.o ./classSprite/Shell.cpp

./classSprite/ShellFactory.o : ./classSprite/ShellFactory.cpp ./classSprite/Shell.o

	g++ -c -g -DDEBUG -std=c++11 -o ./classSprite/ShellFactory.o ./classSprite/ShellFactory.cpp

./classSprite/WeaponSingle.o : ./classSprite/WeaponSingle.cpp ./classSprite/Shell.o ./classSprite/ShellFactory.o

	g++ -c -g -DDEBUG -std=c++11 -o ./classSprite/WeaponSingle.o ./classSprite/WeaponSingle.cpp

./classSprite/WeaponSpread.o : ./classSprite/WeaponSpread.cpp ./classSprite/Shell.o ./classSprite/ShellFactory.o

	g++ -c -g -DDEBUG -std=c++11 -o ./classSprite/WeaponSpread.o ./classSprite/WeaponSpread.cpp

./classFighter/Fighter.o : ./classFighter/Fighter.cpp ./classGraphics/FighterGraphics.o ./classSprite/WeaponSingle.o

	g++ -c -g -DDEBUG -std=c++11 -o ./classFighter/Fighter.o ./classFighter/Fighter.cpp

./classFighter/PlayerFighter.o : ./classFighter/PlayerFighter.cpp ./classFighter/Fighter.o

	g++ -c -g -DDEBUG -std=c++11 -o ./classFighter/PlayerFighter.o ./classFighter/PlayerFighter.cpp

./classFighter/PlayerFighterFactory.o : ./classFighter/PlayerFighterFactory.cpp ./classFighter/PlayerFighter.o

	g++ -c -g -DDEBUG -std=c++11 -o ./classFighter/PlayerFighterFactory.o ./classFighter/PlayerFighterFactory.cpp

./classFighter/EnemyFighter.o : ./classFighter/EnemyFighter.cpp ./classFighter/Fighter.o ./classSprite/WeaponSingle.o

	g++ -c -g -DDEBUG -std=c++11 -o ./classFighter/EnemyFighter.o ./classFighter/EnemyFighter.cpp

./classFighter/EnemyFighterFactory.o : ./classFighter/EnemyFighterFactory.cpp ./classFighter/EnemyFighter.o

	g++ -c -g -DDEBUG -std=c++11 -o ./classFighter/EnemyFighterFactory.o ./classFighter/EnemyFighterFactory.cpp

./operation/Player.o : ./operation/Player.cpp ./operation/SpriteContainer.o ./classFighter/PlayerFighterFactory.o

	g++ -c -g -DDEBUG -std=c++11 -o ./operation/Player.o ./operation/Player.cpp

./operation/Enemy.o : ./operation/Enemy.cpp ./operation/SpriteContainer.o ./classFighter/EnemyFighterFactory.o

	g++ -c -g -DDEBUG -std=c++11 -o ./operation/Enemy.o ./operation/Enemy.cpp

./operation/CollisionJudge.o : ./operation/CollisionJudge.cpp ./operation/Player.o ./operation/Enemy.o ./operation/SpriteContainer.o

	g++ -c -g -DDEBUG -std=c++11 -o ./operation/CollisionJudge.o ./operation/CollisionJudge.cpp

./operation/ShowText.o : ./operation/ShowText.cpp

	g++ -c -g -DDEBUG -std=c++11 -o ./operation/ShowText.o ./operation/ShowText.cpp

./operation/PlaySound.o : ./operation/PlaySound.cpp

	g++ -c -g -DDEBUG -std=c++11 -o ./operation/PlaySound.o ./operation/PlaySound.cpp

clean:
	-rm $(OBJ)
	-rm game.out

run:
	./game.out
