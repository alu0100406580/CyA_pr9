# Macros

CXX = g++ -std=c++11
CFLAGS = -g #-Wall -O2
SRC = src/G2CNF.cpp src/Grammar.hpp src/Production.hpp #src/Rule.hpp
OBJ = src/G2CNF.o src/Grammar.o src/Production.o #src/Rule.o

# Reglas explícitas

all: ${OBJ}
		 $(CXX) $(CFLAGS) -o G2CNF $(OBJ)
		 mv src/*.o obj/

clean:
		 $(RM) obj/* main src/*.o

 # Reglas implícitas

main.o: src/main.cpp

run: #main.o
		 ./G2CNF

ejec: #main.o
		 ./G2CNF 1.gra fnc

modif: #main.o
	   ./G2CNF 1.gra fnc

