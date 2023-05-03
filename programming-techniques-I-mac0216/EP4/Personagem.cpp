#include <iostream>
#include "Personagem.h"
#include "Labirinto.h"

using namespace std;

Character::Character(){

}

Character::~Character(){
    
}

void Character::setPositionAnt(int x, int y){
    this->xAnt = x;
    this->yAnt = y;
}

void Character::setPositionProx(int x, int y){
    this->xProx = x;
    this->yProx = y;
}

int Character::getXant(){
    return xAnt;
}

int Character::getYant(){
    return yAnt;
}

int Character::getXprox(){
    return xProx;
}

int Character::getYprox(){
    return yProx;
}

int Character::verifyCycle(Labyrinth Labyrinth){
    int lines, rows;

    lines = Labyrinth.getLines();
    rows = Labyrinth.getRows();

    if (this->xProx < 0) //Foi para cima do tabuleiro, ou seja, na próx rodada tem que ir para a última linha.
        return 1; 
    else if(this->xProx > lines) //Foi para baixo do tabuleiro, ou seja, na próx rodada tem que ir para a primeira linha.
        return 2;
    else if (this->yProx < 0) //Foi para esquerda do tabuleiro, ou seja, na próx rodada tem que ir para a última coluna.
        return 3;
    else if (this->yProx > rows) //Foi para a direita do tabuleiro, ou seja, na próx rodada tem que ir para a primeira coluna.
        return 4;
    else
        return 0; //Se ta tudo ok e não precisa mudar a posição por conta do ciclo.
}

void Character::fixPosition(int error, Labyrinth Labyrinth, int x, int y) {
    int lines, rows;

    lines = Labyrinth.getLines();
    rows = Labyrinth.getRows();

    if(error == 1) 
        this->setPositionProx(lines - 1, y);
    else if(error == 2)
        this->setPositionProx(0, y);
    else if(error == 3) 
        this->setPositionProx(x, rows - 1);
    else if(error == 4)
        this->setPositionProx(x, 0);
}