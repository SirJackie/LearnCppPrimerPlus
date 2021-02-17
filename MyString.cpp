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
	cout << "-----" << "初始化构造函数 executing. " << "内容: " << ptr << "; strCounter: " << strCounter << "-----" << endl;
}

String::String(const char* str) {
	length = strlen(str);
	ptr = new char[length + 1];
	strcpy(ptr, str);
	strCounter += 1;
	cout << "-----" << "普通构造函数 executing. " << "内容: " << ptr << "; strCounter: " << strCounter << "-----" << endl;
}

String::~String() {
	cout << "-----" << "析构函数 executing. " << "内容: " << ptr;
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
	cout << "-----" << "复制构造函数 executing. " << "内容: " << ptr << "; strCounter: " << strCounter << "-----" << endl;
}

String& String::operator=(const String& str) {
	delete[] this->ptr;

	this->length = str.length;
	this->ptr = new char[this->length + 1];
	strcpy(this->ptr, str.ptr);

	//strCounter += 1; // Important! 赋值运算符没有生成新对象！
	cout << "-----" << "赋值运算符 executing. " << "内容: " << ptr << "; strCounter: " << strCounter << "-----" << endl;

	return *this;
}

int main() {
	String str0;                    // 初始化构造函数

	cout << "----------" << endl;

	String str1 = "Hello Class!";   // 普通构造函数

	cout << "----------" << endl;

	String str2 = str1;             // 复制构造函数

	cout << "----------" << endl;

	String str3;                    // 赋值运算符
	str3 = str1;

	cout << "----------" << endl;
}