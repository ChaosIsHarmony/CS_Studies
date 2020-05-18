/*
 * https://codeforces.com/problemset/problem/219/A
 */
#include <iostream>
#include <string>

const int ascii_a = 97, ascii_z = 122;
int main()
{
	// INPUT
	std::string s, tmp="", ans="";
	int n;
	std::cin >> n;
	std::cin >> s;
	// count num of individual chars
	int char_map[ascii_z-ascii_a+1]; //range of ascii chars
	for (int i = 0; i < (ascii_z-ascii_a+1); i++)
		char_map[i]=0;
	for (int i = 0; i < s.length(); i++)
	{
		char_map[char(s[i])-ascii_a]++;
	}
	
	// PROCESS
	// if one of the chars is not divisible by n, then it cannot be repeated n times
	for (int i = 0; i < (ascii_z-ascii_a+1); i++)
		if (char_map[i]%n != 0)		ans = "-1";
	// make repeatable string
	if (ans != "-1")
		for (int i = 0; i < (ascii_z-ascii_a+1); i++)
			if (char_map[i] > 0)
				for (int j = 0; j < char_map[i]/n; j++)
					tmp+=char(i+ascii_a);
	// copy repeatable string n times
	for (int i = 0; i < n; i++)
		ans+=tmp;
	
	// OUTPUT
	std::cout << ans << std::endl;
	return 0;
}