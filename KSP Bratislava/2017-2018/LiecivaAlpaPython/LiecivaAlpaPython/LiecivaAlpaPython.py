vstup = input().split(" ")
pocetBojovniku = int(vstup[0])
pocetKapek = int(vstup[1])

bojovnici = []
for i in range(pocetBojovniku):
    bojovnici.append(int(input()))
maximum = 0
celkem = 0

for i in range(pocetBojovniku-1,0,-1):
    celkem += bojovnici[i]
    soucet = celkem
    for j in range(pocetBojovniku-1,i,-1):
        if (soucet % pocetKapek ==0):
            pomocna = j-i+1
            if (maximum < pomocna):
                maximum = pomocna
            break
        soucet -= bojovnici[j]

print(maximum)


