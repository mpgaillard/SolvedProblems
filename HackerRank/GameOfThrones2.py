def fact(n):
    res = 1;
    for i in range(2, n+1):
	    res = (res*i)%1000000007
    return res

def fast_pow(a, n):
	if n==0:
		return 1
	if n == 1:
		return a
	f = fast_pow(a, n//2)
	if(n%2==0):
		return (f*f)%1000000007
	else:
		return (a*f*f)%1000000007

line = raw_input()

ct_letters = [0]*26
odd = 0
even = 0
difs = 0

for i in line:
    ct_letters[ ord(i)-ord('a') ]+=1



length_t = len(line)//2
list_reps = []
for i in ct_letters:
    if i%2==0:
        even+=1
    else:
        odd+=1
    lets = i//2
    list_reps += [lets]


if odd==1 or odd==0:
    nomin = fact(length_t)
    denom = 1
    for val in list_reps:
        denom = (denom*fact(val))%1000000007
    r = ((fast_pow(denom, 1000000005)%1000000007)*nomin)%1000000007
    print str(r)

else:
	print "0"
