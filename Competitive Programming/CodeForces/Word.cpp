/*
 * http://codeforces.com/problemset/problem/59/A
 */

#include <iostream>
#include <string>
     
int main()
{
	std::string s;
	std::cin >> s;
	int lc = 0;
        
    for (int i = 0; i < s.length(); i++)
		if (char(s[i]) > 96)   lc++;
        
	std::string ans = "";
    if ((s.length()+1)/2 > lc)
    { //upper
    	for (int i = 0; i < s.length(); i++)
        	if (char(s[i]) > 96)    ans += char(s[i]-32);
            else                    ans += char(s[i]);
    } else
    {
        for (int i = 0; i < s.length(); i++)
    	    if (char(s[i]) > 96)    ans += char(s[i]);
            else                    ans += char(s[i]+32);
    }
        
    std::cout << ans;
	return 0;
}