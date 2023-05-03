# ------------------------------------------------------------------------------
# # MAT0122 ÁLGEBRA LINEAR I
# Aluno: Beatriz Viana Costa
# Numero USP: 13673214
# Tarefa: EP2
# Data: 18/12/2022
#
#
# DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESTE PROGRAMA.  TODAS AS
# PARTES DO PROGRAMA, EXCETO AS QUE SÃO BASEADAS EM MATERIAL FORNECIDO
# PELO PROFESSOR OU COPIADAS DO LIVRO OU DO MATERIAL DIDÁTICO DE MAT0122,
# FORAM DESENVOLVIDAS POR MIM.  DECLARO TAMBÉM QUE SOU RESPONSÁVEL POR TODAS
# AS CÓPIAS DESTE PROGRAMA E QUE NÃO DISTRIBUÍ NEM FACILITEI A DISTRIBUIÇÃO
# DE CÓPIAS DESTA PROGRAMA.
# ------------------------------------------------------------------------------

import sys
import GF2
from GF2 import one
from vec import Vec
from factoring_support import intsqrt, dumb_factor, primes, prod, gcd

def root_method(N):
    a = intsqrt(N) + 1
    while 1:
        if intsqrt(a**2 - N) == int(intsqrt(a**2 - N)):
            b = intsqrt(a**2 - N)
            return a - b
        else:
            a += 1


def transformation_rows(rowlist_input, col_label_list = None):
    z = 0
    one = GF2.one
    rowlist = list(rowlist_input)
    if col_label_list == None: 
        col_label_list = sorted(rowlist[0].D, key=repr)
    m = len(rowlist)
    row_labels = set(range(m))
    M_rowlist = [Vec(row_labels, {i:one}) for i in range(m)]
    new_M_rowlist = []
    rows_left = set(range(m))
    for c in col_label_list:
        rows_with_nonzero = [r for r in rows_left if rowlist[r][c] != 0]
        if rows_with_nonzero != []:
            pivot = rows_with_nonzero[0]
            rows_left.remove(pivot)
            new_M_rowlist.append(M_rowlist[pivot])
            for r in rows_with_nonzero[1:]:
                multiplier = rowlist[r][c]/rowlist[pivot][c]
                rowlist[r] -= multiplier*rowlist[pivot]
                M_rowlist[r] -= multiplier*M_rowlist[pivot]
        else:
            z += 1
    for r in rows_left: 
        new_M_rowlist.append(M_rowlist[r])
    return new_M_rowlist, z


def int2GF2(i):
    if i % 2 != 0:
        return one
    else:
        return 0


def make_Vec(primeset, factors):
    d = {}
    for i in factors:
        d[i[0]] = int2GF2(i[1])
    return Vec(primeset, d)


def find_candidates(N, primelist):
    i = 2
    roots = []
    rowlist = []
    while(len(roots) <= len(primelist)+1):
        x = intsqrt(N)+i
        if len(dumb_factor(x**2 - N, primelist)) == 0:
            roots.append(x)
            rowlist.append(make_Vec(primelist, dumb_factor(x, primelist)))
        i += 1
    return roots, rowlist


def find_a_and_b(v, roots, N):
    alist = []
    aux = []
    for i in range(len(roots)):
        if v[i] != 0:
            alist.append(roots[i])
    a = prod(alist)
    for x in alist:
        aux.append(x**2 - N)
    c = prod(aux)
    b = intsqrt(c)
    if b * b == c:
        return a, b
    else:
        return a, 0

def main():
    ok = 0
    cont = 0
    N = int(sys.argv[1])    

    if len(sys.argv) == 2:
        primelist = list(primes(10000))
    else:        
        primelist = list(primes(int(sys.argv[2])))

    listsroots, rowlist = find_candidates(N, primelist)
    M, z = transformation_rows(rowlist, sorted(primelist, reverse=True))

    for i in range(len(M)-1, 0, -1):  # Percorre de trás para frente
        a, b = find_a_and_b(M[i], listsroots, N)

        if a != None and b != None:

            if len(sys.argv) == 4:
                print(cont, ": a =", a, "/ b =", b)
                cont += 1

            commondivisor = gcd(a-b, N)
            if commondivisor != 1 and commondivisor != None and commondivisor != N:
                print("factor = ", commondivisor)
                ok = 1
                break

    if ok == 0:
        print("Failed")


if __name__ == '__main__':
    main()