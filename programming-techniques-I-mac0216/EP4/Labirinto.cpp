#include <iostream>
#include "Labirinto.h"
#include "Arquivo.h"
#include "Personagem.h"
#include "Fantasma.h"
#include "Pacman.h"
#define MAX 256

using namespace std;

Labyrinth::Labyrinth(){

}

Labyrinth::~Labyrinth(){

}

int Labyrinth::getPacdots() {
    int i, j, k = 0;
    for(i = 0; i < this->lines; i++)
        for(j = 0; j < this->rows; j++)
            if(this->labyrinth[(this->lines * i) + j] == '.')
                k++;

    return k;
}

void Labyrinth::printLabyrinth() {
    int i, j;

    for (i = 0; i < this->lines; i++) {
        for (j = 0; j < this->rows; j++) {
            cout << this->labyrinth[(this->lines * i) + j];             
        }
       cout << endl;
    }

}


void Labyrinth::setLabyrinth(File file) {
    this->labyrinth = file.readLabyrinth();
    this->lines = file.getLines();
    this->rows = file.getRows();
    this->pacdots = this->getPacdots();
}

void Labyrinth::setLabyrinthTest(File FTest, char fileName[256]){
    this->labyrinth = FTest.readLabyrinthTest(fileName);
    this->lines = FTest.getLines();
    this->rows = FTest.getRows();
    this->pacdots = this->getPacdots();    
}

char* Labyrinth::getLabyrinth(){
    return labyrinth;
}

int Labyrinth::getLines() {
    return lines;
}

int Labyrinth::getRows() {
    return rows;
}

void Labyrinth::updateLabyrinth(Labyrinth Labyrinth, char object, int x, int y){
    if (object == 'C' && Labyrinth.labyrinth[(Labyrinth.getLines() * x) + y] == '.')
        this->pacdots--;

    Labyrinth.labyrinth[(Labyrinth.getLines() * x) + y] = object;
}