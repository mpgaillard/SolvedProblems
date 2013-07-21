from datetime import date

n = input()

for i in range(n):
	(f, s) = raw_input().split()
	first = f.split('-')
	second = s.split('-')
	d0 = date(int(first[0]), int(first[1]), int(first[2]))
	d1 = date(int(second[0]), int(second[1]), int(second[2]))
	delta = d0 - d1
	res = delta.days
	if res < 0:
		res = res*-1
	print res

