def sum_digits(n):
	s = 0
	while n:
		s += n%10
		n /= 10
	return s


while True:
	[a, b] = raw_input().split()
	if a == "0" and b == "0":
		break
	print sum_digits( int(a*int(b))*int(a*int(b)) )

