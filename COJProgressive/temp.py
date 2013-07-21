a = 5

def sN(N):
	global a
	if a > N:
		a = 6
		print "sdfd" 
	return (N*(N-1))/2

for i in range(1):
	print str(i)+ " " + str(sN(i))
print a