/*
 * https://codeforces.com/problemset/problem/227/B
 */

#include <iostream>
#include <map>

template<typename T>
void Log(T t_1, T t_2) { std::cout << t_1 << " " << t_2 << std::endl; }

int main()
{
	// input
	long long size, queries, tmp;
	std::cin >> size;
	std::map<long long,long long> elements;
	for(int i = 0; i < size; i++)
	{
		std::cin >> tmp;
		elements[tmp] = i; // tmp = element, i = index
	}
	std::cin >> queries;
	
	// helper
	unsigned long long v_comp = 0, p_comp = 0;
	unsigned long long result;

	// find element
	for(int i = 0; i < queries; i++)
	{
		std::cin >> tmp; // query
		if (elements.find(tmp) != elements.end())
		{ 
			result = elements[tmp]+1; 
			v_comp += result;
			p_comp += size-(result-1);
		}
		else
		{
			v_comp += size;
			p_comp += size;
		}
		
	}
		
	Log(v_comp, p_comp);
	return 0;
}