#include <iostream>
using namespace std;

class Number {
private:
	double value;
public:
	Number();                                     // ���캯��
	~Number();                                    // ��������
	Number(double value);                         // ת�����캯��
	operator double();                            // ת����������
	Number(const Number& num);                    // ���ƹ��캯��
	Number& operator =(const Number& num);        // ��ֵ�����

	void show();
};

void Number::show() {
	cout << value << endl;
}

Number::Number() {
	value = 0.0;
	cout << "���캯��" << endl;
}
Number::~Number() {
	cout << "��������" << endl;
}
Number::Number(double value_) {
	this->value = value_;
	cout << "ת�����캯��" << endl;
}
Number::operator double() {
	cout << "ת������" << endl;
	return this->value;
}
Number::Number(const Number& num) {
	this->value = num.value;
	cout << "���ƹ��캯��" << endl;
}
Number& Number::operator=(const Number& num) {
	Number newNum;
	newNum.value = num.value;
	cout << "��ֵ�����" << endl;
	return newNum;
}

int main() {
	cout << "----------" << endl;

	// ���캯��
	Number num1;
	
	cout << "----------" << endl;

	// ת�����캯��
	Number num2(500.0);
	Number num3 = 1000.0;

	cout << "----------" << endl;

	// ת������
	double num3cpy = num3;
	cout << num3cpy << endl;

	cout << "----------" << endl;

	// ���ƹ��캯��
	Number num4 = num3;

	cout << "----------" << endl;

	// ��ֵ�����
	num4 = num2;

	cout << "----------" << endl;
}
