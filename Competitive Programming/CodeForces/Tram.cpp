/*
 * https://codeforces.com/problemset/problem/116/A
 */

#include <iostream>

#define LOG(x) std::cout << x << std::endl;

int main()
{
	int max_cap = 0, nPass = 0;
	int nStops, on, off;
	std::cin >> nStops;
	for (int i = 0; i < nStops; i++)
	{
		std::cin >> off;
		std::cin >> on;
		nPass+=-off+on;
		if (nPass > max_cap) max_cap = nPass;
	}
	
	LOG(max_cap);
	
	return 0;
}