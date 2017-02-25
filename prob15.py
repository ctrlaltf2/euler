# Only reason I'm using python is 3's ability to do calculations of large numbers such as (40!)
from math import factorial

gridsize = int(input("Enter a grid size: "))

def ncr(n, r):
    return factorial(n) / factorial(r) / factorial(n - r)

print(ncr(gridsize * 2, gridsize))
