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
	ptr = new char[length];
	strcpy(ptr, str);
	strCounter += 1;
	cout << "-----" << "普通构造函数 executing. " << "内容: " << ptr << "; strCounter: " << strCounter << "-----" << endl;
}

String::~String() {
	strCounter -= 1;
	cout << "-----" << "析构函数 executing. " << "内容: " << ptr << "; strCounter: " << strCounter << "-----" << endl;
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
	cout << "-----" << "复制构造函数 executing. " << "内容: " << ptr << "; strCounter: " << strCounter << "-----" << endl;
}

String& String::operator=(const String& str) {
	String self = *this;

	self.length = str.length;
	self.ptr = new char[self.length];
	strcpy(self.ptr, str.ptr);

	strCounter += 1;
	cout << "-----" << "赋值运算符 executing. " << "内容: " << ptr << "; strCounter: " << strCounter << "-----" << endl;
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