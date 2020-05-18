/*
 * https://codeforces.com/problemset/problem/230/A
 */
#include <iostream>
#include <algorithm>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

struct Dragon {
	int d_s;
	int bonus;
};

bool sortDrag(Dragon const& lhs, Dragon const& rhs)
{ return lhs.d_s < rhs.d_s; }

int main()
{
	bool possible = true;
	// input
	int s, dup_s, n;
	std::cin >> s >> n;
	Dragon dragons[n];
	dup_s = s;
	for (int i = 0; i < n; i++)
	{
		std::cin >> dragons[i].d_s >> dragons[i].bonus;
		// try seeing if it works w/o sorting
		if (possible)
		{	
			if (dup_s <= dragons[i].d_s)	possible = false;
			else							dup_s+= dragons[i].bonus;
		}
	}
	
	// process (if needs to be sorted)
	if (!possible)
	{
		possible = true; // reset
		std::sort(dragons, dragons+n, &sortDrag);
		for (int i = 0; i < n; i++)
		{
			if (s <= dragons[i].d_s)	{ possible = false; break;}
			else						s+= dragons[i].bonus;
		}
	}
	
	// output
	Log((possible) ? "YES" : "NO");
	return 0;
}