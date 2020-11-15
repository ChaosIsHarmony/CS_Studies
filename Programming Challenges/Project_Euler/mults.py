#brute force
total = 0
for i in range(350):
	if i*3 < 1000:
		total += i*3

	if i*5 < 1000 and (i*5)%3 != 0:
		total += i*5

print(total)
