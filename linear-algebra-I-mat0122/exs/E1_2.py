# 0.8.2 de PNK.
def main():
    a = [1, 2, 3]
    c = cubes(a)
    print(c)

def cubes(L):
    c = [x*x*x for x in L]
    return c


if __name__ == '__main__':
    main()