#pragma once
#include "Arquivo.h"

/*!
* \brief  Labyrinth()
* \brief Função construtora da classe Labyrinth;
*/


/*!
* \brief  ~Labyrinth()
* \brief Função destrutora da classe Labyrinth;
*/


/*!
* \brief  void setLabyrinth(File file)
* \brief A função instância um objeto do tipo File e a partir dela pega o vetor que representa o labirinto, a quantidade de linha e colunas, e já guarda a quantidade inicial de pacdots no labirinto.
* \param file (File): Arquivo de onde serão pegas informações como o próprio labirinto, a quantidade de linhas e colunas.
*/


/*!
* \brief  void setLabyrinthTest(File FTest, char fileName[256])
* \brief A função instância um objeto do tipo File e a partir dela pega o vetor que representa o labirinto, a quantidade de linha e colunas, e já guarda a quantidade inicial de pacdots no labirinto.
* Ela é utilizada somente durante os testes.
* \param file (File): Arquivo de onde serão pegas informações como o próprio labirinto, a quantidade de linhas e colunas, no caso o arquivo é aquele nomeado como 'ex1.txt'.
* \param filename (char[256]): Nome do arquivo será feita a leitura do labirinto e da quantidade de linhas e colunas.
*/


/*!
* \brief  char* getLabyrinth()
* \brief A função retorna o atributo 'labyrinth' da classe.
* \return retorno (char*): Retorna o labirinto salvo como um atributo da classe.
*/


/*!
* \brief  void printLabyrinth()
* \brief A função percorre o labirinto o imprimindo no terminal.
*/


/*!
* \brief  void updateLabyrinth(Labyrinth Labyrinth, char object, int x, int y)
* \brief A função recebe um objeto que pode ser o Pac-man 'C', um fantasma 'F', um pacdor '.' ou um espaço vazio ' ' e o coloca na posição indicada no labirinto.
* \param Labyrinth (Labyrinth): Labirinto onde serão realizadas as modificações
* \param object (char): Objeto que deve ser colocado na posição indicada.
* \param x (int): Coordenada x da posição que deve ser alterada no labirinto.
* \param y (int): Coordenada y da posição que deve ser alterada no labirinto.
*/


/*!
* \brief  int getLines()
* \brief Retorna o valor do atrivuto 'lines' que indica a quantidade de linhas do labirinto.
* \return retorno (int): Quantidade de linhas do labirinto.
*/


/*!
* \brief  int getRows()
* \brief Retorna o valor do atributo 'rows' que indica a quantidade de colunas do labirinto.
* \return retorno (int): Quantidade de linhas do labirinto.
*/


/*!
* \brief  int getPacdots()
* \brief Percorre todo o labirinto contando os pacdots restantes.
* \return retorno (int): Retorna a quantidade de pacdots restantes no labirinto.
*/


class Labyrinth {
    protected:
        int lines;
        int rows;
        int pacdots;
        char* labyrinth;
    public: 
        Labyrinth();
        ~Labyrinth();
        void setLabyrinth(File file);
        void setLabyrinthTest(File FTest, char fileName[256]);
        char* getLabyrinth();
        void printLabyrinth();      
        void updateLabyrinth(Labyrinth Labyrinth, char object, int x, int y);          
        int getLines();
        int getRows(); 
        int getPacdots();
};