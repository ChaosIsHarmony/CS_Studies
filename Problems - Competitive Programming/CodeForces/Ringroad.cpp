/*
 * https://codeforces.com/problemset/problem/339/B
 
 Very poorly phrased question...
 n = num houses
 m = num tasks
 a[m] = {house_num_task_1, ... , house_num_task_m]
 
 e.g.,	4 3 
		3 2 3 
		= 6
		4 3 
		2 3 3 
		= 2
 
 Goal: find out min time required to go to each house w/o back-tracking
 */
 #include <iostream>
 #include <cmath>
 
 int main()
 {
	// input
	int n, m, hs_1, hs_2;
	std::cin >> n >> m >> hs_1;
	// process
	long long ans = hs_1-1;
	for (int i = 0; i < m-1; i++)
	{
		std::cin >> hs_2;
		if (hs_1-hs_2 <= 0)	ans+= std::abs(hs_1-hs_2);
		else 				ans += (n-hs_1) + hs_2;
		hs_1 = hs_2;
	}
	// output
	std::cout << ans << std::endl;
	return 0;
 }