/*
 * https://codeforces.com/problemset/problem/34/B
 */
#include <iostream>
#include <algorithm>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

int main()
{
	// input & process
	int n, m, price, num_neg = 0, neg_tot = 0;
	std::cin >> n >> m;
	int prices[n];

	for (int i = 0; i < n; i++)
	{
		std::cin >> price;
		prices[i] = 0;
		if (price < 0)	{ prices[i] = price; num_neg++; neg_tot += price; }
	}

	// output
	if (num_neg <= m )	Log((-1*neg_tot));
	else
	{
		neg_tot = 0;
		std::sort(prices, prices+n);
		for (int i = 0; i < m; i++)
			neg_tot += prices[i];
		Log((-1*neg_tot));
	}
	return 0;
}