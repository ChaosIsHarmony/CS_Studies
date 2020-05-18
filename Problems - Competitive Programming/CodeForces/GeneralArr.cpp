/*
 * https://codeforces.com/problemset/problem/144/A
 */

#include <iostream>
#include <bits/stdc++.h>

int main()
{
	int n;
	int tmp;
	int min=INT_MAX, min_ind=0, max=INT_MIN, max_ind=0;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> tmp;
		if (tmp <= min)	{ min = tmp; min_ind = i; } // closest to end is the one
		if (tmp > max)	{ max = tmp; max_ind = i; } // closest to start is the one
	}
	
	if (max_ind > min_ind)	min_ind++; // if the two must cross, it gains an extra spot
	
	std::cout << (n-1-min_ind+max_ind) << std::endl;

	return 0;
}