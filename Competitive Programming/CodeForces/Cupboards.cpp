/*
 * https://codeforces.com/problemset/problem/248/A
 */

#include <iostream>

#define LOG(x) std::cout << x << std::endl;

int main()
{
	int left_z = 0;
	int right_z = 0;
	int n, tmp_l, tmp_r;
	std::cin >> n;
	
	// how many cupboards are closed on each side
	for (int i = 0; i < n; i++)
	{
		std::cin >> tmp_l;
		std::cin >> tmp_r;
		
		if (tmp_l == 0) left_z++;
		if (tmp_r == 0) right_z++;
	}
	
	int result;
	// more closed on left
	if (left_z > n/2)	{ result = n-left_z; }
	else				{ result = left_z; }
	if (right_z > n/2)	{ result += n-right_z; }
	else				{ result += right_z; }
	
	LOG(result);
	
	return 0;
}