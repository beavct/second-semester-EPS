#include <iostream>
#include "Arquivo.h"
#include "Labirinto.h"
#include "Personagem.h"
#include "Pacman.h"
#include "Fantasma.h"
#include "Partida.h"
#include <gtest/gtest.h>
#define MAX 256

using namespace std;

#ifdef TESTES_ON
TEST(PacmanTest, PacmanSetRight) {
    File FTest;
    Labyrinth LabTest;
    Pacman PacTest;

    int x;
    int y;
    int lines;
    int rows;
    char fileName[256] = {'e', 'x', '1', '.', 't', 'x', 't'};

    LabTest.setLabyrinthTest(FTest, fileName);
    lines=LabTest.getLines();
    rows=LabTest.getRows();

    PacTest.setPositionAnt(lines/2, rows/2);


    x=PacTest.getXant();
    y=PacTest.getYant();

    ASSERT_EQ(lines, 31);
    ASSERT_EQ(rows, 27);

    ASSERT_EQ(x, 15);
    ASSERT_EQ(y, 13);    
}

#endif

int main (int argc, char **argv) {
    #ifdef TESTES_ON
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    
    return 0;
    #endif
        Match Match;
    Match.match();
    return 0;
}