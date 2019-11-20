CC = g++
CXXFLAGS = -g -Wfatal-errors -std=c++11
ARGS= pactica.dfa perry

OBJS = src/Transition.o src/State.o src/Dfa.o src/Main.o src/Production.o src/Rule.o src/Grammar.o

all:${OBJS}
	$(CC) $(CXXFLAGS) -o grammar ${OBJS}


clean:
	rm -rf src/*.o grammar html/ latex/ *.grammar

run:
	./grammar ${ARGS}

doxy:
	@doxygen doxyconf