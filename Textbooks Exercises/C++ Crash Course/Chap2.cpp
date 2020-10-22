/*
 * Exercises & Misc for Chap. 2 of Lospinoso - C++ Crash Course
 */

#include <iostream>

template<typename T>
void print(T t) { std::cout << t << std::endl; }

enum class Reindeers { RUDOLPH, VIXEN, DANCER, PRANCER, COMET, BLITZEN, CUPID, DONNER, DASHER };

struct Acct
{
	int acct_num;
	std::string users[2];
	double balance;
	bool is_delinquent;
};

int main()
{
	// pg 103 tells how to find the size of an array
	short array[] = { 104, 103, 102, 101, 100, 99 };
	size_t n_elem_in_array = sizeof(array) / sizeof(short);
	
	print("Old Fashioned way: " + std::to_string(n_elem_in_array));
	
	// pg 104 speaks of string literals just being char arrays
	char english[] = "A book holds a house of gold.";
	char16_t chinese[] = u"\u4e66\u4e2d\u81ea\u6709\u9ec4\u91d1\u5c4b";
	
	printf("%s\n", english);
	printf("%s\n", chinese);
	
	// pg 107 enum and enum class are detailed
	// 	we are warned to not use enum as it is mostly there for backward compatibility w/ C
	Reindeers best_reindeer = Reindeers::BLITZEN;
	
	// pg 108 talks about switch statements
	//	syntax is slightly different from Java switch statements
	switch (best_reindeer)
	{
		case (Reindeers::RUDOLPH):
		{ print("RUDOLPH"); } break;
		case (Reindeers::BLITZEN):
		{ print("BLITZEN"); } break;
		default:
		{ print("INVALID INPUT"); }
	}
	
	// pg 110 mentions structs
	Acct acct;
	acct.acct_num = 1000;
	acct.users[0] = "Bobo";
	acct.users[1] = "";
	acct.balance = 0.05;
	acct.is_delinquent = true;
	
	
	return 0;
}