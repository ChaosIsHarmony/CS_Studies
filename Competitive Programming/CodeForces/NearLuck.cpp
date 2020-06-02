/*
 * https://codeforces.com/problemset/problem/110/A
 */

#include <iostream>

int main()
{
    unsigned long long n;
    std::cin >> n;
    int _4s = 0, _7s = 0;
    
    while (n > 0)
    {
        if (n%10 == 4)      _4s++;
        else if (n%10 == 7) _7s++;
        n /= 10;
    }
    
    if ((_4s+_7s) != 0 && ((_4s+_7s) == 4 || (_4s+_7s) == 7))
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
    
    return 0;
}