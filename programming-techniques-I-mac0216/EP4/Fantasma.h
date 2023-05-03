#pragma once
#include "Personagem.h"
#include "Labirinto.h"

/*!
* \brief  Ghost()
* \brief Função construtora da classe Ghost. Inicializa o atributo 'collidedPacman' como 0 e o atributo 'onPacdot' = 1.
*/


/*!
* \brief  ~Ghost()
* \brief Função destrutora da classe Ghost.
*/


/*!
* \brief  int getOnPacdot()
* \brief Retorna o valor do atrivuto 'onPacdot' que indica se a posição ocupada pelo fantasma no labirinto possui um pacdot que deve ser reposto quando o fantasma mudar de posição ou não.
* \return retorno (int): Retorna o valor da flag 'onPacdot' que terá valor 1 caso o fantasma esteja sob um pacdot e 0 caso contrário.
*/


/*!
* \brief  int getCollidedPacman()
* \brief Retorna o valor do atributo 'collidedPacman' que indica se o fantasma atingiu o Pac-man ou não.
* \return retorno (int): Retorna o valor da flag 'collidedPacman' que será 1 caso tenha colidido com o Pac-man e 0 caso contrário.
*/


/*!
* \brief  void moveGhost(Labyrinth Labyrinth, Ghost Ghost)
* \brief Utiliza a biblioteca 'random' para gerar um número pseudoaleatória de 1-4, onde cada um desses indica uma movimentação.
* 1 para se mover para cima, 2 para a direita, 3 para a baixo e 4 para a esquerda. 
* Depois, caso a posição tenha 'saído' do labirinto por conta do ciclo, ela é arrumada.
* Aṕos a geração da nova posição do fantasma, é verificado se não há nenhum obtáculo já ocupando essa posição chamando a função verifyPosition(). 
* Caso não haja nenhum obstáculo, o fantasma é movido, e caso o Pacman esteja nessa posição, um X é marcado onde ocorreu a colisão.
* \param Labyrinth (Labyrinth): Labirinto no qual o fantasma será movimentado.
* \param Ghost (Ghost): Indica o fantasma no vetor de fantasmas, criado na partida, que será movimentado no labirinto. 
* \param seed (int): Semente que será utilizada para a geração do movimento pseudoaleatório.
*/


/*!
* \brief  int verifyPosition(Labyrinth Labyrinth, Ghost Ghost)
* \brief Verifica se será posível a movimentação do fantasma na posição indicada de maneira pseudoaleatória.
* Álem disso, também verifica se houve colisão com o Pac-man.
* \param Labyrinth (Labyrinth): Labirinto no qual se deseja realizar a movimentação e referência para a verificação.
* \param Ghost (Ghost): Fantasma o qual terá a posição posterior verificada.
* \param mov (int): Movimento que foi gerado de forma aleatória.
* \return retorno (int): Retorna 1 caso seja possível fzer a movimentação, 0 caso contrário e 2 caso tenha ocorrido colisão com o Pac-man.
*/


/*!
* \brief  void putGhost(Labyrinth Labyrinth, Ghost Ghost)
* \brief A função é responsável por mover o fantasma para a próxima posição indicada, e na posição anterior recolocar um pacdot caso seja necessário.
* \param Labyrinth (Labyrinth): Labirinto que será modificado.
* \param Ghost (Ghost): Fantasma que será movido no labirnto.
*/

class Ghost: public Character {
    protected:
        int xAnt;
        int yAnt;
        int xProx;
        int yProx;
        int onPacdot;
        int collidedPacman;
    public:
        Ghost();
        ~Ghost();
        int getOnPacdot();
        int getCollidedPacman();
        void moveGhost(Labyrinth Labyrinth, Ghost Ghost, int r);
        int verifyPosition(Labyrinth Labyrinth, Ghost Ghost, int mov);
        void putGhost(Labyrinth Labyrinth, Ghost Ghost);
};