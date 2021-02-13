#include <iostream>
#include <Windows.h>
#include <string.h>
#include <io.h>
using namespace std;

inline bool checkIfFileExist(const char* name) {
	return (access(name, 0) != -1);
}

void runFileWithVS(const char* filename) {
	char buffer[100] = "devenv ";
	strcat(buffer, filename);
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
	char* filename;

	if (argc != 2) {
		cout << "INVALID ARGUMENTS, TERMINATED." << endl;
		return 0;
	}
	else {
		filename = argv[1];
	}

	if (checkIfFileExist(filename) == true) {
		cout << "Loading.." << endl;
		runFileWithVS(filename);
	}
	else {
		cout << "File Not Exist." << endl;

		cout << "Creating File..." << endl;
		createNewFile(filename);

		cout << "Loading.." << endl;
		runFileWithVS(filename);
	}
	
}
