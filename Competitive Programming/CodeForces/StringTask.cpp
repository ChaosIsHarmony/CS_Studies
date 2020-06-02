/*
 * https://codeforces.com/problemset/problem/118/A
 */
#include <iostream>
#include <string>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

void removeVowels(std::string &s)
{
	std::string tmp_str = "";
	char ch;
	for (int i = 0; i < s.length(); i++)
	{
		ch = char(s[i]);
		if(!(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' || ch=='Y' 
			|| ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='y'))
			tmp_str += ch;
	}
	s = tmp_str;
}

void toLower(std::string &s)
{
	std::string tmp_str = "";
	char ch;
	for(int i = 0; i < s.length(); i++)
	{
		ch = char(s[i]);
		tmp_str += ch | ' ';
	}
	s = tmp_str;
}

void insertDot(std::string &s)
{
	std::string tmp_str = "";
	for(int i = 0; i < s.length(); i++)
	{
		tmp_str += '.';
		tmp_str += char(s[i]);
	}
	s = tmp_str;
}

int main()
{
	// input
	std::string s;
	std::cin >> s;
	// process
	removeVowels(s);
	toLower(s);
	insertDot(s);
	// output
	Log(s);
	
	return 0;
}