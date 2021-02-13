#include <iostream>
using namespace std;

template <class T>

void swap(T a, T b) {
	T temp = a;
	a = b;
	b = temp;
}

int main() {
	int a = 0; b = 1;
	swap(a, b);
}

//int main() {
//
//	cout << "----------" << endl;
//
//	float fa = 1.0f, fb = 2.0f;
//	double da = 1.0, db = 2.0;
//	int ia = 1, ib = 2;
//
//	cout << "fa: " << fa << "; " << "fb:" << fb << endl;
//	cout << "da: " << da << "; " << "db:" << db << endl;
//	cout << "ia: " << ia << "; " << "ib:" << ib << endl;
//
//	cout << "----------" << endl;
//
//	swap(fa, fb);
//	swap(da, db);
//	swap(ia, ib);
//
//	cout << "fa: " << fa << "; " << "fb:" << fb << endl;
//	cout << "da: " << da << "; " << "db:" << db << endl;
//	cout << "ia: " << ia << "; " << "ib:" << ib << endl;
//
//	cout << "----------" << endl;
//
//	return 0;
//}
