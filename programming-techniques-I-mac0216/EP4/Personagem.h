#pragma once
#include "Labirinto.h"

/*!
* \brief  Character()
* \brief Função construtora da classe Character.
*/


/*!
* \brief  ~Character()
* \brief Função destrutora da classe Character.
*/


/*!
* \brief  void setPositionAnt(int x, int y)
* \brief Define a posição anterior do personagem pelas coordenadas dadas como parâmetros da função.
* \param x (int): Coordenada x que se deseja atribuir à classe na posição anterior.
* \param y (int): Coordenada y que se deseja atribuir à classe na posição anterior.
*/


/*!
* \brief  void setPositionProx(int x, int y)
* \brief Define a posição posterior do personagem pelas coordenadas dadas como parâmetros da função.
* \param x (int): Coordenada x que se deseja atribuir à classe na posição posterior.
* \param y (int): Coordenada y que se deseja atribuir à classe na posição posterior.
*/


/*!
* \brief  int getXant()
* \brief A função retorna o valor do atributo 'xAnt' do personagem.
* \return retorno (int): A posição x anterior do personagem.
*/


/*!
* \brief  int getXprox()
* \brief A função retorna o valor do atributo 'xProx' do personagem.
* \return retorno (int): A posição x posterior do personagem.
*/


/*!
* \brief  int getYant()
* \brief A função retorna o valor do atributo 'yAnt' do personagem.
* \return retorno (int): A posição y anterior do personagem.
*/


/*!
* \brief  int getYprox()
* \brief A função retorna o valor do atributo 'yProx' do personagem.
* \return retorno (int): A posição y posterior do personagem.
*/


/*!
* \brief  int verifyCycle(Labyrinth Labyrinth)
* \brief A função verifica se a próxima posição que o personagem deve ocupar esta dentro do labirinto. 
* Caso não esteja devolve o erro correspondente para que a posição seja colocada dentro do ciclo.
* \return retorno (int): Retorna 1 caso o personagem esteja para cima do labirinto, 2 caso esteja abaixo, 3 se estiver à esquerda, 4 se estiver à direita e 0 se estiver dentro.
*/


/*!
* \brief  void fixPosition(int error, Labyrinth Labyrinth, int x, int y)
* \brief A partir do retorno fa função verifyCycle() arruma a posição do personagem para que permaneça dentro do labirinto e respeite o ciclo.
* \param error (int): O erro corresponde à posição posterior do personagem e como esta deve ser arrumada.
* \param Labyrinth (Labyrinth): Labirinto que será utilizado de referência para a quantidade de linhas e colunas.
* \param x (int): Coordenada x da próxima posição do personagem.
* \param y (int): Coordenada y da próxima posição do personagem.
*/

class Character {
    protected:
        int xAnt;
        int yAnt;
        int xProx;
        int yProx;
    public: 
        Character();
        ~Character();
        void setPositionAnt(int x, int y);
        void setPositionProx(int x, int y);
        int getXant();
        int getYant();
        int getXprox();
        int getYprox();
        int verifyCycle(Labyrinth Labyrinth);
        void fixPosition(int error, Labyrinth Labyrinth, int x, int y);
};