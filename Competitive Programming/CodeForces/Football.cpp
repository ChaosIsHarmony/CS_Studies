/*
 * https://codeforces.com/problemset/problem/43/A
 */
#include <iostream>
#include <string>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

int main()
{
	int n, t_a = 0, t_b = 0;
	std::cin >> n;
	std::string team_a, team_b = "?", tmp;
	std::cin >> team_a;
	t_a++;
	for (int i = 0; i < n-1; i++)
	{
		std::cin >> tmp;
		if (tmp.compare(team_a)==0)	t_a++;
		else						{ team_b = tmp; t_b++; }
		
		if (t_a != t_b && (t_a > n/2 || t_b > n/2))	break;
	}
	
	if (t_a > t_b)	Log(team_a);
	else			Log(team_b);
	return 0;
}