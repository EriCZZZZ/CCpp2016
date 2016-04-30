OBJ = main.o ./classGraphics/FighterGraphics.o ./classGraphics/ShellGraphics.o\
 ./classShell/Shell.o ./classFighter/Fighter.o ./classFighter/PlayerFighter.o \
 ./classFighter/PlayerFighterFactory.o
edit: $(OBJ)
	g++ $(OBJ) -std=c++11 -o game.out -pthread -L/home/eric/SFML/lib \
	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

main.o : main.cpp

	g++ -c -std=c++11 -o main.o -pthread -I/home/eric/SFML/include main.cpp

./classGraphics/FighterGraphics.o : ./classGraphics/FighterGraphics.cpp \
	./head/FighterGlobalConfig.h

	g++ -c -std=c++11 -o ./classGraphics/FighterGraphics.o -I/home/eric/SFML/include\
	 ./classGraphics/FighterGraphics.cpp

./classGraphics/ShellGraphics.o: ./classGraphics/ShellGraphics.cpp

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

clean:
	-rm $(OBJ)
	-rm game.out

run:
	./game.out
