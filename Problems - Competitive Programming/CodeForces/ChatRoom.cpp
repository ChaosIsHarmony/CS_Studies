/*
 * https://codeforces.com/problemset/problem/58/A
 */
#include <iostream>
#include <string>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

int main()
{
	// input
	std::string typed;
	std::cin >> typed;
	
	// process
	bool letters[5];
	letters[0] = false;	letters[1] = false;	letters[2] = false;	letters[3] = false;	letters[4] = false;
	for (int i = 0; i < typed.length(); i++)
	{
		// check if letters appear in correct sequence
		if (!letters[0]) 		letters[0] = char(typed[i]) == 'h';
		else if (!letters[1])	letters[1] = char(typed[i]) == 'e';
		else if (!letters[2])	letters[2] = char(typed[i]) == 'l';
		else if (!letters[3])	letters[3] = char(typed[i]) == 'l';
		else if (!letters[4])	letters[4] = char(typed[i]) == 'o';
		// break if all are already found
		if (letters[4])	break;
	}
	
	// output
	// YES if all found in correct sequence
	if (letters[4])	Log("YES");
	else			Log("NO");
	
	return 0;
}