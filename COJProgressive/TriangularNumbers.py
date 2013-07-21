#another solution is using (-b +- squrt(b*b-4ac)))/2 log based binary search > sqrt
def b_search(val):
	l = 0; r = 16000000000000000005

	while(l <= r):
		mid = l + (r-l)//2
		res = (mid*(mid+1))/2
		if(res == val):
			return "YES"
		elif(res < val):
			l = mid+1
		else:
			r = mid-1
	return "NO"

while(True):
	n = input()
	if n == 0:
		break
	print b_search(n)