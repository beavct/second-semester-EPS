#include <iostream>
#include "Pacman.h"
#include "Personagem.h"
#include "Labirinto.h"

using namespace std;

Pacman::Pacman(){
    this->eatedPacdots = 0;
    this->collidedGhost = 0;
}

Pacman::~Pacman(){

}

int Pacman::getCollidedGhost(){
    return collidedGhost;
}

int Pacman::getEatedPacdots(){
    return eatedPacdots;
}

void Pacman::movePacman(Labyrinth Labyrinth, Pacman Pacman){
    char mov;
    int flag = 0;

    while (flag == 0) {
        cout << "Direção (a - esquerda, d - direita, w - cima, s - baixo): ";
        cin >> mov;

        if (mov == 'w')
            Pacman.setPositionProx(Pacman.getXant() - 1, Pacman.getYant());
        else if(mov == 'a')
            Pacman.setPositionProx(Pacman.getXant(), Pacman.getYant() - 1);
        else if(mov == 's')
            Pacman.setPositionProx(Pacman.getXant() + 1, Pacman.getYant());
        else  //mov == 'd'
            Pacman.setPositionProx(Pacman.getXant(), Pacman.getYant() + 1);

        flag = this->verifyPosition(Labyrinth, Pacman);
    }

    if (flag == 2) {
        Labyrinth.updateLabyrinth(Labyrinth, ' ', Pacman.getXant(), Pacman.getYant());
        Labyrinth.updateLabyrinth(Labyrinth, 'X', Pacman.getXprox(), Pacman.getYprox());
    }
    else if(flag == 1){
        Pacman.fixPosition(Pacman.verifyCycle(Labyrinth), Labyrinth, Pacman.getXprox(), Pacman.getYprox());
        this->putPacman(Labyrinth, Pacman);
    }
}

void Pacman::putPacman(Labyrinth Labyrinth, Pacman Pacman){
    Labyrinth.updateLabyrinth(Labyrinth, ' ', Pacman.getXant(), Pacman.getYant());
    Labyrinth.updateLabyrinth(Labyrinth, 'C', Pacman.getXprox(), Pacman.getYprox());

    this->setPositionAnt(Pacman.getXprox(), Pacman.getYprox());
}

int Pacman::verifyPosition(Labyrinth Labyrinth, Pacman Pacman){
    char* lab = Labyrinth.getLabyrinth();
    int lines = Labyrinth.getLines();

    if(lab[(lines * Pacman.getXprox()) + Pacman.getYprox()] == '*')
        return 0;
    else if(lab[(lines * Pacman.getXprox()) + Pacman.getYprox()] == '.')
        this->eatedPacdots++;
    else if(lab[(lines * Pacman.getXprox()) + Pacman.getYprox()] == 'F') {
        this->collidedGhost = 1;
        return 2;
    }
    return 1;
}