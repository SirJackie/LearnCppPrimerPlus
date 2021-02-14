#include <iostream>
#include <string.h>
using namespace std;

class Student {
private:
	float m_dickSize;    // Not Available to acccess and change
public:
	char  m_name[100];   // Available to access and change
	int   m_age;         // Available to access but not available to change

	Student(const char* name, const int age, const float dickSize);
	~Student();
	void show();
	void showConstly() const;
	Student& longestDick(Student& sb);
};

Student::Student(const char* name, const int age, const float dickSize) {
	strcpy(m_name, name);
	m_age = age;
	m_dickSize = dickSize;
}

Student::~Student() {
	cout << "Student " << this->m_name << " has been destroyed." << endl;
}

void Student::show() {
	cout << "Name: " << this->m_name << endl;
	cout << "Age: " << this->m_age << endl;
	cout << "DickSize: " << this->m_dickSize << endl;
}

void Student::showConstly() const {
	cout << "Name: " << this->m_name << endl;
	cout << "Age: " << this->m_age << endl;
	cout << "DickSize: " << this->m_dickSize << endl;
}

Student& Student::longestDick(Student& sb) {
	Student& sa = *this;
	if (sa.m_dickSize > sb.m_dickSize) {
		return sa;
	}
	else {
		return sb;
	}
}

int main() {
	{
		Student xiaoming("XiaoMing", 10, 7.0f);                // Create a class
		xiaoming.show();

		Student xiaowang("XiaoWang", 10, 8.0f);                // Create another class
		xiaowang.show();

		Student xiaozhang = Student("XiaoZhang", 10, 6.0f);    // Create a class using another grammar
		xiaozhang.show();

		Student alice = { "Alice", 10, 5.0f };                 // Create a class using list initialize grammar
		alice.show();
	}

	cout << "----------" << endl;

	{
		const Student a("John", 10, 10.0f);
		//a.show();                           // ERROR!!! Invalid to use a not-const method for a const object
		a.showConstly();                      // Pass.    Valid   to use a const     method for a const object
	}

	cout << "----------" << endl;

	{
		Student a("Ahha", 10, 9.0f);
		Student b("Boba", 11, 10.0f);

		a.longestDick(b).show();
	}
	
	cout << "----------" << endl;
}
