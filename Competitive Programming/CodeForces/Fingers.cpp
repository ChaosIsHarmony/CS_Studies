/*
 * https://codeforces.com/problemset/problem/272/A
 */

#include <iostream>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

int getInt(std::istream& st)
{
	int n;
	std::cin >> n;
	return n;
}

int main()
{
	int nFriends, nFings = 0;
	std::cin >> nFriends;
	for (int i = 0; i < nFriends; i++)
		nFings += getInt(std::cin);
	
	// under 4 friends means more chances on landing on dima
	if (nFriends == 1)		Log((nFings%2==0) ? 2 : 3);
	else if (nFriends == 2)	Log((nFings%3==0 || nFings%3==2) ? 3 : 4);
	else if (nFriends == 3)	Log((nFings%4==0) ? 3 : 4);
	else if (nFriends == 4)	Log(4);
	// 5+ friends means there's only one chance max, sometimes 0
	else					
	{
		// this is the interval where it's impossible for him to lose
		// i.e.,	where nFings%(nFriends+1) is between [1,(nFriends+1-5)]
		// because always starts on dima AND total people (nFriends+1) minus dima's fingers (5<=)
		// means only possible losses occur on mod = 0 and the 4 before it
		if ((nFings%(nFriends+1) > 0) && (nFings%(nFriends+1) <= (nFriends+1-5)))
			Log(5);
		else
			Log(4);
	}
	
	
	return 0;
}