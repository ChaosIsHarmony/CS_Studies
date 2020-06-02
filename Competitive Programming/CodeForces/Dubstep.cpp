/*
 * https://codeforces.com/problemset/problem/208/A
 */
#include <iostream>
#include <string>

int main()
{
	std::string s, ans="";
	std::cin >> s;
	for (int i = 0; i < s.length(); )
	{
		if (char(s[i]) == 'W' && char(s[i+1]) == 'U' && char(s[i+2]) == 'B')
			i += 3;
		else if (char(s[i+1]) == 'W' && char(s[i+2]) == 'U' && char(s[i+3]) == 'B')
		{
			ans += s[i];
			ans += " ";
			i += 4;
		}
		else
		{
			ans += s[i];
			i++;
		}
	}
	
	std::cout << ans << std::endl;
	return 0;
}