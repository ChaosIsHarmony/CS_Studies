/*
 * http://codeforces.com/problemset/problem/281/A
 */

#include <iostream>

int main()
{
	std::string w;
	std::cin >> w;
	
	if (char(w[0]) < 97)	{ std::cout << w << std::endl; }
	else					{ std::cout << char(w[0]-32) << w.substr(1) << std::endl; }
						
	return 0;
}