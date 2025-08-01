/*1. Write a program that can convert the Distance (meter, centimeter) to meters measurement in float and vice versa. Make a class distance with two data members, meter and centimeter. You can add function members as per your requirement.*/
/*#include <iostream>
using namespace std;

class Distance {
private:
    int meter;
    int centimeter;

public:
    Distance() : meter(0), centimeter(0) {}

    Distance(float meters) {
        meter = static_cast<int>(meters);
        centimeter = static_cast<int>((meters - meter) * 100);
    }

    void display() {
        cout << "Meters: " << meter << ", Centimeters: " << centimeter << endl;
    }

    operator float() {
        return meter + (centimeter / 100.0f);
    }
};

int main() {
    float inputMeters;
    cout << "Enter distance in meters (float): ";
    cin >> inputMeters;

    Distance d1 = inputMeters;
    cout << "Converted to object: ";
    d1.display();

    float totalMeters = d1;
    cout << "Converted back to meters (float): " << totalMeters << " meters" << endl;

    return 0;
}
*/

/*2. Write two classes to store distances in meter-centimeter and feet-inch systems respectively. Write conversions functions so that the program can convert objects of both types.*/
/*#include <iostream>
using namespace std;

class FeetInch;  

class MeterCentimeter {
private:
    int meter;
    int centimeter;

public:
    MeterCentimeter(int m = 0, int cm = 0) {
        meter = m;
        centimeter = cm;
    }

    void input() {
        cout << "Enter distance (meters centimeters): ";
        cin >> meter >> centimeter;
    }

    void show() const {
        cout << meter << " meters " << centimeter << " centimeters" << endl;
    }

    int totalCentimeters() const {
        return meter * 100 + centimeter;
    }

    MeterCentimeter(const FeetInch& f); 
};

class FeetInch {
private:
    int feet;
    int inch;

public:
    FeetInch(int f = 0, int i = 0) {
        feet = f;
        inch = i;
    }

    void input() {
        cout << "Enter distance (feet inches): ";
        cin >> feet >> inch;
    }

    void show() const {
        cout << feet << " feet " << inch << " inches" << endl;
    }

    int totalInches() const {
        return feet * 12 + inch;
    }

    FeetInch(const MeterCentimeter& m) {
        float total_cm = m.totalCentimeters();
        float total_inch = total_cm / 2.54;

        feet = static_cast<int>(total_inch) / 12;
        inch = static_cast<int>(total_inch) % 12;
    }
};

MeterCentimeter::MeterCentimeter(const FeetInch& f) {
    float total_inch = f.totalInches();
    float total_cm = total_inch * 2.54;

    meter = static_cast<int>(total_cm) / 100;
    centimeter = static_cast<int>(total_cm) % 100;
}

int main() {
    MeterCentimeter m1;
    m1.input();

    FeetInch f1 = m1;
    cout << "Converted to feet-inch: ";
    f1.show();

    FeetInch f2;
    f2.input();

    MeterCentimeter m2 = f2;
    cout << "Converted to meter-centimeter: ";
    m2.show();

    return 0;
}
 */
/*3. Create a class called Musicians to contain three methods string(), wind(), and perc(). Each of these methods should initialize a string array to contain the following instruments

-  veena, guitar, sitar, sarod and mandolin under string()

-  flute, clarinet saxophone, nadhaswaram, and piccolo under wind()

-  tabla, mridangam, bangos, drums and tambour under perc()

It should also display the contents of the arrays that are initialized. Create a derived class called TypeIns to contain a method called get() and show(). The get() method must display a  menu as follows

Type of instruments to be displayed

a.  String instruments

b.  Wind instruments

c.  Percussion instruments

The show() method should display the relevant detail according to our choice. The base class variables must be accessible only to their derived classes.*/

 /*#include <iostream>
#include <string>
using namespace std;

class Musicians {
protected:
    string stringInstruments[5];
    string windInstruments[5];
    string percussionInstruments[5];

    void string() {
        stringInstruments[0] = "veena";
        stringInstruments[1] = "guitar";
        stringInstruments[2] = "sitar";
        stringInstruments[3] = "sarod";
        stringInstruments[4] = "mandolin";
    }

    void wind() {
        windInstruments[0] = "flute";
        windInstruments[1] = "clarinet";
        windInstruments[2] = "saxophone";
        windInstruments[3] = "nadhaswaram";
        windInstruments[4] = "piccolo";
    }

    void perc() {
        percussionInstruments[0] = "tabla";
        percussionInstruments[1] = "mridangam";
        percussionInstruments[2] = "bangos";
        percussionInstruments[3] = "drums";
        percussionInstruments[4] = "tambour";
    }

public:
    Musicians() {
        string();
        wind();
        perc();
    }
};

class TypeIns : public Musicians {
private:
    char choice;

public:
    void get() {
        cout << "\nType of instruments to be displayed\n";
        cout << "a. String instruments\n";
        cout << "b. Wind instruments\n";
        cout << "c. Percussion instruments\n";
        cout << "Enter your choice: ";
        cin >> choice;
    }

    void show() {
        cout << "\nInstruments List:\n";
        switch (choice) {
            case 'a':
            case 'A':
                for (int i = 0; i < 5; i++) {
                    cout << stringInstruments[i] << endl;
                }
                break;
            case 'b':
            case 'B':
                for (int i = 0; i < 5; i++) {
                    cout << windInstruments[i] << endl;
                }
                break;
            case 'c':
            case 'C':
                for (int i = 0; i < 5; i++) {
                    cout << percussionInstruments[i] << endl;
                }
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    }
};

int main() {
    TypeIns obj;
    obj.get();
    obj.show();
    return 0;
}
*/

