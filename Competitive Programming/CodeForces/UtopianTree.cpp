/*
 * https://www.hackerrank.com/challenges/utopian-tree/problem
 */

#include <iostream>

/*---------------
 * prototypes
 *---------------
 */

int grow(int num, int nTimes);

/*---------------
 * Main program
 *---------------
 */

int utopianTree(int n) {
    switch (n)
    {
        case 0:
            return 1;
        case 1:
            return 2;
        default:
			if (n%2 == 0)	return 1+grow(1, n-1);
			else			return grow(1, n);
    }
}

int grow(int num, int nTimes)
{
	std::cout << num << std::endl;
    // base case
    if (nTimes == 0)    return num;
    // even cycle OR odd
    if (nTimes%2 == 0)  return grow(num+1, nTimes-1);
    else                return grow(2*num, nTimes-1);
}

int main()
{
	int n;
	std::cout << "How many cycles?" << std::endl;
	std::cin >> n;
	std::cout << utopianTree(n) << std::endl;
}
	