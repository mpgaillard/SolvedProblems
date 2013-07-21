T = input()

for i in range(T):
	(N, M) = raw_input().split()
	language = raw_input().split()
	message = raw_input()
	count = {}

	for x in message:
		if (x) in count:
			count[x] += 1
		else:
			count[x]=1
	words = [(x, count[x]) for x in count]
	words.sort(key=lambda tup : tup[1], reverse = True)

	cur_p = 0
	replaced = [0]*len(message)
	for (w, ct) in words:
		message = message.replace(w, language[cur_p].lower())
		cur_p+=1
	print message.upper()