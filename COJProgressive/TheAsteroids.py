import math

while( 1 ):
	N = input()
	if N==0:
		break
	ship_loc = raw_input().split()
	ship_x = int(ship_loc[0])
	ship_y = int(ship_loc[1])

	closest = 10000000
	closest_ship = 0
	for i in range(0, N):
		ast = raw_input().split()
		ast_x = int(ast[0])
		ast_y = int(ast[1])
		dist = math.sqrt( (ship_x-ast_x)**2 + (ship_y-ast_y)**2  ) - float(ast[2])
		if(dist < closest):
			closest = dist
			ship = i+1
	print ship