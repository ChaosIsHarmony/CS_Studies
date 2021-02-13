/*
 * https://codeforces.com/problemset/problem/214/A
 
 Furik loves math lessons very much, so he doesn't attend them, unlike Rubik. But now Furik wants to get a good mark for math. For that Ms. Ivanova, his math teacher, gave him a new task. Furik solved the task immediately. Can you?

You are given a system of equations:

	a^2 + b = n
	a + b^2 = m

You should count, how many there are pairs of integers (a, b) (0 ≤ a, b) which satisfy the system.
Input

A single line contains two integers n, m (1 ≤ n, m ≤ 1000) — the parameters of the system. The numbers on the line are separated by a space.
Output

On a single line print the answer to the problem.

SAMPLE:
9 3
	1

14 28
	1

4 20
	0

Lessons Learned:
  Forgot to heed the stipulation that 0<=a,b (i.e., no negative values)
  This messed me up on n=1 m=11 input
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