#include <iostream>
#include "Partida.h"
#include "Fantasma.h"
#include "Arquivo.h"
#include "Labirinto.h"
#include "Pacman.h"
#define MAX 256

using namespace std;

Match::Match(){

}

Match::~Match(){

}

void Match::match(){
    File File;
    Labyrinth Labyrinth;
    Pacman Pacman;
    Ghost Ghosts[MAX];
    Match Match;
    int ghostsQnt, lines, rows, i, Continue = 1, totalPacdots, r = 0;
    char* lab;

    Labyrinth.setLabyrinth(File);
    lab = Labyrinth.getLabyrinth();
    lines = Labyrinth.getLines();
    rows = Labyrinth.getRows();
    ghostsQnt = this->setGhosts(lab, Ghosts, lines, rows);

    totalPacdots = Labyrinth.getPacdots() + ghostsQnt;

    Pacman.setPositionAnt(lines/2, rows/2);

    while(totalPacdots - Pacman.getEatedPacdots() != 0 && Continue == 1) {

        //move os fantasmas
        for(i = 0; i < ghostsQnt && Continue == 1; i++) {
            Ghosts[i].moveGhost(Labyrinth, Ghosts[i], r);
            r++;

            if(Ghosts[i].getCollidedPacman()) {
                Continue = 0; //perdeu a partida
            }    
        }

        cout << endl << endl;
        Labyrinth.printLabyrinth();
        cout << endl;

        //move o pacman
        if(Continue){
            Pacman.movePacman(Labyrinth, Pacman);

            if(Pacman.getCollidedGhost())
                Continue = 0;
        }   
    }

    if(!Continue){
        Labyrinth.printLabyrinth();
        cout << "Game over! Pontos = " << Pacman.getEatedPacdots() << endl;
    }
    else{ //Continue == 2
        Labyrinth.printLabyrinth();
        cout << "Congratulations! Pontos = " << Pacman.getEatedPacdots() << endl;
    }
}

int Match::setGhosts(char* labyrinth, Ghost Ghosts[MAX], int lines, int rows){
    int i, j, k = 0;

    for(i = 0; i < lines; i++) {
        for(j = 0; j < rows; j++){
            if(labyrinth[(lines * i) + j] == 'F'){
                Ghosts[k].setPositionAnt(i, j);
                k++;
            }
        }
    }
    return k;
}