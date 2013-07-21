max_prime = 51
p_map = [1]*max_prime
i = 2
while i*i < max_prime:
    if(p_map[i]==0):
    	i+=1
        continue
    j = i*i
    while j< max_prime:    		
        p_map[j] = 0
        j += i
    i+=1

primes = [x for x in xrange(2, max_prime) if p_map[x]==1]

primorial = [1]*max_prime

for i in range(2, max_prime):
	for x in primes:
	    if (x > i):
	    	break
	    primorial[i] *= x

while(True):
	n = input()
	if(n == 0):
		break
	print primorial[n]