/* 1. Write a simple program that converts the temperature in Celsius scale to Fahrenheit scale and vice versa using the basic concept of class and object. Make separate classes for Celsius and Fahrenheit which will have the private members that hold the temperature value and make conversion functions in each class for conversion from one to another. For example, you need to have a function toFahrenheit() in class Celsius that converts to Fahrenheit scale and returns the value.*/

/*#include <iostream>
using namespace std;
class Cel
{
private:
    double temperature;

public:
    void input()
    {
        cout << "Enter Temperature in celcius : " << endl;
        cin >> temperature;
    }
    double convert_to_fah()
    {
        return (temperature * 9.0 / 5.0) + 32;
    }
    void display()
    {
        cout << temperature << " C = " << convert_to_fah() << " F" << endl;
    }
};
class Fah
{
    private:
    double temperature;
    public:
    void input()
    {
        cout << "Enter Temperature in Fahrenheit : " << endl;
        cin >> temperature;
    }
    double convert_to_cel()
    {
        return (temperature - 32) * 5.0 / 9.0;
    }
    void output()
    {
        cout << temperature << " F = " << convert_to_cel() << " C" << endl;
    }
};
int main()
{
    int choice;
    cout << "Enter your choice : " << endl;
    cout << "1. Convert Celsius to Fahrenheit\n";
    cout << "2. Convert Fahrenheit to Celsius\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;
    if (choice == 1)
    {
        Cel c;
        c.input();
        c.display();
    }
    else if (choice == 2)
    {
        Fah f;
        f.input();
        f.output();
    }else{
        cout<<"invalid choice !! "<<endl;
    }
}*/

/*2. Assume that you want to check whether the number is prime or not. Write a program that asks for numbers repeatedly. When it finishes checking a number the program asks if the user wants to do another calculation. The response can be 'y' or 'n'. Don't forget to use the object-oriented concept.*/

/*#include <iostream>
using namespace std;

class checkNum
{
private:
    int num;

public:
    void input()
    {
        cout << "Enter any number :" << endl;
        cin >> num;
    }
    bool prime()
    {
        if (num <= 1)
        {
            return false;
            for (int i = 2; i * i <= num; i++)
            {
                if (num % i == 0)

                    return false;
            }
            return true;
        }
    }

    void display()
    {
        if (prime())
            cout << num << " prime number." << endl;
        else
            cout << num << " not a prime number." << endl;
    }
};
int main()
{
    char choice;
    do {
        checkNum check;
        check.input();
        check.display();
        cout << "Do you want to check another number? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
     cout << "Exit" << endl;
    return 0;
}
*/

/*3. Create a class called carpark that has int data member for car id, int data member for charge/hour, and float data member for the parked time. Make functions to set data members and show the charges and parked hours of the corresponding car id. Make functions for setting and showing the data members. Member function should be called from other functions.*/

/*#include<iostream>
using namespace std;
class carpark{
    private:
    int carID;
    int charge_hour;
    float parked_time;

    public:
    void setData(){
         cout << "Enter Car ID: ";
        cin >> carID;
        cout << "Enter charge per hour: ";
        cin >> charge_hour;
        cout << "Enter parked time in hours: ";
        cin >> parked_time;
    }
    int calculate() {
        return static_cast<int>(parked_time * charge_hour);
    }
    void showData() {
        cout << "\n--- Car Details ---" << endl;
        cout << "Car ID: " << carID << endl;
        cout << "Parked Hours: " << charge_hour << " hours" << endl;
        cout << "Total Charge: Rs. " << calculate() << endl;
    }
};
int main(){
    carpark car;
    car.setData();
    car.showData();
    return 0;
}*/

/*4. Write a program with classes to represent a circle, rectangle, and triangle. Each class should have data members to represent the actual objects and member functions to read and display objects, find perimeter and area of the objects, and other useful functions. Use the classes to create objects in your program.*/

/*#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

class Circle {
    double r;
public:
    void read() { cout << "\nEnter radius of the circle: "; cin >> r; }
    double area() { return M_PI * r * r; }
    double peri() { return 2 * M_PI * r; }
    void show() {
        cout << "\nCircle : Radius: " << r << ", Area: " << area()
             << ", Circumference: " << peri() << endl;
    }
};

class Rectangle {
    double l, b;
public:
    void read() { cout << "\nEnter length and breadth of the rectangle: "; cin >> l >> b; }
    double area() { return l * b; }
    double peri() { return 2 * (l + b); }
    void show() {
        cout << "\nRectangle : Length: " << l << ", Breadth: " << b
             << ", Area: " << area() << ", Perimeter: " << peri() << endl;
    }
};

class Triangle {
    double a, b, c;
public:
    void read() {
        cout << "\nEnter three sides of the triangle: "; cin >> a >> b >> c;
        if (a + b <= c || a + c <= b || b + c <= a) a = b = c = 0;
    }
    double peri() { return a + b + c; }
    double area() {
        double s = peri() / 2;
        return (a && b && c) ? sqrt(s * (s - a) * (s - b) * (s - c)) : 0;
    }
    void show() {
        cout << "\nTriangle : Sides: " << a << ", " << b << ", " << c;
        if (a && b && c)
            cout << ", Area: " << area() << ", Perimeter: " << peri() << endl;
        else
            cout << "  Invalid triangle!" << endl;
    }
};

int main() {
    Circle c; Rectangle r; Triangle t;
    cout << "Shape Calculator:\n";
    c.read(); c.show();
    r.read(); r.show();
    t.read(); t.show();
    return 0;
}
*/

/*5. Assume that an object represents an employee report that contains information like employee id, total bonus, total overtime in a particular year. Use an array of objects to represent n employees' reports. Write a program that displays the report. Use setpara() member function to set report attributes by passing the arguments and member function displayreport() to show the report according to the parameter passed. Display the report in the following format.

An employee with ... ... ... has received Rs ... ... ...as a bonus

and

had worked ... ... ... hours as overtime in the year ... ... ...*/

#include <iostream>
using namespace std;

class EmployeeReport
{
private:
    int empId;
    double bonus;
    double overtime;
    int year;

public:
    void setpara(int id, double b, double ot, int y)
    {
        empId = id;
        bonus = b;
        overtime = ot;
        year = y;
    }

    void displayreport()
    {
        cout << "\nAn employee with ID " << empId << " has received Rs " << bonus << " as a bonus" << endl;
        cout << "and had worked " << overtime << " hours as overtime in the year " << year << "." << endl;
    }
};

int main()
{
    int n;

    cout << "Enter number of employees: ";
    cin >> n;

    EmployeeReport employees[n];

    for (int i = 0; i < n; i++)
    {
        int id, year;
        double bonus, overtime;

        cout << "\nEnter details for Employee " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> id;
        cout << "Bonus (Rs): ";
        cin >> bonus;
        cout << "Overtime Hours: ";
        cin >> overtime;
        cout << "Year: ";
        cin >> year;

        employees[i].setpara(id, bonus, overtime, year);
    }

    cout << "\n----- Employee Reports -----" << endl;
    for (int i = 0; i < n; i++)
    {
        employees[i].displayreport();
    }

    return 0;
}
