/*
 * https://codeforces.com/contest/148/problem/A
 */

#include <iostream>
#include <vector>

bool inVec(std::vector<int> &v, int e)
{
	for(int i = 0; i < v.size(); i++)
		if (v.at(i)==e) return true;
	return false;
}

bool divisByOther(int e, std::vector<int> &v, int skip)
{
	for (int i = skip+1; i < v.size(); i++) 
		if (e%v.at(i)==0) return true;
	return false;
}

int main()
{
	// get total dragons
	int nD[5];
	bool all_drag = false;
	for (int i = 0; i < 5; i++)
	{
		std::cin >> nD[i];
		if (i != 4 && nD[i] == 1)	all_drag = true;
	}
	
	// one among the divisors; all dragons suffer
	if (all_drag)		{ std::cout << nD[4] << std::endl; return 0; }
	// if number of dragons is less that k, l, m, n
	if (nD[0] > nD[4] && nD[1] > nD[4] && nD[2] > nD[4] && nD[3] > nD[4])
		{ std::cout << 0 << std::endl; return 0; }
	
	// eliminate redundancy
	std::vector<int> toCheck;
	for (int i = 0; i < 4; i++)
	{ 
		bool add = true;
		for (int j = 0; j < 4; j++)
		{
			if (j != i && (nD[i]%nD[j]==0))
				add = false;
			if (nD[i]==nD[j] && !inVec(toCheck,nD[i]))
				add = true;
		}	
		if (add)
			toCheck.push_back(nD[i]);
	}
		
	// all factors
	std::vector<int> facts;
	for (int i = 0; i < toCheck.size(); i ++)
		for (int j = toCheck.at(i); j <= nD[4]; j+=toCheck.at(i))
			if (!divisByOther(j, toCheck, i)) facts.push_back(j);
	
	// return count of all non-prime numbers up to (-1 is for 1st dragon)
	std::cout << facts.size() << std::endl;
	
	return 0;
}