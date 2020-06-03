/*
 * https://codeforces.com/problemset/problem/96/A
 */
#include <iostream>
#include <string>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

int main()
{
	std::string s, ans = "NO";
	std::cin >> s;
	char ch = char(s[0]);
	int cnt = 1;
	
	for(int i = 1; i < s.length(); i++)
	{
		if (ch == char(s[i]))	cnt++;
		else					cnt = 1;
		if (cnt == 7)			{ ans = "YES"; break; }
		ch = char(s[i]);
	}
	
	Log(ans);
	
	return 0;
}