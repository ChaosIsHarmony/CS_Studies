/*
 * https://codeforces.com/problemset/problem/141/A
 */
 
#include <iostream>
#include <string>
#include <map>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

int main()
{
	std::string n_1, n_2, lts;
	std::cin >> n_1 >> n_2 >> lts;
	std::map<char,int> name_lts;
	std::map<char,int> avail_lts;
	bool can_use = true;
	
	// split into maps
	// two names
	for (int i = 0; i < n_1.length(); i++)
		if (name_lts.find(char(n_1[i])) != name_lts.end())	name_lts[char(n_1[i])]++; 
		else												name_lts[char(n_1[i])] = 1;
	
	for (int i = 0; i < n_2.length(); i++)
		if (name_lts.find(char(n_2[i])) != name_lts.end())	name_lts[char(n_2[i])]++; 
		else												name_lts[char(n_2[i])] = 1;
	// available letters
	for (int i = 0; i < lts.length(); i++)
		if (avail_lts.find(char(lts[i])) != avail_lts.end())	avail_lts[char(lts[i])]++; 
		else													avail_lts[char(lts[i])] = 1;
	
	// equality checks
	// size
	if (name_lts.size() != avail_lts.size())	can_use = false;
	// contents
	else 
	{
		std::map<char, int>::iterator it;

		for ( it = avail_lts.begin(); it != avail_lts.end(); it++ )
		{
			char key = it->first;
			int val = it->second;
			if (avail_lts.find(key) == avail_lts.end())	{ can_use = false; break; }
			else if (avail_lts[key] != name_lts[key])	{ can_use = false; break; }
		}
	}
	
	// output
	if (can_use)	Log("YES");
	else			Log("NO");
	
	return 0;
}