/*
 * https://codeforces.com/problemset/problem/320/A
 */
 #include <iostream>
 #include <string>
 
 bool poss(std::string &str, char ch, int &i, int cnt)
 {
	if (cnt == 0)		return false;
	if (ch == '1')		return true;
	if (ch == '4')		return poss(str, char(str[--i]), i, --cnt);
	else				return false;
 }
 
 int main()
 {
	// input
	std::string n;
	std::cin >> n;
	// process
	char ch;
	bool yes = true;
	for (int i = n.size()-1; i >= 0 ; i--)
	{
		ch = char(n[i]);
		if (poss(n, ch, i, 3))	continue;
		else 					{ yes = false; break; }
	}
	// output
	std::cout << ((yes) ? "YES" : "NO") << std::endl;
	return 0;
 }