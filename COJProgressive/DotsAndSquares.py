T = input()
for i in range(T):
	(x, y) = raw_input().split()
	x = int(x); y = int(y);
	total_edges = ((x-1)*y)+((y-1)*x)
	if (total_edges%2 == 0):
		print "Second"
	else:
		print "First"
