# ------------------------------------------------------------------------------
# # MAT0122 ÁLGEBRA LINEAR I
# Aluno: Beatriz Viana Costa
# Numero USP: 13673214
# Tarefa: E2
# Data: 20/08/2022
#
#
# DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESTE PROGRAMA.  TODAS AS
# PARTES DO PROGRAMA, EXCETO AS QUE SÃO BASEADAS EM MATERIAL FORNECIDO
# PELO PROFESSOR OU COPIADAS DO LIVRO OU DO MATERIAL DIDÁTICO DE MAT0122,
# FORAM DESENVOLVIDAS POR MIM.  DECLARO TAMBÉM QUE SOU RESPONSÁVEL POR TODAS
# AS CÓPIAS DESTE PROGRAMA E QUE NÃO DISTRIBUÍ NEM FACILITEI A DISTRIBUIÇÃO
# DE CÓPIAS DESTA PROGRAMA.
# ------------------------------------------------------------------------------


def main():
    A = [(1, 2), (10, 20)]
    B = [(3, 4), (30, 40)]

    if len(A) != len(B):
        print('Nao foi possivel fazer a soma das listas de tuplas, pois elas nao possuem o mesmo tamanho.')

    else:
        soma = tuple_sum(A, B)
        print(soma)


def tuple_sum(A, B):
    s = [((a+b), (c+d)) for (a, c), (b, d) in zip(A, B)]
    return s


if __name__ == '__main__':
    main()
