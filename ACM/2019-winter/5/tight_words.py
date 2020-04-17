import sys

digits = 0
cache = [[[-1 for y in range(12)] for i in range(102)] for j in range(12)]

def count_tights(previous, length):
	if previous == -1 or previous == digits:
		return 0
	if length == 0:
		return 1
	if cache[digits][length][previous] != -1:
		return cache[digits][length][previous]

	count = (count_tights(previous, length-1) 
		+ count_tights(previous-1, length-1)
		+ count_tights(previous+1, length-1))

	cache[digits][length][previous] = count
	return count

def solve(length):

	tight= 0
	for i in range(digits):
		tight += count_tights(i, length-1)
	#print(f'tight={tight} total={digits ** length}')
	return tight * 100 / (digits ** length)
	


for line in sys.stdin:
	digits, length = list(map(int, line.split()))
	digits += 1
	print('%.5f' % solve(length))