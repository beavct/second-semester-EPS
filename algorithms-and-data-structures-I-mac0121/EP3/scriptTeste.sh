#!/bin/bash
#$1= o sort que queremos testar, $2= arquivo .txt onde será salva a saída
PALAVRAS=250
heap="heap"

    if [ $1 == ${heap} ]; then 
        gcc -ansi -Wall -pedantic -O2 filaPrioridades.c heapsort.c
        echo -e "\nheapsort" >> $2

        while [ "$(echo "${PALAVRAS} <= 64000" | bc -l)" -eq 1 ]; do
            #echo -e "\nVetor aleatório" >> $2
            #echo -e ${PALAVRAS}"palavras \n" >> $2
            ./a.out < ${PALAVRAS}words.txt >> $2
            let PALAVRAS=${PALAVRAS}*2
        done
        PALAVRAS=250

        while [ "$(echo "${PALAVRAS} <= 64000" | bc -l)" -eq 1 ]; do
            #echo -e "\nVetor parcial" >> $2
            #echo -e ${PALAVRAS}"palavras \n" >> $2
            ./a.out < ${PALAVRAS}partial.txt >> $2
            let PALAVRAS=${PALAVRAS}*2
        done
        PALAVRAS=250

        while [ "$(echo "${PALAVRAS} <= 64000" | bc -l)" -eq 1 ]; do
            #echo -e "\nVetor ordenado" >> $2
            #echo -e ${PALAVRAS}"palavras \n" >> $2
            ./a.out < ${PALAVRAS}order.txt >> $2
            let PALAVRAS=${PALAVRAS}*2
        done

    else
        gcc -ansi -Wall -pedantic -O2 $1sort.c
        echo -e "$1sort\n" >> $2

        while [ "$(echo "${PALAVRAS} <= 64000" | bc -l)" -eq 1 ]; do
            #echo -e "\nVetor aleatório" >> $2
            #echo -e ${PALAVRAS}"palavras \n" >> $2
            ./a.out < ${PALAVRAS}words.txt >> $2
            let PALAVRAS=${PALAVRAS}*2
        done
        PALAVRAS=250

        while [ "$(echo "${PALAVRAS} <= 64000" | bc -l)" -eq 1 ]; do
            #echo -e "\nVetor parcial" >> $2
            #echo -e ${PALAVRAS}"palavras \n" >> $2
            ./a.out < ${PALAVRAS}partial.txt >> $2
            let PALAVRAS=${PALAVRAS}*2
        done
        PALAVRAS=250

        while [ "$(echo "${PALAVRAS} <= 64000" | bc -l)" -eq 1 ]; do
            #echo -e "\nVetor ordenado" >> $2
            #echo -e ${PALAVRAS}"palavras \n" >> $2
            ./a.out < ${PALAVRAS}order.txt >> $2
            let PALAVRAS=${PALAVRAS}*2
        done

    fi

    rm a.out

exit 0