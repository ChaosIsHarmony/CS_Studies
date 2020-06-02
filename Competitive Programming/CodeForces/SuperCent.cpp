/*
 * https://codeforces.com/problemset/problem/165/A
 */

#include <iostream>

struct Point {
	int x;
	int y;
	bool hasN = false;
	bool hasE = false;
	bool hasS = false;
	bool hasW = false;
};

int main()
{
	// load points
	int n;
	std::cin >> n;
	Point p_arr[n];
	for (int i = 0; i < n; i++)
	{
		int x, y;
		std::cin >> x >> y;
		Point p;
		p.x = x;
		p.y = y;
		p_arr[i] = p;
	}
	
	// go thru points and keep track of ones with neighbors
	// then track supercentral points
	int sc = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			if (p_arr[i].x == p_arr[j].x)
			{
				if (p_arr[i].y < p_arr[j].y) p_arr[i].hasN = true;
				if (p_arr[i].y > p_arr[j].y) p_arr[i].hasS = true;
			} else if (p_arr[i].y == p_arr[j].y)
			{
				if (p_arr[i].x < p_arr[j].x) p_arr[i].hasW = true;
				if (p_arr[i].x > p_arr[j].x) p_arr[i].hasE = true;
			}
		}
		// increment supercentral counter
		if (p_arr[i].hasN 
			&& p_arr[i].hasE 
			&& p_arr[i].hasS 
			&& p_arr[i].hasW)
			{ sc++; }
	}
	
	// output
	std::cout << sc << std::endl;
	
	return 0;
}