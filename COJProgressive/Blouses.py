case_num = 1
while(True):
	(C,Q,K) = raw_input().split()
	C = int(C)
	Q = int(Q)
	K = int(K)
	if(C==0 and Q==0 and K == 0):
		break
	color_list = []
	cur = 0
	start = 1
	for i in xrange(C):
		(color, cant) = raw_input().split()
		cant = int(cant)
		
		color_list.append((color, start, cant+cur))
		cur += cant
		start = cur+1
	
	for i in xrange(Q):
		live_cols = [1]*(cur+1)
		res = []
		last_worn = raw_input().split()
		if i==0:
			print "Case #" + str(case_num)+":"
		#live_cols[int(last_worn[len(last_worn)-1])] = 0
		for j in xrange(len(last_worn), len(last_worn)-K, -1):
			#print j
			live_cols[int(last_worn[j-1])] = 0
		live_cols[int(last_worn[(len(last_worn)-1)-6])]= 0

		last_color = int(last_worn[len(last_worn)-1])
		last_start = 0
		last_end = 0
		for (c, l, e) in color_list:
			if l <= last_color and e >= last_color:
				last_color = c
				last_start = l
				last_end = e
		for j in xrange(last_start, last_end+1):
			live_cols[j] = 0
		for j in xrange(1, len(live_cols)):
			if live_cols[j]==1:
				res += [j]

		if res==[]:
			print "Buy other blouse"
		else:		
			for i in range(0,len(res)-1):
				print  str(res[i]),
			print str(res[len(res)-1])
	print

	case_num+=1