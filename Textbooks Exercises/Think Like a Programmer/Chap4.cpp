/*
 *	Spraul - Think Like a Programmer
 *		
 *		Learning about dynamic memory allocation
 *		Heap (dynamic) vs Stack (static)
 *		When to use pointers
 *
 *		Here we use null (ASCII Code: \0) terminated strings and associated methods
 */
#include <iostream>

typedef char * arrayString;	// typedef appears to auto declare the type in later code
							// thus, all future arrayString types are actually char*

// returns character at given index
char charAt(arrayString s, int position)	{ return s[position]; }

// pass by reference so that sideeffects will be persistent
void append(arrayString & s, char c)
{
	// determine string s's original length
	int orig_len = 0;
	while(s[orig_len] != 0) { orig_len++; }	// increment orig_len until null char
	
	// create new string
	arrayString new_s = new char[orig_len + 2];	// +2 for char c to append and null char
	for(int i = 0; i < orig_len; i++)	{ new_s[i] = s[i]; }	//copy orig str to new one
	new_s[orig_len] = c; 		// append char c to end
	new_s[orig_len +1 ] = 0; 	// append null char to end
	delete[] s;					// deallocate orig array memory
	s = new_s;					// set pointer s to new_s
}

int main()
{
	// create test string
	arrayString s = new char[5];
	s[0] = 't';
	s[1] = 'e';
	s[2] = 's';
	s[3] = 't';
	s[4] = 0;
	// print orig
	std::cout << s << std::endl;
	// append !
	append(s, '!');
	// print new
	std::cout << s << std::endl;
	
	return 0;
}


