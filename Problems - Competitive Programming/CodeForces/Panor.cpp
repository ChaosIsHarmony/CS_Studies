/*
 * http://codeforces.com/problemset/problem/80/A
 */

#include <iostream>

int main()
{
    int n, m;
    std::cin >> n >> m;
	
	int next_prime = m+1;
	
	for (int i = n+1; i <= m; i++)
	{
		bool prime = true;
		for (int j = 2; j <= i/2; j++)
		{
			if (i%j == 0) { prime = false; break; }
		}
		
		if (prime && i < next_prime) { next_prime = i; break; }
	}
		
	if (next_prime == m)	std::cout << "YES" << std::endl;
	else					std::cout << "NO" << std::endl;
	
    return 0;
}