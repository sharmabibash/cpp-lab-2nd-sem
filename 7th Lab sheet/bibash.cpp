/*1. Write a program to create a class shape with functions to find the area of the shapes and display the names of the shapes and other essential components of the class. Create derived classes circle, rectangle, and trapezoid each having overriding functions area() and display(). Write a suitable program to illustrate virtual functions and virtual destructors.*/

/*#include <iostream>
using namespace std;

class Shape {
public:
    virtual void area() = 0;
    virtual void display() = 0;
    virtual ~Shape() {
        cout << "Base Shape Destructor\n";
    }
};

class Circle : public Shape {
    float radius;
public:
    Circle(float r) : radius(r) {}
    void area() override {
        cout << "Area of Circle: " << 3.14 * radius * radius << endl;
    }
    void display() override {
        cout << "Shape: Circle\n";
    }
    ~Circle() {
        cout << "Circle Destructor\n";
    }
};

class Rectangle : public Shape {
    float length, width;
public:
    Rectangle(float l, float w) : length(l), width(w) {}
    void area() override {
        cout << "Area of Rectangle: " << length * width << endl;
    }
    void display() override {
        cout << "Shape: Rectangle\n";
    }
    ~Rectangle() {
        cout << "Rectangle Destructor\n";
    }
};

class Trapezoid : public Shape {
    float a, b, h;
public:
    Trapezoid(float base1, float base2, float height) : a(base1), b(base2), h(height) {}
    void area() override {
        cout << "Area of Trapezoid: " << 0.5 * (a + b) * h << endl;
    }
    void display() override {
        cout << "Shape: Trapezoid\n";
    }
    ~Trapezoid() {
        cout << "Trapezoid Destructor\n";
    }
};

int main() {
    float r, l, w, base1, base2, height;

    cout << "Enter radius of circle: ";
    cin >> r;
    Shape* s = new Circle(r);
    s->display();
    s->area();
    delete s;

    cout << "\nEnter length and width of rectangle: ";
    cin >> l >> w;
    s = new Rectangle(l, w);
    s->display();
    s->area();
    delete s;

    cout << "\nEnter base1, base2, and height of trapezoid: ";
    cin >> base1 >> base2 >> height;
    s = new Trapezoid(base1, base2, height);
    s->display();
    s->area();
    delete s;

    return 0;
}
*/

/*2. Create a class Person and two derived classes Employee and Student, inherited from class Person. Now create a class Manager which is derived from two base classes Employee and Student. Show the use of the virtual base class.*/

/*#include <iostream>
using namespace std;
class Person
{
public:
    string name;
    int age;

    void getPersonInfo()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }

    void showPersonInfo()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Employee : virtual public Person
{
public:
    int empID;

    void getEmployeeInfo()
    {
        cout << "Enter Employee ID: ";
        cin >> empID;
    }

    void showEmployeeInfo()
    {
        cout << "Employee ID: " << empID << endl;
    }
};

class Student : virtual public Person
{
public:
    int rollNo;

    void getStudentInfo()
    {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
    }

    void showStudentInfo()
    {
        cout << "Roll Number: " << rollNo << endl;
    }
};

class Manager : public Employee, public Student
{
public:
    string department;

    void getManagerInfo()
    {
        getPersonInfo();
        getEmployeeInfo();
        getStudentInfo();
        cout << "Enter Department: ";
        cin >> department;
    }

    void showManagerInfo()
    {
        showPersonInfo();
        showEmployeeInfo();
        showStudentInfo();
        cout << "Department: " << department << endl;
    }
};

int main()
{
    Manager m;
    cout << "Enter Manager Details:\n";
    m.getManagerInfo();

    cout << "\nManager Information:\n";
    m.showManagerInfo();

    return 0;
}
*/

/*3. Write a program with an abstract class Student and create derive classes Engineering, Medicine and Science from base class Student. Create the objects of the derived classes and process them and access them using an array of pointers of type base class Student.*/
/*#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    virtual void getData() = 0;      
    virtual void displayData() = 0;  

    virtual ~Student() {} 
};

class Engineering : public Student {
public:
    string branch;

    void getData() override {
        cout << "Enter Engineering Student Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Branch: ";
        cin >> branch;
    }

    void displayData() override {
        cout << "Engineering Student: " << name << ", Age: " << age << ", Branch: " << branch << endl;
    }
};

class Medicine : public Student {
public:
    string specialization;

    void getData() override {
        cout << "Enter Medicine Student Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Specialization: ";
        cin >> specialization;
    }

    void displayData() override {
        cout << "Medicine Student: " << name << ", Age: " << age << ", Specialization: " << specialization << endl;
    }
};

class Science : public Student {
public:
    string subject;

    void getData() override {
        cout << "Enter Science Student Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Subject: ";
        cin >> subject;
    }

    void displayData() override {
        cout << "Science Student: " << name << ", Age: " << age << ", Subject: " << subject << endl;
    }
};

int main() {
    const int SIZE = 3;
    Student* students[SIZE];

    students[0] = new Engineering();
    students[1] = new Medicine();
    students[2] = new Science();

    cout << "\nEnter student details:\n";
    for (int i = 0; i < SIZE; i++) {
        students[i]->getData();
    }

    cout << "\nDisplaying student details:\n";
    for (int i = 0; i < SIZE; i++) {
        students[i]->displayData();
    }

    for (int i = 0; i < SIZE; i++) {
        delete students[i];
    }

    return 0;
}
*/

/*Create a polymorphic class Vehicle and create other derived classes Bus, Car, and Bike from Vehicle. Illustrate RTTI by the use of dynamic_cast and typeid operators in this program.*/

#include <iostream>
#include <typeinfo>
using namespace std;

class Vehicle {
public:
    virtual void show() {
        cout << "This is a Vehicle" << endl;
    }
    virtual ~Vehicle() {}
};

class Bus : public Vehicle {
public:
    void show() override {
        cout << "This is a Bus" << endl;
    }
};

class Car : public Vehicle {
public:
    void show() override {
        cout << "This is a Car" << endl;
    }
};

class Bike : public Vehicle {
public:
    void show() override {
        cout << "This is a Bike" << endl;
    }
};

int main() {
    Vehicle* v;

    Car c;
    v = &c;
    cout << "Type using typeid: " << typeid(*v).name() << endl;

    if (Bike* b = dynamic_cast<Bike*>(v)) {
        b->show();
    } else if (Car* car = dynamic_cast<Car*>(v)) {
        car->show();
    } else if (Bus* bus = dynamic_cast<Bus*>(v)) {
        bus->show();
    } else {
        cout << "Unknown Vehicle Type" << endl;
    }

    return 0;
}
