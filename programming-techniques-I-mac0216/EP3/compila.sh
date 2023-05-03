#!/bin/bash

verfificaErro() {
    if [ $? -ne 0 ]; then
        exit 1
    fi
}

# Criação biblioteca estática
gcc -c -o propriedadesnumericas.o propriedadesnumericas.c
verfificaErro
ar -rc libpropriedadesnumericas.a propriedadesnumericas.o 
verfificaErro

# Criação da biblioteca dinâmica
gcc -c -fPIC -o vetoraleatorio.o vetoraleatorio.c
verfificaErro
gcc -o libvetoraleatorio.so -shared vetoraleatorio.o
verfificaErro


# Exclui os arquivos .o que não seram mais úteis
rm *.o

# Ligação das bibliotecas e compilação do programa
gcc -Wall -o testa testa.c libpropriedadesnumericas.a -L${PWD} -lvetoraleatorio
verfificaErro

# Geração da documentação no Doxygen
doxygen -g
verfificaErro
doxygen Doxyfile
verfificaErro

# Execução do programa
LD_LIBRARY_PATH=${PWD}:${LD_LIBRARY_PATH}
export LD_LIBRARY_PATH
./testa

exit 0