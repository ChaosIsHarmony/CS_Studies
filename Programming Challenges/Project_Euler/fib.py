# first choice
# build fib up to 4 million, add even
total = 0
fib = [1, 1]
while fib[1] < 4000000:
	fib[0] = fib[0] + fib[1]
	if fib[0]%2 == 0:
		total += fib[0]
	fib[1] = fib[0] + fib[1]
	if fib[1]%2 == 0:
		total += fib[1]

print(total)
