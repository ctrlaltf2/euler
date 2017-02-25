#Ported from c++ version that broke after 11 as grid size (probably some shitty overflow error that I can't find)
from math import factorial

gridsize = int(input("Enter a grid size: "))

def ncr(n, r):
    return factorial(n) / factorial(r) / factorial(n - r)

print(ncr(gridsize * 2, gridsize))
