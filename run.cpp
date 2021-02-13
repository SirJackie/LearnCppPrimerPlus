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

char* getExeName(char* filename) {
	char* buffer = new char[100];
	strcpy(buffer, filename);

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

	return buffer;
}

void runExe(const char* exename) {
	//cout << "Running Command: " << buffer << endl;
	system(exename);
}

void deleteExe(const char* exename) {
	char buffer[100] = "rm ";
	strcat(buffer, exename);
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

	if (argc == 1) {
		cout << "C++ Source File Runner by Sir Jackie" << endl;
		cout << "--------------------------------------" << endl;
		cout << "Designed for compile and run a c++ file in cmd easily." << endl;
	}

	else if (argc == 2) {
		char* filename = argv[1];
		char* exename = getExeName(filename);

		if (checkIfFileExist(filename) == true) {

			if (checkIfFileExist(exename) == true) {
				deleteExe(exename);
			}

			cout << "Loading.." << endl;
			compileFileWithCL(filename);

			if (checkIfFileExist(exename) == true) {
				system("clear");
				runExe(exename);
			}

			else {
				cout << "Compile Failed." << endl;
			}
		}

		else {
			cout << "File Not Exist." << endl;
		}

		delete[] exename;
	}

	else {
		cout << "INVALID ARGUMENTS, TERMINATED." << endl;
		return 0;
	}
}
