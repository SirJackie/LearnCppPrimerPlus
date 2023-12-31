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

	if (argc == 1) {
		cout << "Visual Studio Caller by Sir Jackie" << endl;
		cout << "--------------------------------------" << endl;
		cout << "Designed for open a c++ file in cmd with Visual Studio" << endl << "and not cause a blocking" << endl;
	}

	else if (argc == 2) {
		char* filename = argv[1];
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

	else {
		cout << "INVALID ARGUMENTS, TERMINATED." << endl;
		return 0;
	}
}
