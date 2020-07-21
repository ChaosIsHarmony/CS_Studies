/*
 * https://codeforces.com/problemset/problem/1100/A
 
This morning, Roman woke up and opened the browser with n opened tabs numbered from 1 to n. There are two kinds of tabs: those with the information required for the test and those with social network sites. Roman decided that there are too many tabs open so he wants to close some of them.

He decided to accomplish this by closing every k-th (2≤k≤n−1) tab. Only then he will decide whether he wants to study for the test or to chat on the social networks. Formally, Roman will choose one tab (let its number be b) and then close all tabs with numbers c=b+i⋅k that satisfy the following condition: 1≤c≤n and i is an integer (it may be positive, negative or zero).

For example, if k=3, n=14 and Roman chooses b=8, then he will close tabs with numbers 2, 5, 8, 11 and 14.

After closing the tabs Roman will calculate the amount of remaining tabs with the information for the test (let's denote it e) and the amount of remaining social network tabs (s). Help Roman to calculate the maximal absolute value of the difference of those values |e−s|

so that it would be easy to decide what to do next.

Input

The first line contains two integers n and k (2≤k<n≤100) — the amount of tabs opened currently and the distance between the tabs closed.

The second line consists of n integers, each of them equal either to 1 or to −1. The i-th integer denotes the type of the i-th tab: if it is equal to 1, this tab contains information for the test, and if it is equal to −1, it's a social network tab.

Output

Output a single integer — the maximum absolute difference between the amounts of remaining tabs of different types |e−s|.

SAMPLES:
4 2
1 1 -1 1
	2

14 3
-1 1 -1 -1 1 -1 -1 1 -1 -1 1 -1 -1 1
	9
 */

int main()
{
	return 0;
}


