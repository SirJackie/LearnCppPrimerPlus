#include <iostream>
using namespace std;

int main()
{
	int buffer[10] = { 0,1,2,3,4,5,6,7,8,9 };

	cout << "----------" << endl;


	// Create a pointer to int
	int* p2i = &(buffer[0]);
	cout << *p2i << endl;

	p2i += 1;                   // VALID to modify the pointer
	cout << *p2i << endl;

	*p2i = 11111;               // VALID to modify the int
	cout << *p2i << endl;

	cout << "----------" << endl;


	// Create a pointer to const int
	const int* p2ci = &(buffer[0]);
	cout << *p2ci << endl;

	p2ci += 1;                  // VALID to modify the pointer
	cout << *p2ci << endl;

	//*p2ci = 111;              // ERROR!!! INVALID to modify the const int
	//cout << *p2ci << endl;

	cout << "----------" << endl;


	// Create a const pointer to int
	int* const cp2i = &(buffer[0]);
	cout << *cp2i << endl;
	
	//cp2i += 1;                // ERROR!!! INVALID to modify the const pointer
	//cout << *cp2i << endl;

	*cp2i = 12345;              // VALID to modify the int
	cout << *cp2i << endl;

	cout << "----------" << endl;


	// Create a const pointer to const int
	const int* const cp2ci = &(buffer[0]);
	cout << *cp2ci << endl;

	//cp2ci += 1;               // ERROR!!! INVALID to modify the const pointer
	cout << *cp2ci << endl;

	//*cp2ci = 1;               // ERROR!!! INVALID to modify the const int
	cout << *cp2ci << endl;

	cout << "----------" << endl;


	return 0;
}
