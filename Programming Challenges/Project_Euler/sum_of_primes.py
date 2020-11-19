primes = [2, 3, 5, 7]

def is_prime(num):
	for prime in primes:
		if num%prime == 0:
			return 0
	primes.append(num)
	return num

sum_o_primes = 17
for i in range(10, 2_000_000):
	sum_o_primes += is_prime(i)
	# progress checker
	if i%100000 == 0: print(sum_o_primes)


print(sum_o_primes)
