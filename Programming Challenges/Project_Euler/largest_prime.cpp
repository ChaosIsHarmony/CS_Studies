/*
	./largest_prime < primes.txt
*/

#include <iostream>
#include <cmath>

// brute force w/ pre-computed prime list from internet
void bf()
{
	int i = 1;
	int cnt = 1;
	while(cnt++ < 601)
	{
		std::cin >> i;
		if (600851475143%i==0)	{ std::cout << i << std::endl; break; }
	}
}

// mathematical cleverness
bool is_prime(int candidate)
{
	int limit = int(std::sqrt(candidate));
	while (limit > 1)	
		if (candidate%limit==0)	return false;
		else			limit--;
	return true;
}


void sqrt_limiter()
{
	// highest possible
	int fact = int(std::sqrt(600851475143));
	while (fact > 1)
	{
		if (600851475143%fact==0 && is_prime(fact))	{ std::cout << fact << std::endl; break; }
		fact--;
	}
}

int main()
{
	// bf();
	sqrt_limiter();
	return 0;
}
