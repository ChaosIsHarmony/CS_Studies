# https://projecteuler.net/problem=12
#
# The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be:
#	1 + 2 + 3 + 4 + 5 + 6 + 7 = 28.
# The first ten terms would be:
#	1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
# Let us list the factors of the first seven triangle numbers:
#	1: 1
#	3: 1,3
#	6: 1,2,3,6
#	10: 1,2,5,10
#	15: 1,3,5,15
#	21: 1,3,7,21
#	28: 1,2,4,7,14,28
# [My addition]
#	36: 1,2,3,4,6,9,12,18,36
#	45: 1,3,5,9,15,45
#	55: 1,5,11,55
#	66: 1,2,3,6,11,22,33,66
# We can see that 28 is the first triangle number to have over five divisors.
# What is the value of the first triangle number to have over five hundred divisors?
#
# Ans:

# Observations:
#	- first div is always 1, last is always itself
#	- second is 2 if even, 3 if odd (?)(no, 55)
#	- n_div can decrease (e.g., 36->45)
#	- always pair (hi-lo, e.g., 6: 1-6, 2-3); thus fact must = 502
#	- second highest must be <= num/2

# Ideas:
#	- Build dictionary of triangle nums, if next num is div by any triangle num, all its divisors should be added to the list for that num
#		- e.g., 3 | 6, thus all of 3's divs go into 6,
import math

# use binary search
def in_divs(divs, e):
	if len(divs) == 0:	return False
	hi = len(divs)-1
	mid = hi//2
	lo = 0
	while not mid > hi and not mid < lo:
		#print(mid)
		#print(f'e: {e} and sought: {divs[mid]}')
		if e > divs[mid]:
			lo = mid+1
			mid = lo + (hi-lo)//2
		elif e < divs[mid]:
			hi = mid-1
			mid = lo + (hi-lo)//2
		else:
			return True 
	return False

def get_divs(n):
	divs = []
	cnt = 0
	ind = 0
	# check only till sqrt(i) because its pair will be 
	for i in range(1,int(math.sqrt(n))):
		if n%i == 0 and not in_divs(divs, n//i):
			divs.insert(ind,i)
			ind += 1
			if i != n//i:
				divs.insert(ind,n//i)
				cnt += 1
				#print(divs)
			cnt += 1
	return cnt

tot = 0
for i in range(1000,100000):
	tot = i*(i+1)/2
	n_div = get_divs(tot)
	if n_div > 500:	
		print(tot, ":", n_div) 
		break


