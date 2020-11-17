def is_prime(num):
	limit = int(num**(0.5))
	for i in range(2, limit+1):
		if num%i == 0:
			return False
	return True

def find_next_prime(last_prime):
	next_cand = prime + 1
	while not is_prime(next_cand):
		next_cand += 1
	return next_cand

cnt = 1
prime = 2
while cnt != 10001:
	prime = find_next_prime(prime)
	cnt += 1

print(prime)
