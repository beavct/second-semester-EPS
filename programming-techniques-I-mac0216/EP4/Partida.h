#pragma once
#include "Partida.h"
#include "Fantasma.h"
#include "Arquivo.h"
#include "Labirinto.h"
#include "Pacman.h"
#define MAX 256

/*!
* \brief  Match()
* \brief Função construtora da classe Match.
*/


/*!
* \brief  ~Match()
* \brief Função destrutora da classe Match.
*/


/*!
* \brief  void match()
* \brief A função instância o arquivo, labirinto, pacman e fantasmas. Inicializa as posições de todos os personagens.
* Posteriormente chama as funções da classe Ghost para que seja realizada a movimentação de cada um dos fantasmas. 
* Depois imprime o labirinto para que o usuário possa escolher para onde irá movimentar o Pacman.
* Assim chama a função da classe Pacman para que seja feita sua movimentação.
* Enquanto o Pac-man não é comido ou ainda haja pacdots no labirinto este loop é repetido.
* Caso o usuário perca o jogo uma mensagem de 'Game over' é impressa e também o labirinto, indicando com um 'X' o local em que ocorreu a colisão.
* Caso o usuário vença uma mensagem o parabenizando é impressa.
* Nos dois casos a pontuação final é impressa no terminal.
*/


/*!
* \brief  int setGhosts(char* labyrinth, Ghost Ghosts[MAX], int lines, int rows)
* \brief A função percorre o labirinto guardando a posição de cada um dos fantasmas.
* \param labyrinth (char*): Labirinto que será percorrido a procura de fantasmas.
* \param Ghost (Ghost[MAX]): Vetor de fantasmas onde será armazenada a informação de cada um dos fantasmas presentes no labirinto.
* \param lines (int): Quantidade de linhas do labirinto.
* \param rows (int): Quantidade de colunas do labirinto.
* \return retorno (int): Retorna a quantidade de fantasmas presente no labirinto.
*/

class Match{
    protected:
        int ghosts;
    public:
        Match();
        ~Match();
        void match();
        int setGhosts(char* labyrinth, Ghost Ghosts[MAX], int lines, int rows);
};