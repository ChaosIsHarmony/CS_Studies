/*
 * https://codeforces.com/problemset/problem/1163/A

 The three friends, Kuro, Shiro, and Katie, met up again! It's time for a party...

What the cats do when they unite? Right, they have a party. Since they wanted to have as much fun as possible, they invited all their friends. Now n cats are at the party, sitting in a circle and eating soup. The rules are simple: anyone having finished their soup leaves the circle.

Katie suddenly notices that whenever a cat leaves, the place where she was sitting becomes an empty space, which means the circle is divided into smaller continuous groups of cats sitting next to each other. At the moment Katie observes, there are m cats who left the circle. This raises a question for Katie: what is the maximum possible number of groups the circle is divided into at the moment?

Could you help her with this curiosity?

Input

The only line contains two integers n and m (2≤n≤1000, 0≤m≤n) — the initial number of cats at the party and the number of cats who left the circle at the moment Katie observes, respectively.

Output

Print a single integer — the maximum number of groups of cats at the moment Katie observes.

SAMPLE:
7 4
	3

6 2
	2

3 0
	1

2 2
	0

Observations:
	- A group is defined as a vertex of degree x and all its connected nodes, even if x = 0
	- How can you remove m vertices to leave the maximum number of groups?
 */
template<typename T>
void print(T t) { std::cout << t << std::endl; }

int main()
{

	return 0;
}