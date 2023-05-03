from vec import Vec
from GF2 import one

def main ():
    D = {'A', 'B', 'C'}
    u1 = Vec(D, {'A': one, 'B': one})
    v1 = Vec(D, {'B': one, 'C': one})
    L = [u1, v1]
    r = GF2_span(D, L)
    print(r)

def GF2_span(D, L):
    n = len(L)
    if n == 0:
        return []
    max = 2 ** n - 1
    r = [sum([L[i] for i in range(n) if j // (2 ** i) % 2]) for j in range(max + 1)]
    r.append(Vec(D, {}))
    del r[0]
    return r

if __name__ == '__main__':
    main()