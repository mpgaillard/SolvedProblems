import math
while(True):
    n = input()
    if(n==0):
    	break
    best = -10000000000
    best_s = 0
    best_e = 0
    for i in range(0, n):
	    (x, y) = raw_input().split()
	    x = int(x); y = int(y)
	    val = y*math.log(x)
	    if(val > best):
	    	best = val
	    	best_s = x
	    	best_e = y

    #print nums
    #sorted(nums, key=lambda x: x[0]**x[1])
    print str(best_s) + " " + str(best_e)

