/*
 *	Programming Abstractions Chap. 2
 *	1 & 2 are reimplementations of their counterparts in Chap. 1 
 */
#include <iostream>
#include <random>
#include <vector>
#include <math.h>

// UTILITIES
template<typename I>
I get_input(I& i) { std::cin >> i; return i; }

template<typename T>
void print(T t) { std::cout << t << std::endl; }


// PROTOTYPES
int problem_three(float);
float problem_four();
bool problem_five(int);
int sum_divisors(int);
bool problem_six(int, std::vector<int>&);
double problem_seven(int);
int problem_nine();
double problem_twelve();
void problem_thirteen();
double problem_fourteen();
void problem_fifteen();

// MAIN
int main()
{
	// Rounding
	//print(problem_three(get_input()));
	
	// Windchill
	//try 						{ print(problem_four()); }
	//catch (const char* msg)	{ print(msg); }
	
	// Perfect Numbers
	//for (int i = 1; i < 10000; i++)	{ problem_five(i); }
	
	// IsPrime
	//std::vector<int> primes;
	//primes.push_back(2);
	//for (int i = 3; i < 101; i++)	{ print(i); print(problem_six(i, primes)); }
	
	// Successive approx for roots
	//print(problem_seven(get_input()));
	
	// Permutations
	//print(problem_nine());

	// Random Average
	//print(problem_twelve());
	
	// Radioactive decay
	//problem_thirteen();

	// Estimating pi
	//print(problem_fourteen());

	// Three consecutive heads
	problem_fifteen();

	return 0;
}


// IMPLEMENTATIONS
int problem_three(float f) { return int(f+0.5); }

float problem_four()
{ 
	float temp;
	get_input(temp);
	float wind_spd;
	get_input(wind_spd);
	
	if (wind_spd == 0)	return temp;
	else if (temp > 40)	throw "Undefined above 40C";
	else				return (35.74 + (0.6215*temp) - (35.75*powf(wind_spd,0.16)) +(0.4275*temp*powf(wind_spd,0.16))); }

bool problem_five(int n)
{
	if (sum_divisors(n) == n)	{ print(n); return true; }
	else						return false;
}

int sum_divisors(int n)
{
	int sum = 0;
	for (int i = 1; i <= n/2; i++)
	{
		if (n%i == 0)	sum += i;
	}
	return sum;
}

bool problem_six(int n, std::vector<int> &primes)
{
	for (int i : primes)
	{
		if (i > n/2)	{ primes.push_back(n); return true; }
		if (n%i==0)		return false;
	}
	
	return true;
}

const double EPSILON = 0.0001;
double problem_seven(int base)
{
	double g = base/2;
	//My solution:
	//while (g*g < base-EPSILON || g*g > base+EPSILON)	{ g = (g + base/g)/2; }
	//Book's request:
	while (true)
	{ 
		double og = g;
		g = (g + base/g)/2;
		if (g == og || g == base/og)	break;
	}
	return g;
}

int problem_nine()
{
	// get input
	int n;
	get_input(n);
	int k;
	get_input(k);
	
	// process
	int limit = n-k;
	int product = n--;
	while(n>limit) { product *= n--; }
	return product;
}

double problem_twelve()
{
	int n_trials;
	get_input(n_trials);
	double average;

	// random number generator
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(0.0, 1.0);

	// Generate random numbers [0-1], average them and return their average
	for (int i = 0; i < n_trials; i++) average += dist(mt);

	return average/n_trials;
}


void problem_thirteen()
{
	int years = 0;
	int atoms;
	get_input(atoms);
	
	// random number generator
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(0.0, 1.0);

	std::string output;

	while (atoms > 0)
	{ 
		for (int i = 0; i < atoms; i++) { if (dist(mt) < 0.5) atoms--; }
		output = "There are " + std::to_string(atoms) + " atoms at the end of year " + std::to_string(++years) + "."; 
		print(output);
	}
}

double problem_fourteen()
{
	int num_darts;
	double x, y;
	int darts_in_circ = 0;
	get_input(num_darts);

	// random number generator
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(-1.0, 1.0);

	for (int i = 0; i < num_darts; i++)
	{
		x = dist(mt);
		y = dist(mt);

		if ((x*x+y*y)<1) darts_in_circ++;
	}

	return double(darts_in_circ)/(num_darts-darts_in_circ);
}


void problem_fifteen()
{
	int threshold;
	get_input(threshold);

	int heads_run = 0;
	int tot_flips = 0;

	// random number generator
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(0.0, 1.0);

	while (heads_run < threshold) 
	{ 
		heads_run = (dist(mt) < 0.5) ? heads_run+1 : 0;
		tot_flips++;
	}

	std::string output = "It took " + std::to_string(tot_flips) + " to get " + std::to_string(threshold) + " heads in a row.";
	print(output);
}
