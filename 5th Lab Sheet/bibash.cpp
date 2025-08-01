/*1. Write a program to make classes for instantiating the objects that represent the two-dimensional Cartesian coordinate system.

A. Make a particular member function of one class a friend function of another class for addition.

B. Make three non-member functions that work as a bridge between two classes for multiplication, division, and subtraction.

C. Demonstrate that all the member functions of one class are the friend functions of another class if the former class is made a friend of the latter.

Make the least possible classes to demonstrate all the above in a single program without conflict.*/

#include <iostream>
using namespace std;

class PointB;
class PointA
{
private:
    int x, y;

public:
    void input()
    {
        cout << "Enter Coordinates for Point A (x y) : ";
        cin >> x >> y;
    }

    void addPointB(PointB p);
    void display()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    friend class PointB;
    friend void multiplyPoints(PointA, PointB);
    friend void dividePoints(PointA, PointB);
    friend void subtractPoints(PointA, PointB);
};

class PointB
{
private:
    int x, y;

public:
    void input()
    {
        cout << "Enter coordinates for PointB (x y) : ";
        cin >> x >> y;
    }
    void display()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
    friend void PointA::addPointB(PointB p);
    friend void multiplyPoints(PointA, PointB);
    friend void dividePoints(PointA, PointB);
    friend void subtractPoints(PointA, PointB);
};

void PointA::addPointB(PointB p)
{
    cout << "Add Result : (" << x + p.x << ", " << y + p.y << ")" << endl;
}
void multiplyPoints(PointA a, PointB b) {
    cout << "Multiplication result: (" << a.x * b.x << ", " << a.y * b.y << ")" << endl;
}

void dividePoints(PointA a, PointB b) {
    cout << "Division result: (" << a.x / b.x << ", " << a.y / b.y << ")" << endl;
}

void subtractPoints(PointA a, PointB b) {
    cout << "Subtraction result: (" << a.x - b.x << ", " << a.y - b.y << ")" << endl;
}

int main() {
    PointA p1;
    PointB p2;


    p1.input();
    p2.input();

    cout << "\nPointA: "; p1.display();
    cout << "PointB: "; p2.display();

   
    p1.addPointB(p2);

   
    multiplyPoints(p1, p2);
    dividePoints(p1, p2);
    subtractPoints(p1, p2);

 
    // cout << "Accessing PointB private data directly from friend class PointA: ";
    // cout << "(" << p2.x << ", " << p2.y << ")" << endl;

    return 0;
}

/*2. Write a class to store x, y, and z coordinates of a point in three-dimensional space. Overload the addition and subtraction operators for the addition and subtraction of two coordinate objects. Implement the operator functions as non-member functions.*/
/*#include <iostream>
using namespace std;

class Point3D {
private:
    int x, y, z;

public:
    // Constructor
    Point3D(int _x=0, int _y=0, int _z=0) : x(_x), y(_y), z(_z) {}

    // Function to input values
    void input() {
        cout << "Enter coordinates (x y z): ";
        cin >> x >> y >> z;
    }

    // Function to display the point
    void display() const {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }

    // Declare non-member operator functions as friend
    friend Point3D operator+(Point3D a, Point3D b);
    friend Point3D operator-(Point3D a, Point3D b);
};

// Non-member function to overload + operator
Point3D operator+(Point3D a, Point3D b) {
    return Point3D(a.x + b.x, a.y + b.y, a.z + b.z);
}

// Non-member function to overload - operator
Point3D operator-(Point3D a, Point3D b) {
    return Point3D(a.x - b.x, a.y - b.y, a.z - b.z);
}

int main() {
    Point3D p1, p2, sum, diff;

    // Input points from user
    cout << "Enter first point:" << endl;
    p1.input();
    cout << "Enter second point:" << endl;
    p2.input();

    // Addition
    sum = p1 + p2;

    // Subtraction
    diff = p1 - p2;

    // Display results
    cout << "\nFirst Point: "; p1.display();
    cout << "Second Point: "; p2.display();
    cout << "Sum: "; sum.display();
    cout << "Difference: "; diff.display();

    return 0;
}*/


/*3. Write a program to compare two objects of a class that contains an integer value as its data member. Make overloading functions to overload equality(==), less than(<), greater than(>), not equal (!=), greater than or equal to (>=), and less than or equal to(<=) operators using member operator functions.*/

/*#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    // Constructor
    Number(int v=0) : value(v) {}

    // Function to input value
    void input() {
        cout << "Enter an integer value: ";
        cin >> value;
    }

    // Display function
    void display() const {
        cout << value << endl;
    }

    // Overload equality operator
    bool operator==(const Number& other) const {
        return value == other.value;
    }

    // Overload less than operator
    bool operator<(const Number& other) const {
        return value < other.value;
    }

    // Overload greater than operator
    bool operator>(const Number& other) const {
        return value > other.value;
    }

    // Overload not equal operator
    bool operator!=(const Number& other) const {
        return value != other.value;
    }

    // Overload greater than or equal to operator
    bool operator>=(const Number& other) const {
        return value >= other.value;
    }

    // Overload less than or equal to operator
    bool operator<=(const Number& other) const {
        return value <= other.value;
    }
};

int main() {
    Number n1, n2;

    cout << "Enter first number:" << endl;
    n1.input();

    cout << "Enter second number:" << endl;
    n2.input();

    cout << "\nFirst number: "; n1.display();
    cout << "Second number: "; n2.display();

    cout << "\nComparison results:" << endl;

    if (n1 == n2)
        cout << "Both numbers are equal." << endl;
    else
        cout << "Numbers are not equal." << endl;

    if (n1 < n2)
        cout << "First number is less than second number." << endl;

    if (n1 > n2)
        cout << "First number is greater than second number." << endl;

    if (n1 != n2)
        cout << "Numbers are different." << endl;

    if (n1 >= n2)
        cout << "First number is greater than or equal to second number." << endl;

    if (n1 <= n2)
        cout << "First number is less than or equal to second number." << endl;

    return 0;
}
*/

/*4. Write a class Date that overloads prefix and postfix operators to increase the Date object by one day, while causing appropriate increments to the month and year (use the appropriate condition for leap year). The prefix and postfix operators in the Date class should behave exactly like the built-in increment operators.*/

/*#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;
    static const int daysInMonth[12];

    bool isLeapYear(int y) const {
        return ( (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) );
    }

public:
    Date(int d=1, int m=1, int y=2000) : day(d), month(m), year(y) {}

    void input() {
        cout << "Enter date (day month year): ";
        cin >> day >> month >> year;
    }

    void display() const {
        cout << day << "/" << month << "/" << year << endl;
    }

    Date& operator++() {
        int maxDay = daysInMonth[month - 1];
        if (month == 2 && isLeapYear(year)) {
            maxDay = 29;
        }
        day++;
        if (day > maxDay) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        return *this;
    }

    Date operator++(int) {
        Date temp = *this;
        ++(*this);
        return temp;
    }
};

const int Date::daysInMonth[12] = 
    {31,28,31,30,31,30,31,31,30,31,30,31};

int main() {
    Date d;

    d.input();

    cout << "\nOriginal date: ";
    d.display();

    cout << "\nAfter prefix increment (++d): ";
    ++d;
    d.display();

    cout << "\nAfter postfix increment (d++): ";
    d++;
    d.display();

    cout << "\nAnother postfix increment (d++): ";
    Date oldDate = d++;
    cout << "Old date returned: ";
    oldDate.display();
    cout << "New date after increment: ";
    d.display();

    return 0;
}
*/