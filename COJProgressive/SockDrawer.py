t = input()

for i in xrange(0, t):
	k = input()
	socks = raw_input().split()
	for j in xrange(0,len(socks)):
		socks[j] = int(socks[j])
	socks.sort()
	min_s_c = 0
	min_d_c = socks[-1]+1
	min_s_c = len(socks)+1
	print "Case " + str(i+1) + ": " +  str(min_s_c)+ " " + str(min_d_c)