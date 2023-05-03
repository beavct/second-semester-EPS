#pragma once
#define MAX 256

/*!
* \brief  File()
* \brief Função construtora da classe File.
*/


/*!
* \brief  ~File()
* \brief Função destrutora da classe File.
*/


/*!
* \brief  char* readLabyrinth()
* \brief Instância um arquivo que será aberto a partir do nome indicado pelo usuário no terminal. 
*   Ao abrir o arquivo, a função guarda os valores das linhas e colunas, respectivamente.
*   Posteriormente lê o labirinto carácter ppr carácter, já inserindo o Pac-man, indicado pela letra 'C', no centro do labirinto.
* \return retorno (char*): Retorna o labirinto lido no arquivo indicado pelo usuário.
*/


/*!
* \brief  char* readLabyrinthTest(char fileName[MAX])
* \brief Instância um arquivo que será abertp, no caso o labirinto nomeado como 'ex1.txt'. 
*   Ao abrir o arquivo, a função guarda os valores das linhas e colunas, respectivamente.
*   Posteriormente lê o labirinto carácter ppr carácter, já inserindo o Pac-man, indicado pela letra 'C', no centro do labirinto.
* \return retorno (char*): Retorna o labirinto lido no arquivo 'ex1.txt' que será utiliado no teste.
*/


/*!
* \brief  int getLines()
* \brief A função retorna o atributo "lines" da classe, que indica a quantidade de linhas do labirinto lido.
* \return retorno (int): Quantidade de linhas do labirinto.
*/


/*!
* \brief  int getRows()
* \brief A função retorna o atributo "rows" da classe, que indica a quantidade de colunas do labirinto lido.
* \return retorno (int): Quantidade de colunas do labirinto.
*/

class File {
    protected:
        int lines;
        int rows;
    public:
        File();
        ~File();
        char* readLabyrinth();
        char* readLabyrinthTest(char fileName[MAX]);
        int getLines();
        int getRows();
};