#include <iostream>
#include <random>
#include "Fantasma.h"
#include "Labirinto.h"

using namespace std;

Ghost::Ghost(){
    this->collidedPacman = 0;
    this->onPacdot = 1;
}

Ghost::~Ghost(){
    
}

int Ghost::getCollidedPacman(){
    return collidedPacman;
}

void Ghost::moveGhost(Labyrinth Labyrinth, Ghost Ghost, int r){
    default_random_engine gerador(r);
    int mov = 0;

    while (!this->verifyPosition(Labyrinth, Ghost, mov)) {
        /*MOVIMENTAÇÃO:
        1: cima 
        2: direita
        3: baixo
        4: esquerda*/
        uniform_int_distribution<int> distrI(1,4);
        mov = distrI(gerador);

        if(mov == 1){
            this->setPositionProx(this->getXant(), this->getYant() - 1);
        }
        else if(mov == 2){
            this->setPositionProx(this->getXant() + 1, this->getYant());
        }
        else if(mov == 3){
            this->setPositionProx(this->getXant(), this->getYant() + 1);
        }
        else { //mov == 4
            this->setPositionProx(this->getXant() - 1, this->getYant());
        }

        this->fixPosition(this->verifyCycle(Labyrinth), Labyrinth, this->getXprox(), this->getYprox());
    }

    if (this->verifyPosition(Labyrinth, Ghost, mov) == 1) {
        this->putGhost(Labyrinth, Ghost);
    }

    else if (this->verifyPosition(Labyrinth, Ghost, mov) == 2) {
        this->collidedPacman = 1;
        Labyrinth.updateLabyrinth(Labyrinth, 'X', this->getXprox(), this->getYprox()); 
    }

}



int Ghost::verifyPosition(Labyrinth Labyrinth, Ghost Ghost, int mov){ 
    char* lab;
    int lines;

    lab = Labyrinth.getLabyrinth();
    lines = Labyrinth.getLines();

    if(lab[this->getXprox() * lines + this->getYprox()] == '*' || lab[this->getXprox() * lines + this->getYprox()] == 'F' || mov == 0) 
        return 0;
    else if (lab[(this->getXprox() * lines) + this->getYprox()] == 'C') //colidiu com o Pacman.
        return 2;
    else
        return 1;
}

void Ghost::putGhost(Labyrinth Labyrinth, Ghost Ghost){
    char* lab = Labyrinth.getLabyrinth();
    int flag = 0, lines;

    lines = Labyrinth.getLines();

    if (lab[(lines * this->getXprox()) + this->getYprox()] == '.')
        flag = 1;

    Labyrinth.updateLabyrinth(Labyrinth, 'F', this->getXprox(), this->getYprox());

    if (this->getOnPacdot() == 1) {
        Labyrinth.updateLabyrinth(Labyrinth, '.', this->getXant(), this->getYant());
        this->onPacdot = 0;
    }
    else
        Labyrinth.updateLabyrinth(Labyrinth, ' ', this->getXant(), this->getYant());

    if (flag == 1)
        this->onPacdot = 1;

    this->setPositionAnt(this->getXprox(), this->getYprox());
}

int Ghost::getOnPacdot(){
    return onPacdot;
}