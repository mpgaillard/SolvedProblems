def fast_pow(a, b, modl):
    if (b==0):
        return 1%modl
    if(b==1):
        return a%modl
    tm = fast_pow(a, b/2, modl)
    if b%2==0:
        return  (tm*tm)%modl 
    else:
        return (((tm*tm)%modl)*a)%modl


T = input()
for i in range(0, T):
    (a, b) = raw_input().split()
    a = int(a)
    b = int(b)
    print fast_pow(a, b, 1000000000)
