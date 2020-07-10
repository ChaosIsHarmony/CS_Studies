/*
 *	Programming Abstractions Chap. 2
 *	1 & 2 are reimplementations of their counterparts in Chap. 1 
 */
#include <iostream>
#include <math.h>

// UTILITIES
float get_input() { float i; std::cin >> i; return i; }

template<typename T>
void print(T t) { std::cout << t << std::endl; }


// PROTOTYPES
int problem_three(float);
float problem_four();
bool problem_five(int);
int sum_divisors(int);


// MAIN
int main()
{
	// Rounding
	//print(problem_three(get_input()));
	
	// Windchill
	//try 						{ print(problem_four()); }
	//catch (const char* msg)	{ print(msg); }
	
	// Perfect Numbers
	for (int i = 1; i < 10000; i++)	{ problem_five(i); }
	
	return 0;
}


// IMPLEMENTATIONS
int problem_three(float f) { return int(f+0.5); }

float problem_four()
{ 
	float temp = get_input();
	float wind_spd = get_input();
	
	if (wind_spd == 0)	return temp;
	else if (temp > 40)	throw "Undefined above 40C";
	else				return (35.74 + (0.6215*temp) - (35.75*powf(wind_spd,0.16)) +(0.4275*temp*powf(wind_spd,0.16))); }

//INCOMPLETE
bool problem_five(int n)
{
	if (sum_divisors(n) == n)	{ print(n); return true; }
	else						return false;
}

int sum_divisors(int n)
{
	int sum = 0;
	for (int i = 1; i < n/2; i++)
	{
		if (n%i == 0)	sum += i;
	}
	return sum;
}





