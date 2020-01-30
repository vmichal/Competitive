def zjisti(photo):   
  pismena = ['f','a','c','e']  
  if photo[0] in pismena and photo[1] in pismena and photo[2] in pismena and photo[3] in pismena:
      plati = True
      prvky = []
      for i in range(4):
          if photo[i] in prvky:
            plati = False
          else: 
            prvky.append(photo[i])
      return plati
  return False      



def is_face_on_photo(photo):
  vyska = len(photo)
  sirka = len(photo[0])
  for y in range(vyska-1):
      for x in range(sirka-1):
          list = [photo[y][x], photo[y][x+1], photo[y+1][x], photo[y+1][x+1],]
          if zjisti(list):
              return True
  return False



print(is_face_on_photo([['f', 'a'], ['c', 'e']]))
print(is_face_on_photo([['f', 'a', 'c', 'e']])) 
print(is_face_on_photo([['e', 'c', 'x'], ['a', 'f', 'x'], ['x', 'x', 'x']])) 
print(is_face_on_photo([['f', 'f', 'x'], ['a', 'a', 'x'], ['x', 'x', 'x']])) 
