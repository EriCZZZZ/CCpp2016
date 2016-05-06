OBJ = main.o ./classGraphics/FighterGraphics.o ./classGraphics/ShellGraphics.o\
 ./classShell/Shell.o ./classFighter/Fighter.o ./classFighter/PlayerFighter.o \
 ./classFighter/PlayerFighterFactory.o ./classFighter/EnemyFighter.o \
 ./classFighter/EnemyFighterFactory.o ./operation/Player.o ./operation/Enemy.o \
 ./operation/AllShell.o ./operation/CollisionJudge.o

edit: $(OBJ)

	g++ $(OBJ) -std=c++11 -g -o game.out \
	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

main.o : main.cpp ./operation/Player.o ./operation/Enemy.o \
	./operation/AllShell.o ./operation/CollisionJudge.o

	g++ -c -g -std=c++11 -o main.o main.cpp

./classGraphics/FighterGraphics.o : ./classGraphics/FighterGraphics.cpp \
	./head/GameConfig.h

	g++ -c -g -DDEBUG -std=c++11 -o ./classGraphics/FighterGraphics.o\
	 ./classGraphics/FighterGraphics.cpp

./classGraphics/ShellGraphics.o: ./classGraphics/ShellGraphics.cpp \
	./head/GameConfig.h

	g++ -c -g -DDEBUG -std=c++11 -o ./classGraphics/ShellGraphics.o \
	./classGraphics/ShellGraphics.cpp

./classShell/Shell.o: ./classShell/Shell.cpp

	g++ -c -g -DDEBUG -std=c++11 -o ./classShell/Shell.o \
	./classShell/Shell.cpp

./classFighter/Fighter.o : ./classFighter/Fighter.cpp ./classGraphics/FighterGraphics.o \
	./classShell/Shell.o

	g++ -c -g -DDEBUG -std=c++11 -o ./classFighter/Fighter.o  \
	./classFighter/Fighter.cpp

./classFighter/PlayerFighter.o : ./classFighter/PlayerFighter.cpp \
	./classFighter/Fighter.o

	g++ -c -g -DDEBUG -std=c++11 -o ./classFighter/PlayerFighter.o \
	./classFighter/PlayerFighter.cpp

./classFighter/PlayerFighterFactory.o : ./classFighter/PlayerFighterFactory.cpp \
	./classFighter/PlayerFighter.o

	g++ -c -g -DDEBUG -std=c++11 -o ./classFighter/PlayerFighterFactory.o \
	./classFighter/PlayerFighterFactory.cpp

./classFighter/EnemyFighter.o : ./classFighter/EnemyFighter.cpp \
	./classFighter/Fighter.o

	g++ -c -g -DDEBUG -std=c++11 -o ./classFighter/EnemyFighter.o \
	./classFighter/EnemyFighter.cpp

./classFighter/EnemyFighterFactory.o : ./classFighter/EnemyFighterFactory.cpp \
	./classFighter/EnemyFighter.o

	g++ -c -g -DDEBUG -std=c++11 -o ./classFighter/EnemyFighterFactory.o \
	./classFighter/EnemyFighterFactory.cpp

./operation/AllShell.o : ./operation/AllShell.cpp ./classShell/Shell.o

	g++ -c -g -DDEBUG -std=c++11 -o ./operation/AllShell.o \
	./operation/AllShell.cpp

./operation/Player.o : ./operation/Player.cpp ./operation/AllShell.o \
	./classFighter/PlayerFighterFactory.o

	g++ -c -g -DDEBUG -std=c++11 -o ./operation/Player.o \
	./operation/Player.cpp

./operation/Enemy.o : ./operation/Enemy.cpp ./operation/AllShell.o \
	./classFighter/EnemyFighterFactory.o

	g++ -c -g -DDEBUG -std=c++11 -o ./operation/Enemy.o \
	./operation/Enemy.cpp

./operation/CollisionJudge.o : ./operation/CollisionJudge.cpp \
	./operation/Player.o ./operation/Enemy.o ./operation/AllShell.o

	g++ -c -g -DDEBUG -std=c++11 -o ./operation/CollisionJudge.o \
	./operation/CollisionJudge.cpp

clean:
	-rm $(OBJ)
	-rm game.out

run:
	./game.out
