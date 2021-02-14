#include <iostream>
using namespace std;

enum shit {Soft, Hard};

void CheckShit(shit& s){
	if (s == Soft) {
		cout << "Soft Shit Haha." << endl;
	}
	else if (s == Hard) {
		cout << "Hard Shit Blayt" << endl;
	}
}

int main() {
	shit s1 = Soft;
	shit s2 = Hard;

	CheckShit(s1);
	CheckShit(s2);
}
