import sys
import sympy.ntheory as nt

def main():
    a = int(sys.argv[1])
    b = int(sys.argv[2])
    if len(sys.argv) == 3:
        p = nt.randprime(a, b)
        q = nt.randprime(a, b)
        print(f"p = {p} / q = {q} / p*q = {p*q}")
    else:
        k = int(sys.argv[3])
        N = 1
        for _ in range(k):
            p = nt.randprime(a, b)
            print(p)
            N *= p
        print(N)
    
if __name__ == '__main__':
    main()    

#-----------------------------------------------------------------------

# $ python challenge.py 10000 20000
# p = 13033 / q = 11467 / p*q = 149449411
# $ python challenge.py 1000000 2000000
# p = 1587673 / q = 1875683 / p*q = 2977971255659
# $ python challenge.py 10000 15000 3
# 13397
# 11863
# 11353
# 1804316520683
# $ 
