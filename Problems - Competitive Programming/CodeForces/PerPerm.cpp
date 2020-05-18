/*
 * https://codeforces.com/problemset/problem/233/A
 */

#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	
	if (n%2 != 0)	std::cout << -1 << std::endl;
	else			for (int i = 1; i <= n; i+=2)
						std::cout << i+1 << " " << i << " ";

	return 0;
}