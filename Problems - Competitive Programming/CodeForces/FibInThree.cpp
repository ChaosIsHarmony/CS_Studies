/*
 * https://codeforces.com/problemset/problem/199/A
 
 if you can use any three fib numbers, then just use 0 + the original two that generate the next fib num
 */

#include<iostream>
#include<string>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

const int fib[] = {	0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733 };

int main()
{
	// input
	int n;
	std::cin >> n;
	
	// determine factors
	int facts[3];
	facts[0] = 0;
	int i = 1;
	while (fib[i] < n)
	{
		facts[1] = fib[i-1];
		facts[2] = fib[i];
		i++;
	}
	
	// in case n is zero, make all entries 0
	if (n==0) { facts[1] = 0; facts[2] = 0; }
	if (n==1) { facts[1] = 0; facts[2] = 1; }

	// print
	Log(std::to_string(facts[0]) + " " + std::to_string(facts[1]) + " " + std::to_string(facts[2]));
	return 0;
}