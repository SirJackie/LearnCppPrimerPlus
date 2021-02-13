#include <iostream>
#include <Windows.h>
#include <string.h>
#include <io.h>
using namespace std;

inline bool checkIfFileExist(const char* name) {
	return (access(name, 0) != -1);
}

void compileFileWithCL(const char* filename) {
	char buffer[100] = "cl ";
	strcat(buffer, filename);
	//cout << "Running Command: " << buffer << endl;
	system(buffer);
}

void runFile(const char* filename) {
	char buffer[100] = "";
	strcat(buffer, filename);

	int bufferEnd;

	for (int i = 0; ; i++) {
		if (buffer[i] == '\0') {
			bufferEnd = i;
			break;
		}
	}

	buffer[bufferEnd - 1] = 'e';
	buffer[bufferEnd - 2] = 'x';
	buffer[bufferEnd - 3] = 'e';

	//cout << "Running Command: " << buffer << endl;
	system(buffer);
}

void createNewFile(const char* filename) {
	char buffer[100] = "type nul > ";
	strcat(buffer, filename);
	//cout << "Running Command: " << buffer << endl;
	system(buffer);
}



int main(int argc, char* argv[]) {

	cout << argv[0] << endl;
	cout << argv[1] << endl;

	if (argc == 1) {
		cout << "C++ Source File Runner by Sir Jackie" << endl;
		cout << "--------------------------------------" << endl;
		cout << "Designed for compile and run a c++ file in cmd easily." << endl;
	}

	else if (argc == 2) {
		char* filename = argv[1];
		if (checkIfFileExist(filename) == true) {
			cout << "Loading.." << endl;
			compileFileWithCL(filename);
			system("clear");
			runFile(filename);
		}
		else {
			cout << "File Not Exist." << endl;
			return 0;
		}
	}

	else {
		cout << "INVALID ARGUMENTS, TERMINATED." << endl;
		return 0;
	}
}
