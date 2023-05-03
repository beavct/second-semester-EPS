#include <iostream>
#include <fstream> 
#include "Arquivo.h"
#define MAX 256

using namespace std;

File::File(){

}

File::~File(){

}

char* File::readLabyrinth() {
    fstream labyrinthFile;
    int i, j, size;
    char fileName[MAX];
    
    cout << "Digite o nome do arquivo do labirinto: ";

    cin >> fileName;

    labyrinthFile.open(fileName, ios::in); 

    labyrinthFile >> this->lines;
    labyrinthFile >> this->rows;
    size = this->lines * this->rows;

    char* labyrinth = (char*)calloc(size,sizeof(char) * (size));

    for (i = 0; i < this->lines; i++) {
        for (j = 0; j < this->rows; j++) {
            if ((i != this->lines/2) || (j != this->rows/2)) 
                labyrinthFile >> labyrinth[(this->lines * i) + j];
            else 
                labyrinth[(this->lines * i) + j] = 'C';
        }
    }

    labyrinthFile.close();

    return labyrinth; 
}

char* File::readLabyrinthTest(char fileName[MAX]){
    fstream labyrinthFile;
    int i, j, size;

    labyrinthFile.open(fileName, ios::in); 

    labyrinthFile >> this->lines;
    labyrinthFile >> this->rows;
    size = this->lines * this->rows;

    char* labyrinth = (char*)calloc(size,sizeof(char) * (size));

    for (i = 0; i < this->lines; i++) {
        for (j = 0; j < this->rows; j++) {
            if ((i != this->lines/2) || (j != this->rows/2)) 
                labyrinthFile >> labyrinth[(this->lines * i) + j];
            else 
                labyrinth[(this->lines * i) + j] = 'C';
        }
    }

    labyrinthFile.close();

    return labyrinth;     
}

int File::getLines() {
    return lines;
}

int File::getRows() {
    return rows;
}
