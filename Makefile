# Macros

CXX = g++ -std=c++11
CFLAGS = -g -Wall -O2 
SRC = src/G2CNF.cpp src/Grammar.hpp src/Rule.hpp src/Production.hpp
OBJ = src/G2CNF.o src/Rule.o src/Grammar.o src/Production.o

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
		 ./G2CNF 1.gra 2.nfa

modif: #main.o
	   ./G2CNF 1.gra 2.nfa

