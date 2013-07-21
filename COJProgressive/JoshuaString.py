best_s = "z"*40

def bruteforce(LI, S):
    global best_s
    if len(LI)==0:
        if S < best_s:
            best_s = S
        return
    else:
        pos = []
        val = 1000
        best_char = 'a'
        for j in range(len(LI)):
    	    if ord(LI[j][0])-ord('a') < val:
    	        val = ord(LI[j][0])-ord('a')
    	        best_char = LI[j][0]
    	        pos = [j]
            elif ord(LI[j][0])-ord('a') == val:
                pos.append(j)
        for i in range(len(pos)):
            newL = []+LI
            newL[pos[i]] = newL[pos[i]][1:]
            if newL[pos[i]]=="":
                newL.remove("")
            bruteforce(newL, S+best_char) 


TC = raw_input()
TC = int(TC)

for i in range (TC):
    N = input()
    S = ""
    L = []
    for j in range (N):
        L.append(raw_input())

    #bruteforce(L, "")
    #print best_s
    while(len(L) > 0):
        pos = 0
        val = 1000
        cur_d = -1000
        chain_length = 0;
        #L.sort(reverse = True)
        for j in range(len(L)):
            if ord(L[j][0])-ord('a') < val:
                val = ord(L[j][0])-ord('a')
                pos = j
                if len(L[j])==1:
                	cur_d = -1000
                else:
                	cur_d = ord(L[j][0])-ord(L[j][1])
            elif ord(L[j][0])-ord('a') == val:
            	if len(L[j]) > 1:
            		if(ord(L[j][0])-ord(L[j][1]) > cur_d):
            			cur_d = ord(L[j][0])-ord(L[j][1])
            			pos = j
            			cl = 0
            			for i in L[j][1:]:
            				if i== L[j][1]:
            					cl+=1
            				else:
            					break;
            			chain_length = max(chain_length, cl)
            		elif(ord(L[j][0])-ord(L[j][1]) == cur_d):
            			cl = 0
            			for i in L[j][1:]:
            				if i== L[j][1]:
            					cl+=1
            				else:
            					break;
            			if(cl > chain_length):
            				chain_length = cl
            				pos = j


        S += L[pos][0]
        L[pos] = L[pos][1:]
        if (L[pos] == ""):
            L.remove("")
    print S
