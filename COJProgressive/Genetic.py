t = input()
for i in range(0, t):
	(M,N) = raw_input().split()
	if(M.find('T')==-1 or M.find(N) == -1):
		print 'N'
	else:
		print 'Y'