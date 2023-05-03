from vec import Vec
from GF2 import one


def main():
    dois = button_vectors(2)
    tres = button_vectors(3)
    quatro = button_vectors(4)

    print(len(dois))
    print(len(tres))
    print(len(quatro))


def gf2_span(D, L):
    n = len(L)
    if n == 0:
        return []
    m = 2 ** n - 1
    r = [sum([L[i] for i in range(n) if j // (2 ** i) % 2]) for j in range(m + 1)]
    r.append(Vec(D, {}))
    del r[0]
    r = list(set(r))
    return r


def button_vectors(n):
    i = 0
    j = 0
    D = {(i, j) for i in range(n) for j in range(n)}
    D = list(D)
    del D[0]
    D = set(D)
    vecdict = {(i, j): Vec(D, dict([((x, j), one) for x in range(max(i - 1, 0), min(i + 2, n))]
                                   + [((i, y), one) for y in range(max(j - 1, 0), min(j + 2, n))]
                                   for (i, j) in D))}
    return vecdict


if __name__ == '__main__':
    main()
