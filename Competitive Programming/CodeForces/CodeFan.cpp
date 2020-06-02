/*
 * https://codeforces.com/problemset/problem/155/A
 */

#include <iostream>

#define LOG(x) std::cout << x << std::endl;

int main()
{
	int n, record_break=0, val;
	std::cin >> n;
	std::cin >> val;
	int best = val;
	int worst = val;
	
	for (int i = 0; i < n-1; i++)
	{
		std::cin >> val;
		if (val > best)			{ best = val; record_break++; }
		else if (val < worst)	{ worst = val; record_break++; }
	}
	
	LOG(record_break);
	
	return 0;
}