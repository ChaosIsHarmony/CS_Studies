/*
 * https://codeforces.com/problemset/problem/339/A
 */

#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;

int main()
{
	std::string sum;
	std::cin >> sum;
	int num[3] = {0, 0, 0};
	for (int i = 0; i < sum.length(); i++)
		switch (char(sum[i]))
		{
			case '1':	num[0]++; break;
			case '2':	num[1]++; break;
			case '3':	num[2]++; break;
		}
	
	std::string new_sum = "";
	for (int i = 0; i < num[0]; i++)
		new_sum += "1+";
	for (int i = 0; i < num[1]; i++)
		new_sum += "2+";
	for (int i = 0; i < num[2]; i++)
		new_sum += "3+";
	
	std::cout << new_sum.substr(0,new_sum.length()-1) << std::endl;
	
	return 0;
}