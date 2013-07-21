import math

t = input()

while ( t >0 ):
    n = input()
    vol = 0.0
    for x in range(0, n):
        geom = raw_input().split()
        vol += (math.pi*float(geom[0])*float(geom[0])*float(geom[1]))
    print "%.2f" % vol

    t -= 1