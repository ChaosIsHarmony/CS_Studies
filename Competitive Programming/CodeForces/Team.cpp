/*
 * https://codeforces.com/problemset/problem/231/A
 */

#include <iostream>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

int main()
{
	int problems_solved = 0;
	int comps, can_solve, prob;
	std::cin >> comps;
	for (int i = 0; i < comps; i++)
	{
		can_solve = 0;
		for (int j = 0; j < 3; j++)
		{
			std::cin >> prob;
			if (prob == 1)		can_solve++;
		}
		if (can_solve >= 2)		problems_solved++;
	}
				
	Log(problems_solved);
	return 0;
}