

N = int(input())

last_one = [0]*10002
last_zero = [0]*10002

last_one[1] = 1
last_zero[1] = 1

for i in range(2,N+1):
	last_zero[i] = last_one[i-1]
	last_one[i] = last_one[i-1] + last_zero[i-1]

print(last_one[N] + last_zero[N])
