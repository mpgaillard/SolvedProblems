#GRAPH-DFS PYTHON
class node:
	def __init__(self, n, t):
		self.name = n
		self.tol = t
		self.neighboors = []
		self.visited = False

def DFS(nodes, i):
	global best_so_far
	if nodes[i].visited == True:
		return
	if nodes[i].tol > best_so_far.tol:
		best_so_far = nodes[i]
	nodes[i].visited = True
	#curr_worker=nodes[i].tol
	curr_worker= nodes[i]
	for j in nodes[i].neighboors:
		curr_worker=  DFS(nodes, j)


while(True):
	namevals = {}
	nodes = []
	(N, K) = raw_input().split()
	N = int(N)
	K = int(K)
	if(N==0 and K==0): break

	for i in range(N):
		(name, tol) = raw_input().split()
		tol = int(tol)
		person = node(name, tol)
		nodes.append(person)
		namevals[name] = i

	for i in range(K):
		(n1, n2) = raw_input().split()
		nodes[namevals[n1]].neighboors.append(namevals[n2])
		nodes[namevals[n2]].neighboors.append(namevals[n1])

	sum_best_w = []
	for i in range(len(nodes)):
		if nodes[i].visited == False:
			best_so_far = nodes[i]
			DFS(nodes, i)
			sum_best_w += [best_so_far.name]
	sum_best_w.sort()
	for j in sum_best_w:
		print j




