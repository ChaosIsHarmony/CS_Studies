/*
 * Exercises & Misc for Chap. 2 of Lospinoso - C++ Crash Course
 */

#include <iostream>

template<typename T>
void print(T t) { std::cout << t << std::endl; }

int main()
{
	// pg 103 tells how to find the size of an array
	short array[] = { 104, 103, 102, 101, 100, 99 };
	size_t n_elem_in_array = sizeof(array) / sizeof(short);
	
	print("Old Fashioned way: " + n_elem_in_array);
	
	// pg 104 speaks of string literals just being char arrays
	char english[] = "A book holds a house of gold.";
	char16_t chinese[] = u"\u4e66\u4e2d\u81ea\u6709\u9ec4\u91d1\u5c4b";
	
	printf("%s", english);
	printf("%s", chinese);
	
	return 0;
}