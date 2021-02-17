#include <iostream>
#include <string.h>
using namespace std;

class String {
private:
	char* ptr;
	int length;
	static int strCounter;
public:
	String();
	String(const char* str);
	~String();
	String(const String& str);
	String& operator=(const String& str);
	//friend operator<<(const ostream os, const String& str);
};

int String::strCounter = 0;

String::String() {
	ptr = new char[1];
	ptr[0] = '\0';
	length = 0;
	strCounter += 1;
	cout << "-----" << "��ʼ�����캯�� executing. " << "����: " << ptr << "; strCounter: " << strCounter << "-----" << endl;
}

String::String(const char* str) {
	length = strlen(str);
	ptr = new char[length];
	strcpy(ptr, str);
	strCounter += 1;
	cout << "-----" << "��ͨ���캯�� executing. " << "����: " << ptr << "; strCounter: " << strCounter << "-----" << endl;
}

String::~String() {
	strCounter -= 1;
	cout << "-----" << "�������� executing. " << "����: " << ptr << "; strCounter: " << strCounter << "-----" << endl;
	delete[] ptr;
	ptr = nullptr;
	length = 0;
}

String::String(const String& str) {
	String& self = *this;

	self.length = str.length;
	self.ptr = new char[self.length];
	strcpy(self.ptr, str.ptr);

	strCounter += 1;
	cout << "-----" << "���ƹ��캯�� executing. " << "����: " << ptr << "; strCounter: " << strCounter << "-----" << endl;
}

String& String::operator=(const String& str) {
	String self = *this;

	self.length = str.length;
	self.ptr = new char[self.length];
	strcpy(self.ptr, str.ptr);

	strCounter += 1;
	cout << "-----" << "��ֵ����� executing. " << "����: " << ptr << "; strCounter: " << strCounter << "-----" << endl;
}

int main() {
	String str0;                    // ��ʼ�����캯��

	cout << "----------" << endl;

	String str1 = "Hello Class!";   // ��ͨ���캯��

	cout << "----------" << endl;

	String str2 = str1;             // ���ƹ��캯��

	cout << "----------" << endl;

	String str3;                    // ��ֵ�����
	str3 = str1;

	cout << "----------" << endl;
}