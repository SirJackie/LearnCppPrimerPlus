#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
using namespace std;

class String {
private:
	char* ptr;
	int length;
	static int strCounter;
public:
	String();                                // ��ʼ�����캯��
	String(const char* str);                 // ��ͨ���캯��(ת�����캯��)
	~String();                               // ��������
	String(const String& str);               // ���ƹ��캯��
	String& operator=(const String& str);    // ��ֵ�����
	operator char* ();                       // ת������

	friend ostream& operator<<(ostream& os, const String& str);   // ֧��cout������
	char& operator[](int i);                                      // ֧�������ŷ��ʵ�����
	int len();                                                    // ���Ȼ�ȡ����
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
	ptr = new char[length + 1];
	strcpy(ptr, str);
	strCounter += 1;
	cout << "-----" << "��ͨ���캯�� executing. " << "����: " << ptr << "; strCounter: " << strCounter << "-----" << endl;
}

String::~String() {
	cout << "-----" << "�������� executing. " << "����: " << ptr;
	delete[] ptr;
	ptr = nullptr;
	length = 0;

	strCounter -= 1;
	cout << "; strCounter: " << strCounter << "-----" << endl;
}

String::String(const String& str) {
	this->length = str.length;
	this->ptr = new char[this->length + 1];
	strcpy(this->ptr, str.ptr);

	strCounter += 1;
	cout << "-----" << "���ƹ��캯�� executing. " << "����: " << ptr << "; strCounter: " << strCounter << "-----" << endl;
}

String& String::operator=(const String& str) {
	delete[] this->ptr;

	this->length = str.length;
	this->ptr = new char[this->length + 1];
	strcpy(this->ptr, str.ptr);

	//strCounter += 1; // Important! ��ֵ�����û�������¶���
	cout << "-----" << "��ֵ����� executing. " << "����: " << ptr << "; strCounter: " << strCounter << "-----" << endl;

	return *this;
}

ostream& operator<<(ostream& os, const String& str) {
	os << str.ptr;
	return os;
}

String::operator char* () {
	char* newcharlist = new char[this->length + 1];
	strcpy(newcharlist, this->ptr);
	return newcharlist;
}

char& String::operator[](int i) {
	return (this->ptr)[i];
}

int String::len() {
	return length;
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

	// �������
	cout << str1 << endl;
	char* str1cpy = str1;
	cout << str1cpy << endl;

	for (int i = 0; i < str1.len(); i++) {
		cout << "str1[" << i << "]" << " = " << str1[i] << endl;
	}

	cout << "----------" << endl;
}