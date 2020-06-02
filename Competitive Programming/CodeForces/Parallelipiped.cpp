/*
 * https://codeforces.com/problemset/problem/224/A
 
 4 6 6
 =28
 because 2 x 2 x 3 dimensions
 
 i, j, k
 - find factors of smallest entry (possible i, j pairs)
 - divide remaining two entries by factors to find k
 
 e.g., 4 - (4,1), (2,2)
	   6/4 1.5
	   6/2 3 MATCH
	   6/4 1.5
	   6/2 3 MATCH
 
 e.g., 20 X 10 X 50
		68
		5 10 2
		10 - (10,1), (5,2)
		20/10 2
		20/5 4 
		20/2 10 MATCH
		50/10  5
		50/5  10 MATCH
		50/2  25
 */

#include<iostream>
#include <vector>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

void getFacts(std::vector<int> &facts, int num)
{
	facts.push_back(1);
	facts.push_back(num);
	for (int i = 2; i < facts.back(); i++)
		if (num%i==0) { facts.push_back(i); facts.push_back(num/i); }
	
}

void matchFacts(std::vector<int> &facts, int j, int k)
{
	int f_1, f_2, f_3;
	for (int i = facts.size()-1; i >= 0; i-=2)
	{
		if (j%facts[i]==0 && k%facts[i-1]==0 && j/facts[i]==k/facts[i-1])
		{ f_1 = facts[i]; f_2 = facts[i-1]; f_3 = k/facts[i-1]; break;}
		if (j%facts[i-1]==0 && k%facts[i]==0 && j/facts[i-1]==k/facts[i])
		{ f_1 = facts[i]; f_2 = facts[i-1]; f_3 = j/facts[i-1]; break;}
	}
	facts.clear();
	facts.push_back(f_1);
	facts.push_back(f_2);
	facts.push_back(f_3);
}

int main()
{
	int i,j,k;
	std::cin >> i >> j >> k;
	
	// get factors for lowest fact
	// match factors for other facts
	std::vector<int> factors;
	if (i <= j && i <= k) 		{ getFacts(factors, i); matchFacts(factors, j, k); }
	else if (j <= i && j <= k)	{ getFacts(factors, j); matchFacts(factors, i, k); }
	else						{ getFacts(factors, k); matchFacts(factors, j, i); }
	
	// print
	Log(4*factors[0] + 4*factors[1] + 4*factors[2]);
	return 0;
}