/*
 * https://codeforces.com/problemset/problem/149/A
 * Neglected stipulation that k could be impossible to achieve
 */
#include <iostream>
#include <algorithm>

template<typename T>
Log(T t) { std::cout << t << std::endl; }

int main()
{
	int k, tot=0, months = 0;
	int growth[12];
	std::cin >> k;
	if (k > 0) {
		for (int i = 0; i < 12; i++)
		{ std::cin >> growth[i]; tot+=growth[i]; }

		// impossible to achieve
		if (k > tot)	months = -1;
		// doable
		else
		{
			std::sort(growth, growth+12);
			
			for (int ind = 11; ind >= 0; ind--)
			{
				tot+=growth[ind];
				months++;
				if (tot >= k)	break;
			}
		}
	}
	
	Log(months);
	return 0;
}