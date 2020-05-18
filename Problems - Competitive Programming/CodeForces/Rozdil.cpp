/*
 * https://codeforces.com/problemset/problem/205/A
 
 consider the case that there are multiple cities the same distance away,
 BUT that there is also one that is closer than them
 THUS, must traverse the whole list
 */

#include <iostream>

int main()
{
	//input
	int n, tmp, min_city_ind, min = 1000000001;
	std::cin >> n;
	bool still_R = false;
	for (int i = 1; i <= n; i++)
	{
		std::cin >> tmp;
		if (tmp == min)	{ still_R = true; }
		if (tmp < min)	{ min = tmp; min_city_ind = i; still_R = false; }
	}
	
	//output
	if (still_R)	std::cout << "Still Rozdil" << std::endl;
	else			std::cout << min_city_ind << std::endl;
	return 0;
}