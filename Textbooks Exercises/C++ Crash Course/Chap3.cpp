/*
 * Exercises & Misc for Chap. 3 of Lospinoso - C++ Crash Course
 */
#include <iostream>

struct Animal
{
	std::string sound;
};

struct Rock
{
	char roll[5];	// must be +1 longer than intended size to fit NULL
};

void printAni(Animal* ani_ptr)
{
	printf("Pigs definitely go %s\n", ani_ptr->sound.c_str());
}

void printRock(Rock* rock_ptr, size_t n_rocks)
{
	for(size_t i = 0; i < n_rocks; i++)
		printf("Hi, I'm %s. I'm a lovely rock.\n", rock_ptr[i].roll);
} 

void changeRock(Rock& rock)
{
	rock.roll[0] = 'T';
	rock.roll[1] = 'u';
	rock.roll[2] = 'f';
	rock.roll[3] = 'f';
}

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
	
	Animal pigs[] = { "oink!", "Oink!", "OINK!" };
	printAni(pigs);	// highlights array decaying to a point to arrays first element
			//  when treated as pointer

	Rock rocks[] = { "Gold", "Mica", "Iron" };
	printRock(rocks, sizeof(rocks)/sizeof(Rock));
	Rock* third_rock_1 = &rocks[2];	// two different ways of obtaining a reference to the third element in an array
	Rock* third_rock_2 = rocks + 2;

	printf("third_rock_add: %p\n", third_rock_1);
	printf("third_rock_add: %p\n", third_rock_1);

	printf("third_rock: %s\n", third_rock_1->roll);
	changeRock(rocks[2]);	// pass by reference
	printf("third_rock: %s\n", third_rock_1->roll);

	return 0;
}

