/*
 * https://codeforces.com/problemset/problem/337/A
 */
#include <iostream>
#include <algorithm>
#include <climits>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

int main()
{
	// input 
	int nStud, nPuzz;
	std::cin >> nStud >> nPuzz;
	int puzzles[nPuzz];
	for (int i = 0; i < nPuzz; i++)
	{ std::cin >> puzzles[i]; }
	
	// process
	std::sort(puzzles, puzzles+nPuzz);
	int min = INT_MAX, upper;
	for (int lower = 0; lower <= nPuzz-nStud; lower++)
	{
		upper = lower+nStud-1;
		if (puzzles[upper] - puzzles[lower] < min)	min = puzzles[upper] - puzzles[lower]; 
	}
	
	// output
	Log(min);
	return 0;
}