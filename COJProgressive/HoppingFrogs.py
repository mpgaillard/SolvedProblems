from collections import deque

def gen_comb(f, second, moves, visited):
	first_str = "".join(f)

	if first_str in visited:
		return -1

	if(first_str == second):
		return moves

	visited[first_str] = True
	best_moves = 10000000000000000
	for i in range(len(f)):
		first = []+f
		if first[i]=='B' or first[i]=='R':
			if i != len(first)-1 and first[i+1]=='.':
				first[i+1]=first[i]
				first[i]='.'
				best_moves = min(best_moves, gen_comb(first, second, moves+1, visited))
			if i+2 < len(first) and first[i+1]!= '.' and first[i+2]=='.':
				first[i+2] = first[i]
				first[i] = '.'
				best_moves = min(best_moves, gen_comb(first, second, moves+1, visited))
		if first[i] == 'G' or first[i]=='R':
			if i != 0 and first[i-1]=='.':
				first[i-1]=first[i]
				first[i]='.'
				best_moves = min(best_moves, gen_comb(first, second, moves+1, visited))
			if i-2 >= 0 and first[i-1]!='.' and first[i-2]=='.':
				first[i-2]=first[i]
				first[i]='.'
				best_moves = min(best_moves, gen_comb(first, second, moves+1, visited))

	return best_moves




T = input()

for j in range(T):
	blank = raw_input()
	f = raw_input()
	f = list(f)
	second = raw_input()
	visited = {}
	res_d = 0
	#next_queue = [(f,0)]
	next_queue = deque([])
	next_queue.append((f,0))
	visited["".join(f)] = True
	sol = False
	while len(next_queue) > 0:
		(front,d) = next_queue.popleft()
		if ("".join(front)==second):
			res_d = d
			sol = True; break

		d2 = d+1
		#print front, " " + str(d)
		for i in range(len(front)):
			if front[i]=='B' or front[i]=='R':
				first = []+front
				if i != len(first)-1 and first[i+1]=='.':
					first[i+1]=first[i]
					first[i]='.'
					first_str = "".join(first)
					if first_str not in visited:
						visited[first_str] = True
						next_queue.append((first,d2))
				first = []+front
				if i+2 < len(first) and first[i+1] != '.' and first[i+2]=='.':
					first[i+2] = first[i]
					first[i] = '.'
					first_str = "".join(first)
					if first_str not in visited:
						visited[first_str] = True
						next_queue.append((first,d2))
					
			if front[i] == 'G' or front[i]=='R':
				first = []+front
				if i != 0 and first[i-1]=='.':
					first[i-1]=first[i]
					first[i]='.'
					first_str = "".join(first)
					if first_str not in visited:
						visited[first_str] = True
						next_queue.append((first,d2))
				first = []+front
				if i-2 >= 0 and first[i-1] !='.' and first[i-2]=='.':
					first[i-2]=first[i]
					first[i]='.'
					first_str = "".join(first)
					if first_str not in visited:
						visited[first_str] = True
						next_queue.append((first,d2))

	if sol:
		print "Case " + str(j+1) + ": " + str(res_d)
	else:
		print "impossible"