def lists(a,b,c,d):
  list1 = []
  for i in range(a+1):
    list1.append(i)
  list2 = []
  for i in range(a+1):
    list2.append(list1[i]+10)
  list2[len(list2)-1] = "KSI"
  if b in list2:
    list2.remove(b)
  else: 
    print("Not here")
  list3 = []
  if c>len(list1):
    list3 = list1
  else:
    for i in range(c):
      list3.append(i)
  list2 += list3
  list3.reverse()
  list1[1] = d
  list1.sort()
  return (list1, list2, list3)
  
print(lists(5, 12, 3, 20))
print(lists(10, 3, 2, 11))
  
  
  
  