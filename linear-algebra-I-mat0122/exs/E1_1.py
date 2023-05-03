# 0.8.1 de PNK.
def main():
    a = [1, 5, 7]
    i = increments(a)
    print(i)


def increments(L):
    s = [x+1 for x in L]
    return s


if __name__ == '__main__':
    main()
