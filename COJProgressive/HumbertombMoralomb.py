
def bSearch(val, l, r):
    
    while(l <= r):
        x = l + (r-l)/2
        ans = x*x
        y = x-1
        previous_ans = y*y
        if(ans >= val and previous_ans < val):
        	return x
        else:
        	if(ans < val):
        		l = x+1
        	else:
        		r = x-1
    return -1

while(True):
	n = input()
	if(n==0):
		break
	print bSearch(n, 0, 100000)