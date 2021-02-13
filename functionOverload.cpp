#include <iostream>
using namespace std;

void myPrint() {
	cout << "Default Printing String. Learn C++!" << endl;
}

void myPrint(char* str) {
	for (int i = 0; ; i++) {
		if (str[i] == '\0') {
			cout << endl;
			return;
		}
		else {
			cout << str[i];
		}
	}
}

void myPrint(char* str, int length) {
	for (int i = 0; i < length; i++) {
		cout << str[i];
	}
	cout << endl;
}

int main() {
	cout << "----------" << endl;

	// Try Function Overload
	char str[100] = "Hello mother fucker!";
	myPrint();
	myPrint(str);
	myPrint(str, 10);

	cout << "----------" << endl;

	return 0;
}
