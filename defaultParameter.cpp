#include <iostream>
using namespace std;

void showStr(char* str, int length = 1) {
	for (int i = 0; i < length; i++) {
		cout.put(str[i]);
	}
	cout << endl;
}

int main() {

	cout << "----------" << endl;

	// A simple demostration of dafault parameter
	char str1[] = "Hello mother fucker!";
	showStr(str1, sizeof(str1));
	showStr(str1);

	cout << "----------" << endl;


	return 0;
}
