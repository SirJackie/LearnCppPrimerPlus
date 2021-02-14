#include <iostream>
using namespace std;

// You can't do this because of redefinition
//enum egg   { Small, Medium, Large, Jumbo };
//enum tshit { Small, Medium, Large, Jumbo };

// But you can do this!
enum class egg   { Small, Medium, Large, Jumbo };
enum class tshit { Small, Medium, Large, Jumbo };

// Which is the same as
namespace egg2 {
	enum egg2    { Small, Medium, Large, Jumbo };
}
namespace tshit2 {
	enum tshit2   { Small, Medium, Large, Jumbo };
}

int main() {
	egg e = egg::Small;
	tshit t = tshit::Small;
	cout << (int)e << (int)t << endl;

	egg2::egg2 e2 = egg2::Small;
	tshit2::tshit2 t2 = tshit2::Small;
	cout << (int)e2 << (int)t2 << endl;
}
