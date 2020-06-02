/*
 * https://codeforces.com/problemset/problem/133/A
 */

#include <iostream>
#include <string>
#include <set>

static std::set<char> instr = {'H', 'Q', '9'};

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

int main()
{
	std::string s;
	std::cin >> s;
	for (int i = 0; i < s.length(); i++)
		if (instr.find(char(s[i])) != instr.end()) { Log("YES"); return 0; }
	
	Log("NO");
	return 0;
}