#include <iostream>

void print(int* first, int* limit) {
  	while (first != limit-1) {
    	std::cout << *first << ' ';
    	first++;
	}
	std::cout << *first << std::endl;
}

// Returns a pointer to the first object in [first, limit) whose value is equal to value. Returns limit if no such object is found.
int* find(int* first, int* limit, int value) {
	while (first != limit) {
		if (*first == value) return first;
		first++;
	}
	return limit;

}

// Returns true if there exists an object in [first, limit) whose value is equal to value and false otherwise.
bool in(int* first, int* limit, int value) {
	while (first != limit) {
		if (*first == value) {
			return true;
		}
		first++;
	}
	return false;
}

// The number of objects in [first, limit) whose value is equal to value.
int count(int* first, int* limit, int value) {
	int i = 0;
	while (first != limit) {
		if (*first == value) {
			i++;
		}
		first++;
	}
	return i;
}

// Returns true if the ranges [first1, limit1) and [first2, limit2) denote equal sequences of integers and false otherwise. 
// Two ranges denote equal sequences when each element of one range is equal to its corresponding element in the other.
bool equal(int* first1, int* limit1, int* first2, int* limit2) {
	while (first1 != limit1 && first2 != limit2) {
		if (first1 != first2) return false;
		first1++;
		first2++;
	}
	return true;
}

// Returns the lesser value of a and b.
int mininum(int a, int b) {
	return (a < b) ? a : b;
}

// Returns a pointer to the object in the range [first, limit) with the least value. Returns limit if the range is empty.
int* mininum(int* first, int* limit) {
	int min = *first;
	while (*first != *limit) {
		min = mininum(*first, min);
		first++;
	}
	return &min;
}

// Returns the greater value of a and b.
int maximum(int a, int b) {
	return (a > b) ? a : b;
}

// Returns a pointer to the object in the range [first, limit) with the greatest value. Returns limit if the range is empty.
int* maximum(int* first, int* limit) {
	int max = *first;
	while (*first != *limit) {
		max = maximum(*first, max);
		first++;
	}
	return &max;
}

// Performs a three-way lexicographical comparison of the values in the ranges [first1, limit1) and [first2, limit2) and returns
// -1 if the range [first1, limit1) is lexicographically less than the elements in the range [first2, limit2),
// 1 if the converse is true (the second range is lexcicographically less than the first), and
// 0 if the ranges are equivalent.

int compare(int* first1, int* limit1, int* first2, int* last2) {

	// checks if either are empty
	if (first1 == limit1 && first2 == last2) return 0;
	if (first1 == limit1) return -1;
	if (first2 == last2) return 1;

	while (first1 != limit1 || first2 != last2) {
		
		// checks if either are shorter
		if (first1 == limit1 && first2 != last2) return -1;
		if (first2 == last2 && first1 != limit1) return 1;

		// compares the values
    	if (*first1 < *first2) return -1; // second is bigger
    	else if (*first1 > *first2) return 1; // first is bigger
   		
   		first1++;
   		first2++;
	}
	return 0; // both are equal
}

void copy(int* first1, int* limit1, int* first2, int* limit2) {
	int i = 0;
	while (first1 != limit1) {
		first1[i] = first2[i];
		first1++;
		first2++;
	}
}

void fill(int* first, int* limit, int value) {
	int i = 0;
	while (first != limit) {
		first[i] = value;
		first++;
	}
}
int main(int argc, char** argv) {

	int a[] = {1, 2, 3, 4, 5};
	int* first = a;      // Points to the first object in a
	int* limit = a + 5;  // Points past the end of a

	// print test
	print(first, limit); // Prints '1 2 3 4 5 '

	// find test
	std::cout << "find first value of 2 in {1, 2, 3, 4, 5}: " << *find(first, limit, 2) << std::endl;

	// in test
	std::cout << "is 2 in {1, 2, 3, 4, 5}? " << std::boolalpha << in(first, limit, 2) << std::endl;

	// count test
	std::cout << "how many 2s are in {1, 2, 3, 4, 5}? " << count(first, limit, 2) << std::endl;

	// equal test
	std::cout << "is {1, 2, 3, 4, 5} equal to {1, 2, 3, 4, 5}? " << equal(first, limit, first, limit) << std::endl;
	
	int b[] = {1, 2, 3};
	int* first2 = b;
	int* limit2 = b + 3;

	std::cout << "is {1, 2, 3, 4, 5} equal to {1, 2, 3}? " << equal(first, limit, first2, limit2) << std::endl;

	// mininum test
	std::cout << "min of (1, 2): " << mininum(1, 2) << std::endl;
	std::cout << "min of {1, 2, 3, 4, 5} is " << *mininum(first, limit) << std::endl;

	// maximum test
	std::cout << "max of (1, 2): " << maximum(1, 2) << std::endl;
	std::cout << "max of {1, 2, 3, 4, 5} is " << *maximum(first, limit) << std::endl;

	// comparison test
	std::cout << "should say 1 since {1, 2, 3} is less than {1, 2, 3, 4, 5}:  " << compare(first, limit, first2, limit2) << std::endl;
	std::cout << "should say 0 since {1, 2, 3, 4, 5} is equal to {1, 2, 3, 4, 5}:  " << compare(first, limit, first, limit) << std::endl;
	std::cout << "should say -1 since {1, 2, 3, 4, 5} is greater than {1, 2, 3}:  " << compare(first2, limit2, first, limit) << std::endl;

	// copy test
	int c[] = {1, 2, 3, 4, 6};
	int* first3 = c;
	int* limit3 = c + 5;
	copy(first, limit, first3, limit3);

	std::cout << "should print values {1, 2, 3, 4, 6}: ";
	print(first, limit);

	// fill test
	fill(first, limit, 3);
	std::cout << "should print {3, 3, 3, 3, 3}: ";
	print(first, limit);

	return 0;
}