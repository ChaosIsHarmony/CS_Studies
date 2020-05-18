/*
 * https://codeforces.com/problemset/problem/124/A
 */
 
#include <iostream>
 
int min(int a, int b) { return (a > b) ? b : a; }
 
int main()
{
    int n, a, b;
    std::cin >> n >> a >> b;
    std::cout << min(n-a, b+1) << std::endl;    
    return 0;
}