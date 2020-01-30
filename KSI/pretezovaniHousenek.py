class Caterpillar:

    def __init__(self, head, body):
        self.head = head
        self.body = body

    def __str__(self):
        text = "(" + self.head + ")"
        for i in range(len(self.body)):
            text += "(" + str(self.body[i]) + ")"
        return text

    def __getitem__(self, key):
        return self.body[key]

    def __setitem__(self, key, value):
        self.body[key] = value

    def __add__(self, otherCatepillar):
        c = Caterpillar("",[])   
        if self.head < otherCatepillar.head:
            c.head = self.head
        else:
            c.head = otherCatepillar.head
        if len(self.body) > len(otherCatepillar.body):
            c.body = list(self.body)
            for i in range(len(otherCatepillar.body)):
                c.body[i] += otherCatepillar.body[i]
        else:
            c.body = list(otherCatepillar.body)
            for i in range(len(self.body)):
                c.body[i] += self.body[i]   
        return c


# Testy:
caterpillar_a = Caterpillar("green", [5, 2, 10, 8])
print(caterpillar_a)
caterpillar_a[2] = caterpillar_a[2] + 1
caterpillar_b = Caterpillar("red", [1, 3, 4])
print(caterpillar_a + caterpillar_b)
