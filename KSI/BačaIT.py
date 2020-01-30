def count_profit(data):    
    zisky = {"krava":5,"koza":14,"ovce":4}
    list = data.split(",")
    druhyList = []
    for i in range(len(list)):
        druhyList += list[i].split()
    zisk = 0
    i = 0
    while i<len(druhyList):
        zisk += zisky[druhyList[i]]*int(druhyList[i+1])
        i = i+2
    return zisk

# Testy:
print(count_profit("krava 2,koza 1"))  # 24
print(count_profit("krava 1,krava 3"))  # 20
print(count_profit("ovce 10")) # 40
# na farme je vzdy alespon jedno zvire

