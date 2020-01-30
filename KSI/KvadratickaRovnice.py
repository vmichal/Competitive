from math import sqrt
def Vyres(a,b,c):
    diskriminant = b*b-4*a*c
    if diskriminant<0:
        return None
    return (-b+sqrt(diskriminant))/(2*a)

a = int(input())
b = int(input())
c = int(input())
print(Vyres(a,b,c))