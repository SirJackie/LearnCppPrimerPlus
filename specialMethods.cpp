#include <iostream>
using namespace std;

class Number {
private:
	double value;
public:
	Number();                                     // 构造函数
	~Number();                                    // 析构函数
	Number(double value);                         // 转换构造函数
	operator double();                            // 转换析构函数
	Number(const Number& num);                    // 复制构造函数
	Number& operator =(const Number& num);        // 赋值运算符

	void show();
};

void Number::show() {
	cout << value << endl;
}

Number::Number() {
	value = 0.0;
	cout << "构造函数" << endl;
}
Number::~Number() {
	cout << "析构函数" << endl;
}
Number::Number(double value_) {
	this->value = value_;
	cout << "转换构造函数" << endl;
}
Number::operator double() {
	cout << "转换函数" << endl;
	return this->value;
}
Number::Number(const Number& num) {
	this->value = num.value;
	cout << "复制构造函数" << endl;
}
Number& Number::operator=(const Number& num) {
	Number newNum;
	newNum.value = num.value;
	cout << "赋值运算符" << endl;
	return newNum;
}

int main() {
	cout << "----------" << endl;

	// 构造函数
	Number num1;
	
	cout << "----------" << endl;

	// 转换构造函数
	Number num2(500.0);
	Number num3 = 1000.0;

	cout << "----------" << endl;

	// 转换函数
	double num3cpy = num3;
	cout << num3cpy << endl;

	cout << "----------" << endl;

	// 复制构造函数
	Number num4 = num3;

	cout << "----------" << endl;

	// 赋值运算符
	num4 = num2;

	cout << "----------" << endl;
}
