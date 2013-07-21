line = raw_input()

ct_letters = [0]*26
odd = 0
even = 0

for i in line:
    ct_letters[ ord(i)-ord('a') ]+=1
for i in ct_letters:
    if i%2==0:
        even+=1
    else:
        odd+=1
if odd ==1 or odd==0:
    print "YES"
else:
    print "NO"