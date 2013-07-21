
def b_search(val):
	l = 0; r = 2500000000000000000

	while(l <= r):
		mid = l + (r-l)//2
		res = (mid*(mid+1))/2
		bef_res = ((mid-1)*mid)/2
		if(res >= val and bef_res < val ):
			return mid
		elif(res < val):
			l = mid+1
		else:
			r = mid-1
	return -1

while(True):
	num = input()
	if num == 0:
		break

	line = b_search(num)
	start_num = (((line-1)*(line))/2)+1
	movs = num-start_num
	if(line%2==0):
		#top start
		start_x = 1
		start_y = line
		start_x+= movs
		start_y-= movs

	else:
		#bottom start
		start_x = line
		start_y = 1
		start_x-=movs
		start_y+=movs
	print str(start_x) + " " + str(start_y)

