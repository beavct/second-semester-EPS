#  0.8.4 de PNK
def main():
    o_dict = {'thank you': 'merci', 'goodbye': 'au revoir'}
    i_dict = inv_dict(o_dict)
    print(i_dict)


def inv_dict(d):
    i = {b: a for a, b in d.items()}
    # The items() method returns a view object that displays a list of dictionary's (key, value) tuple pairs.
    return i


if __name__ == '__main__':
    main()
