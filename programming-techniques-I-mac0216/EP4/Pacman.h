#pragma once
#include "Personagem.h"
#include "Labirinto.h"

/*!
* \brief  Pacman()
* \brief Função contrutora da classe. Inicializa a quantidade de pacdots comidos (eatedPacdots) e a flag de colisão com o fantasma como 0.
*/


/*!
* \brief  ~Pacman()
* \brief Função destrutora da classe.
*/


/*!
* \brief  int getCollidedGhost()
* \brief A função retorna o atributo da classe "collidedGhost", que indica se o Pac-man colidiu ou não com algum fantasma no jogo.
* 
* \return retorno (int): retorna 1 caso o Pac-man tenha colidido com um fantasma e 0 caso contrário.
*/


/*!
* \brief  getEatedPacdots()
* \brief A função retorna o atributo da classe "eatedPacdots", que indica a quantidade de pacdots que o Pac-man já comeu.
*
* \return retorno (int): A quantidade de pacdots já comida pelo Pac-man.
*/


/*!
* \brief  void movePacman(Labyrinth Labyrinth, Pacman Pacman)
* \brief A função é responsável por realizar a movimentação do Pac-man no labirinto, para isto, imprimi o prompt no terminal para que o usuário indique o movimento desejado(esquerda, direita, baixo, cima).
* Aṕos isso verifica se a posição indicada pelo usuário é uma posição válida - ou seja, se não possui uma parede no caminho - chamando a função verifyPosition().
* Caso haja uma parede no caminho, imprimi o promp de novo para que o usuário insira um movimento válido, caso haja colisão com um fantasma, marca o lugar em que ocorreu a colisão, e caso o movimento seja válido, move o Pac-man.
*
* \param Labyrinth (Labyrinth): Labirinto o qual o Pac-man se encontra e que receberá a movimentação.
* \param Pacman (Pacman): Pac-man que será movimentado.
*/


/*!
* \brief  int verifyPosition(Labyrinth Labyrinth, Pacman Pacman)
* \brief Verifica se há algo na pŕoxima posição do Pacman, como uma parede, pacdot ou fantasma.
*
* \param Labyrinth (Labyrinth): O mapa de referência para a verificação da posição do Pac-man.
* \param Pacman (Pacman): O Pac-man no o qual a posição será verificada.
* \return retorno (int): Retorna 0 caso haja uma parede, 1 caso o movimento seja permitido e 2 caso ocorrá colisão com algum fantasma.
* caso haja colição com um fantasma.
*/


/*!
* \brief  void putPacman(Labyrinth Labyrinth, Pacman Pacman)
* \brief É responsável por colocar o Pac-man na pŕoxima posição indicada e limpar o espaço em que este estava anteriormente.
*
* \param Labyrinth (Labyrinth): Labirinto que será alterado.
* \param Pacman (Pacman): Pac-man o qual serão verificadas as posições anterior e posterior para que o labirinto seja algerado.
*/



class Pacman: public Character {
    protected:
        int xAnt;
        int yAnt;
        int xProx;
        int yProx;
        int eatedPacdots;
        int collidedGhost;
    public:
        Pacman();
        ~Pacman();
        int getCollidedGhost();
        int getEatedPacdots();
        void movePacman(Labyrinth Labyrinth, Pacman Pacman);
        int verifyPosition(Labyrinth Labyrinth, Pacman Pacman);
        void putPacman(Labyrinth Labyrinth, Pacman Pacman);
};