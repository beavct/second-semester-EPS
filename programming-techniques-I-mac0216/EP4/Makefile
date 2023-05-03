PP=g++
TESTFLAGS= -lgtest -lpthread
COMPFLAGS= -Wall
DOC=doxygen
OTHERS= Partida.cpp Arquivo.cpp Labirinto.cpp Personagem.cpp Pacman.cpp Fantasma.cpp

###################################################################################

OBJS = Partida.o Arquivo.o Labirinto.o Personagem.o Pacman.o Fantasma.o
DOXY=Doxyfile
MAIN=ep4.cpp

###################################################################################

.PHONY: clean

all: game

Partida.o: Partida.h
Arquivo.o: Arquivo.h 
Labirinto.o: Labirinto.h 
Personagem.o: Personagem.h 
Pacman.o: Pacman.h
Fantasma.o: Fantasma.h

ep4.o: ep4.cpp

game: ${OBJS}
		${PP} ${COMPFLAGS} -o game ${MAIN} ${OTHERS}

tests: gameTests

gameTests: ${OBJS} ${MAIN}
		${PP} ${COMPFLAGS} -o game ${MAIN} ${OTHERS} ${TESTFLAGS} -DTESTES_ON
		
doc:
	${DOC} ${DOXY}

clean:
	@rm -rf game *.o html 
