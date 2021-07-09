#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

typedef int i32;
typedef float f32;


class Person{
public:
    string firstName;
    string lastName;
    i32 age;
    Person(string fn, string ln, i32 ag) : firstName(fn), lastName(ln), age(ag) {}
    virtual void ShowInfo(){
        cout << firstName << " " << lastName << ", " << age << " years old." << endl;
    }
};


class Student : public Person{
public:
    i32 grade;
    Student(string fn, string ln, i32 ag, i32 gd) : Person(fn, ln, ag), grade(gd) {}
    virtual void ShowInfo(){
        Person::ShowInfo();
        cout << "The Grade of this student is: " << grade << endl;
    }
};


int main(){
    Person ps("Elon", "Musk", 50);
    ps.ShowInfo();

    Student st("Jackie", "Lin", 16, 9);
    st.ShowInfo();
}