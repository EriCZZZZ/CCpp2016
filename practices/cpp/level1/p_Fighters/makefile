OBJ = main.o ./classGraphics/FighterGraphics.o ./classGraphics/ShellGraphics.o\
 ./classShell/Shell.o ./classFighter/Fighter.o ./classFighter/PlayerFighter.o \
 ./classFighter/PlayerFighterFactory.o ./classFighter/EnemyFighter.o \
 ./classFighter/EnemyFighterFactory.o ./operation/Player.o
edit: $(OBJ)
	g++ $(OBJ) -std=c++11 -o game.out -pthread -L/home/eric/SFML/lib \
	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

main.o : main.cpp

	g++ -c -std=c++11 -o main.o -pthread -I/home/eric/SFML/include main.cpp

./classGraphics/FighterGraphics.o : ./classGraphics/FighterGraphics.cpp \
	./head/FighterGlobalConfig.h

	g++ -c -std=c++11 -o ./classGraphics/FighterGraphics.o -I/home/eric/SFML/include\
	 ./classGraphics/FighterGraphics.cpp

./classGraphics/ShellGraphics.o: ./classGraphics/ShellGraphics.cpp \
	./head/ShellGlobalConfig.h

	g++ -c -std=c++11 -o ./classGraphics/ShellGraphics.o -I/home/eric/SFML/include \
	./classGraphics/ShellGraphics.cpp

./classShell/Shell.o: ./classShell/Shell.cpp

	g++ -c -std=c++11 -o ./classShell/Shell.o -I/home/eric/SFML/include \
	./classShell/Shell.cpp

./classFighter/Fighter.o : ./classFighter/Fighter.cpp ./classGraphics/FighterGraphics.o \
	./classShell/Shell.o

	g++ -c -std=c++11 -o ./classFighter/Fighter.o -I/home/eric/SFML/include  \
	./classFighter/Fighter.cpp

./classFighter/PlayerFighter.o : ./classFighter/PlayerFighter.cpp \
	./classFighter/Fighter.o

	g++ -c -std=c++11 -o ./classFighter/PlayerFighter.o -I/home/eric/SFML/include \
	./classFighter/PlayerFighter.cpp

./classFighter/PlayerFighterFactory.o : ./classFighter/PlayerFighterFactory.cpp \
	./classFighter/PlayerFighter.o

	g++ -c -std=c++11 -o ./classFighter/PlayerFighterFactory.o -I/home/eric/SFML/include \
	./classFighter/PlayerFighterFactory.cpp

./classFighter/EnemyFighter.o : ./classFighter/EnemyFighter.cpp \
	./classFighter/Fighter.o

	g++ -c -std=c++11 -o ./classFighter/EnemyFighter.o -I/home/eric/SFML/include \
	./classFighter/EnemyFighter.cpp

./classFighter/EnemyFighterFactory.o : ./classFighter/EnemyFighterFactory.cpp \
	./classFighter/EnemyFighter.o

	g++ -c -std=c++11 -o ./classFighter/EnemyFighterFactory.o -I/home/eric/SFML/include \
	./classFighter/EnemyFighterFactory.cpp

# ./operation/Player.o : ./operation/Player.cpp ./operation/AllShell.o \
# 	./classFighter/PlayerFighterFactory.o
./operation/Player.o : ./operation/Player.cpp ./classFighter/PlayerFighterFactory.o

	g++ -c -std=c++11 -o ./operation/Player.o -I/home/eric/SFML/include \
	./operation/Player.cpp

clean:
	-rm $(OBJ)
	-rm game.out

run:
	./game.out
