
T = int(input())

for i in range(T):
	a, b = input().split()
	a = a[::-1]
	b = b[::-1]

	result = int(a) + int(b)
	print(int(str(result)[::-1]))


