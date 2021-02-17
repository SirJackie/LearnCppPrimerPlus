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
	String();                                // 初始化构造函数
	String(const char* str);                 // 普通构造函数(转换构造函数)
	~String();                               // 析构函数
	String(const String& str);               // 复制构造函数
	String& operator=(const String& str);    // 赋值运算符
	operator char* ();                        // 转换函数

	friend ostream& operator<<(ostream& os, const String& str);   // 支持cout的重载
	char& operator[](int i);                                      // 支持中括号访问的重载
	int len();                                                    // 长度获取函数
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
	String str0;                    // 初始化构造函数

	cout << "----------" << endl;

	String str1 = "Hello Class!";   // 普通构造函数

	cout << "----------" << endl;

	String str2 = str1;             // 复制构造函数

	cout << "----------" << endl;

	String str3;                    // 赋值运算符
	str3 = str1;

	cout << "----------" << endl;

	// 尝试输出
	cout << str1 << endl;
	char* str1cpy = str1;
	cout << str1cpy << endl;

	for (int i = 0; i < str1.len(); i++) {
		cout << "str1[" << i << "]" << " = " << str1[i] << endl;
	}

	cout << "----------" << endl;
}