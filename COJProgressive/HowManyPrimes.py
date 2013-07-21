max_prime = 1000001
p_map = [1]*max_prime
p_map[0] = 0
p_map[1] = 0
primes_range = [0]*max_prime

i=2

while i*i < max_prime:
    if(p_map[i]==0):
    	i+=1
        continue
    j = i*i
    while j< max_prime:    		
        p_map[j] = 0
        j += i
    i+=1

#primes = [x for x in xrange(2, max_prime) if p_map[x]==1]
for i in xrange(2,max_prime):
    primes_range[i] = p_map[i]+primes_range[i-1]

while(True):
    inp = raw_input().split()
    inp[0] = int(inp[0])
    inp[1] = int(inp[1])
    if(inp[0]==0 and inp[1]==0):
        break
    print primes_range[inp[1]]-primes_range[inp[0]-1]
   # print len([x for x in primes if x>= inp[0] and x <= inp[1]])
    
