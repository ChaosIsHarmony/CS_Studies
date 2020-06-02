/*
 * https://codeforces.com/problemset/problem/34/A
 */

#include <iostream>
#include <cmath>

int main()
{
	//input
	int n, first, h_1, h_2, min_ind_1, min_ind_2, min =1001;
	std::cin >> n >> first;
	for (int i = 0; i < n; i++, h_1 = h_2) // set h_1 for subsequent iterations
	{
		if (i < n-1)	std::cin >> h_2;
		if (i == 0)
		{
			if (std::abs(first-h_2) < min) { min = std::abs(first-h_2); min_ind_1 = i; min_ind_2 = i+1; }
		}
		else if (i == n-1)
		{
			if (std::abs(h_1-first) < min) { min_ind_1 = i; min_ind_2 = 0; }
		}
		else
		{
			if (std::abs(h_1-h_2) < min) { min = std::abs(h_1-h_2); min_ind_1 = i; min_ind_2 = i+1; }
		}
	}
	
	//output
	std::cout << ++min_ind_1 << " " << ++min_ind_2 << std::endl;
	return 0;
}