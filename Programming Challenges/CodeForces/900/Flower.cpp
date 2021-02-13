/*
 * https://codeforces.com/problemset/problem/149/A
 
 

What joy! Petya's parents went on a business trip for the whole year and the playful kid is left all by himself. Petya got absolutely happy. He jumped on the bed and threw pillows all day long, until...

Today Petya opened the cupboard and found a scary note there. His parents had left him with duties: he should water their favourite flower all year, each day, in the morning, in the afternoon and in the evening. "Wait a second!" — thought Petya. He know for a fact that if he fulfills the parents' task in the i-th (1 ≤ i ≤ 12) month of the year, then the flower will grow by a i centimeters, and if he doesn't water the flower in the i-th month, then the flower won't grow this month. Petya also knows that try as he might, his parents won't believe that he has been watering the flower if it grows strictly less than by k centimeters.

Help Petya choose the minimum number of months when he will water the flower, given that the flower should grow no less than by k centimeters.

Input

The first line contains exactly one integer k (0 ≤ k ≤ 100). The next line contains twelve space-separated integers: the i-th (1 ≤ i ≤ 12) number in the line represents a i (0 ≤ a i ≤ 100).

Output

Print the only integer — the minimum number of months when Petya has to water the flower so that the flower grows no less than by k centimeters. If the flower can't grow by k centimeters in a year, print -1.
 
 SAMPLES:
 5
 1 1 1 1 2 2 3 2 2 1 1 1
	2

 0
 0 0 0 0 0 0 0 1 1 2 3 0
	0

 11
 1 1 4 1 1 5 1 1 4 1 1 1
	3
 
 Problems:
 Neglected stipulation that k could be impossible to achieve
 */
#include <iostream>
#include <algorithm>

template<typename T>
Log(T t) { std::cout << t << std::endl; }

int main()
{
	int k, tot=0, months = 0;
	int growth[12];
	std::cin >> k;
	if (k > 0) {
		for (int i = 0; i < 12; i++)
		{ std::cin >> growth[i]; tot+=growth[i]; }

		// impossible to achieve
		if (k > tot)	months = -1;
		// doable
		else
		{
			std::sort(growth, growth+12);
			
			for (int ind = 11; ind >= 0; ind--)
			{
				tot+=growth[ind];
				months++;
				if (tot >= k)	break;
			}
		}
	}
	
	Log(months);
	return 0;
}