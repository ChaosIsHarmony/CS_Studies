/*
 * Exercises & Misc for Chap. 3 of Lospinoso - C++ Crash Course
 */
#include <iostream>

struct Animal
{
	std::string sound;
};

int main()
{
	int sample_int = {};	// sets to zero
	printf("sample_int: %d\n", sample_int);

	int* sample_int_add = &sample_int;
	printf("&sample_int: %p\n", sample_int_add);
	
	*sample_int_add = 42;	// dereference pointer address to access memory directly
				// then change value there to 42	
	printf("sample_int new val: %d\n", *sample_int_add);
	printf("&sample_int: %p\n", sample_int_add);

	Animal pig;
	Animal* pig_ptr = &pig;
	pig_ptr->sound = "oink!";	// ptr->member is equivalent to (*ptr).member
	printf("Pigs go %s\n", (*pig_ptr).sound.c_str());
	printf("Pigs go %s\n", pig_ptr->sound.c_str());
	printf("I said, pigs go %s\n", pig.sound.c_str());
	

	return 0;
}

