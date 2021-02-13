#include <iostream>
#include <Windows.h>
#include <string.h>
using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "INVALID ARGUMENTS, TERMINATED." << endl;
	}
	else {
		char buffer[100] = "devenv ";
		strcat(buffer, argv[1]);
		cout <<"Running Command: "<< buffer << endl;
		system(buffer);
	}
}