/*4. Write three derived classes inheriting functionality of base class person (should have a member function that asks to enter name and age) and with added unique features of student, and employee, and functionality to set properties of student and employee objects. And make one member function for printing the address of the objects of classes (base and derived) using this pointer. Create two objects of the base class and the derived classes each and print the addresses of individual objects. Using a calculator, calculate the address space occupied by each object and verify this with address spaces printed by the program.*/

/*#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    void setPerson() {
        cout << "Enter name and age: ";
        cin >> name >> age;
    }

    void printAddress() {
        cout << "Address of Person object: " << this << endl;
    }
};

class Student : public Person {
private:
    string course;
public:
    void setStudent() {
        setPerson();
        cout << "Enter course: ";
        cin >> course;
    }

    void printAddress() {
        cout << "Address of Student object: " << this << endl;
    }
};

class Employee : public Person {
private:
    string company;
public:
    void setEmployee() {
        setPerson();
        cout << "Enter company: ";
        cin >> company;
    }

    void printAddress() {
        cout << "Address of Employee object: " << this << endl;
    }
};

class Visitor : public Person {
public:
    void setVisitor() {
        setPerson();
    }

    void printAddress() {
        cout << "Address of Visitor object: " << this << endl;
    }
};

int main() {
    Person p1, p2;
    Student s1, s2;
    Employee e1, e2;

    p1.printAddress();
    p2.printAddress();
    s1.printAddress();
    s2.printAddress();
    e1.printAddress();
    e2.printAddress();

    cout << "\nObject sizes (bytes):" << endl;
    cout << "Person: " << sizeof(p1) << endl;
    cout << "Student: " << sizeof(s1) << endl;
    cout << "Employee: " << sizeof(e1) << endl;

    return 0;
}*/

/*5. Write a base class that asks the user to enter a complex number, and make a derived class that adds the complex number of its own to the base. Finally, make a third class that is a friend of derived and calculate the difference between the base complex number and its own complex number.*/

#include <iostream>
using namespace std;

class BaseComplex {
protected:
    float real, imag;
public:
    void getComplex() {
        cout << "Enter real and imaginary part of base complex number: ";
        cin >> real >> imag;
    }

    void showBase() {
        cout << "Base Complex: " << real << " + " << imag << "i" << endl;
    }
};

class DerivedComplex : public BaseComplex {
protected:
    float dReal, dImag;
public:
    void getDerivedComplex() {
        getComplex();
        cout << "Enter real and imaginary part of derived complex number: ";
        cin >> dReal >> dImag;
    }

    void addComplex() {
        float r = real + dReal;
        float i = imag + dImag;
        cout << "Sum: " << r << " + " << i << "i" << endl;
    }

    friend class FriendComplex;
};

class FriendComplex {
private:
    float fReal, fImag;
public:
    void getFriendComplex() {
        cout << "Enter real and imaginary part of friend's complex number: ";
        cin >> fReal >> fImag;
    }

    void diffComplex(DerivedComplex d) {
        float r = d.real - fReal;
        float i = d.imag - fImag;
        cout << "Difference: " << r << " + " << i << "i" << endl;
    }
};

int main() {
    DerivedComplex dc;
    dc.getDerivedComplex();
    dc.addComplex();

    FriendComplex fc;
    fc.getFriendComplex();
    fc.diffComplex(dc);

    return 0;
}

