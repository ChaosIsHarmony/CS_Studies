/*
 * https://codeforces.com/problemset/problem/41/A
 */
#include <iostream>
#include <string>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

int main()
{
	std::string s, t, ans = "NO";
	std::cin >> s >> t;
	
	if (s.size() == t.size())
	{
		ans = "YES";
		for (int i = 0; i < s.size(); i++)
			if (char(s[i]) != char(t[t.size()-1-i])) { ans = "NO"; break; }
	}
	
	Log(ans);
	return 0;
}