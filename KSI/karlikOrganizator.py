from game import Registration

# Tyto tridy implementuj:


class Player:
    def __init__(self, name, sledges, skis, index):
        self.name = name
        self.sledges = sledges
        self.skis = skis
        self.index = index
        
    def get_transportni_mista(self):
        mista = 0
        for i in range(len(self.sledges)):
            mista += self.sledges[i]
        mista += len(self.skis)
        return mista

class Team:
    def __init__(self, name,players):
        self.name = name              
        self.players = players
       
    def get_players_count(self):
       return len(self.players)

    def get_transport_capacity(self):
        pocetMist = 0
        for i in range(self.get_players_count()):
            pocetMist += self.players[i].get_transportni_mista()
        return pocetMist
            
    def get_average_index(self):
        soucet = 0
        for i in range(self.get_players_count()):
            soucet += self.players[i].index
        return soucet/self.get_players_count()

# Testy:

registration = Registration()

print(registration.register(
    Team(
        "Zmlsani",
        [
            Player("Agata", [2, 3], [1], 5),
            Player("Rudolf", [], [], 3),
            Player("Alois", [], [], 4)
        ]
    ))
)
'''
"Tym Zmlsani zaregistrovan,
zarazen jako pojizdny s prum. hernim indexem 4.0."
'''

print(registration.register(
    Team(
        "Dupoledu",
        [
            Player("Agata", [], [1], 1),
            Player("Alois", [], [], 2)
        ]
    ))
)
'''
"Tym Dupoledu zaregistrovan,
zarazen jako nepojizdny s prum. hernim indexem 1.5."
'''

print(registration.register(
    Team(
        "(O)OP",
        [
            Player("Agata", [2], [1], 8),
            Player("Rudolf", [], [1], 7),
            Player("Alois", [3], [], 9),
            Player("Oskar", [2], [], 10),
            Player("Karlos", [10, 5], [1, 1, 1], 20)
        ]
    ))
)
''' "Tym nezaregistrovan, prekroceno povolene mnozstvi clenu." '''
