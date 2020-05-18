/*
 * https://codeforces.com/problemset/problem/61/A
 */

#include <iostream>
#include <string>

int main()
{
    std::string first_num;
    std::string second_num;
    std::string result;
    std::cin >> first_num >> second_num;
    
    for (int i = 0; i < first_num.length(); i++)
        if (char(first_num[i]) != char(second_num[i]))  result += "1";
        else                                            result += "0";
        
    std::cout << result << std::endl;
    return 0;
}