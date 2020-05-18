/*
 * https://codeforces.com/problemset/problem/214/A
 * 
 * Forgot to heed the stipulation that 0<=a,b (i.e., no negative values)
 * This messed me up on n=1 m=11 input
 */
#include <iostream>

template<typename T>
Log(T t) { std::cout << t << std::endl; }

int main()
{
	int n, m, cnt=0;
	//std::cin >> n >> m;
	for (n = 1; n <=1000; n++)
		for(m = 1; m <=1000; m++)
			// a^4-2na^2+a = m-n^2
			for (int i = -1001000; i < 1001000; i++)
				if ((i*i*i*i)-(2*n*i*i)+i == (m-(n*n))
					&& i >= 0
					&& (n-(i*i)) >= 0) cnt++;
	
	if ((m-(n*n))>0 && cnt>0) Log("Huh?");
	
	Log(cnt);
	return 0;
}