n = int(input())
soucet = 0
mocnina = 1
for i in range (0,n+1):
  soucet += mocnina
  mocnina *= 2
print(soucet)