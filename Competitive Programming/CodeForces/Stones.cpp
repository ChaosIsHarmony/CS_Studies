/*
 * http://codeforces.com/problemset/problem/266/A
 */

#include <iostream>
#include <string>

int main()
{
	int len;
	std::string s;
	std::cin >> len >> s;
	char ch = char(s[0]);
	int removals = 0;
	
	for (int i = 1; i < len; i++)
	{
		if (char(s[i] == ch))	{ removals++; }
		else					{ ch = char(s[i]); }
	}
	
	std::cout << removals << std::endl;
	
	return 0;
}