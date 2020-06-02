/*
 * https://codeforces.com/problemset/problem/228/A
 */

#include <iostream>
#include <set>

template<typename T>
void LOG(T t) { std::cout << t << std::endl; }

int main()
{
	int shoes[4];
	std::cin >> shoes[0];
	std::cin >> shoes[1];
	std::cin >> shoes[2];
	std::cin >> shoes[3];
	int shoes_2_buy = 0;
	std::set<int> used;
	
	for(int i = 0; i < 3; i++)
	{
		if (used.find(shoes[i])!=used.end()) continue;
		used.insert(shoes[i]);
		
		for(int j = i+1; j < 4; j++)
			if (shoes[i]==shoes[j]) shoes_2_buy++;
	}
	
	LOG(shoes_2_buy);
			
	return 0;
}