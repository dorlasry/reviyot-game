#All Targets 
all: reviiot

#Tool invocations
#Executable "reviiot" depends on the files reviiot.o and reviiyot.o 
reviiot: bin/Card.o bin/Deck.o bin/Hand.o bin/Player.o bin/Game.o bin/reviiyot.o

	@echo 'Building target: reviiot'
	@echo 'Invoking: C++ Linker'
	g++ -o bin/reviiot  bin/Card.o bin/Deck.o bin/Hand.o bin/Player.o bin/Game.o bin/reviiyot.o
	@echo 'Finished building target: reviiot'

#depends on the source and header files
bin/Card.o: src/Card.cpp
	g++ -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Card.o src/Card.cpp

#depends on the source and header files
bin/Deck.o: src/Deck.cpp
	g++ -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Deck.o src/Deck.cpp

#depends on the source and header files
bin/Hand.o: src/Hand.cpp
	g++ -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Hand.o src/Hand.cpp

#depends on the source and header files
bin/Player.o: src/Player.cpp
	g++ -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Player.o src/Player.cpp

#depends on the source and header files
bin/Game.o: src/Game.cpp
	g++ -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Game.o src/Game.cpp
	
#depends on the source and header files
bin/reviiyot.o: src/reviiyot.cpp
	g++ -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/reviiyot.o src/reviiyot.cpp

#clean the build directory
clean:
	rm -f bin/*
	
	

