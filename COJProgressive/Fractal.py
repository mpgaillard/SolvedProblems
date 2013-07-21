T = input()

for i in range(T):
	(L,S) = raw_input().split()
	L = float(L); S = float(S)
	it = 0
	nom = 5.0
	denom = 3.0
	while(True):
		if (nom/denom)*L > S:
			break
		#print nom/denom
		nom *= 5.0
		denom *= 3.0
		it+=1
	print it
