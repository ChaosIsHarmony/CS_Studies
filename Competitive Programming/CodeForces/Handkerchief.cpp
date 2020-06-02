/*
 * https://codeforces.com/problemset/problem/118/B
 */
#include <iostream>
#include <string>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

void buildLine(int n, int spaces, std::string &line)
{
	// add init spaces
	for (int sp = 0; sp < spaces; sp++)
		line += " ";
	// add nums
	for (int j = 0; j <= n*2; j++)
	{
		if ((j > n || n == 0) && j == 0)	line += std::to_string(j);
		else if (j <= n)					line += std::to_string(j) + " ";
		else if (j < n*2)					line += std::to_string(n-(j-n)) + " ";
		else								line += std::to_string(n-(j-n));
	}
}

int main()
{
	// input
	int n;
	std::cin >> n;
	
	// process & output
	std::string line;
	for (int i = 0; i < (2*n+1); i++)
	{	
		line = "";
		if (i < (n+1))	buildLine(i, (2*(n-i)), line);
		else
		{
			if (i%n!=0)	buildLine((n-(i%n)), (2*(n-(n-(i%n)))), line);
			else		buildLine(0, (2*n), line);
		}
		Log(line);
	}
	
	return 0;
}