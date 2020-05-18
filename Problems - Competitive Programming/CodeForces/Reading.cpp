/*
 * https://codeforces.com/problemset/problem/139/A
 */

#include <iostream>

int main()
{
	int p;
	std::cin >> p;
	int d_o_wk[7];
	for (int i = 0; i < 7; i++)
		std::cin >> d_o_wk[i];
	
	int ind = 0;
	for (;p > 0; ind = (ind+1)%7)
		p -= d_o_wk[ind];
		
	std::cout << ((ind==0) ? 7 : ind) << std::endl;
	
	return 0;
}