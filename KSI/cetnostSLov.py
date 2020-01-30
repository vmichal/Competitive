def word_frequency(text):
    text = text.lower()
    text += " "
    list = []
    index = 0
    posledniOddelovac = -1
    jePismeno = False
    while index<len(text):
        if text[index].isalpha():
            index = index+1
            jePismeno = True
        else:
            if jePismeno:
                list.append(text[posledniOddelovac+1:index])
                jePismeno = False                      
            posledniOddelovac = index
            index = index+1
    slovnik = {}
    for i in range(len(list)):
        if not list[i] in slovnik:
            slovnik[list[i]] = 1
        else:
            slovnik[list[i]] += 1
    return slovnik

print(word_frequency("Ksi, Ksa, Ksi, Kse"))       # {'ksi': 2, 'ksa': 1, 'kse': 1}
print(word_frequency("Informatika je nejlepsi"))  # {'informatika': 1, 'je': 1, 'nejlepsi': 1}


