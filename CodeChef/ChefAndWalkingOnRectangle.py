
T = input()

for i in range(T):
    (N,M,K) = raw_input().split()
    N = int(N); M=int(M); K = int(K);
    if N==1 and M<=2:
        print 0
    elif M==1 and N<=2:
        print 0
    elif N==1 or M == 1:
        print K
    else:
        if K%2==0:
            print K/2
        else:
            print (K+1)/2
        
