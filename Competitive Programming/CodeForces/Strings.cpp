/*
 * https://codeforces.com/problemset/problem/112/A
 */

#include <iostream>
#include <string>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

/*
 * 		01000001 (char 'A')
 *	Or	00100000 (char ' ')
 *	= 	01100001 (char 'a')
 *	----------------------
 *		01100001 (char 'a')
 *	Or 	00100000 (char ' ')
 *	= 	01100001 (char 'a')
 */
char upper(char c)
{
	return c | ' ';
}

int main()
{
	std::string s_1, s_2;
	std::cin >> s_1 >> s_2;
	
	for (int i = 0; i < s_1.length(); i++)
		if (upper(char(s_1[i])) != upper(char(s_2[i])))
		{ Log((upper(char(s_1[i]))-upper(char(s_2[i])) > 0) ? 1 : -1); return 0; }
	
	Log("0");
	return 0;
}