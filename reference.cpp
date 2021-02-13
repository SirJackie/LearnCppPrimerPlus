#include <iostream>
using namespace std;

void ptrSwap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void refSwap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

struct Student {
	char name[40];
	int age;
};

Student stu1 = { "Alice", 10 };
Student stu2 = { "John", 12 };

void ptrShowStu(Student* stu) {
	cout << stu->name << ", " << stu->age << endl;
}

void refShowStu(Student& stu) {
	cout << stu.name << ", " << stu.age << endl;
}

int strangeInt;

int& strangeRef() {
	return strangeInt;
}


int main() {

	cout << "----------" << endl;

	// Create a reference
	int rats = 10;
	int& rodents = rats;
	cout << rats << ", " << rodents << endl;

	rodents = 20;
	cout << rats << endl;

	rats = 30;
	cout << rodents << endl;

	cout << "----------" << endl;


	// Swap numbers
	int a = 11111;
	int b = 22222;
	cout << "a: " << a << "; " << "b:" << b << endl;

	ptrSwap(&a, &b);
	cout << "a: " << a << "; " << "b:" << b << endl;

	refSwap(a, b);
	cout << "a: " << a << "; " << "b:" << b << endl;

	cout << "----------" << endl;


	// Use reference for a structure as an argument
	ptrShowStu(&stu1);
	refShowStu(stu2);

	cout << "----------" << endl;


	// Use a function which return a reference as a left value
	strangeRef() = 10;
	cout << strangeRef() << endl;
	strangeInt = 12;
	cout << strangeRef() << endl;
	strangeRef() = 14;
	cout << strangeInt << endl;

	cout << "----------" << endl;


	return 0;
}
