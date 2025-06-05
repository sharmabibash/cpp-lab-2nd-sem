/*1. Write a program to set a structure to hold a date (mm,dd and yy), assign values to the members of the structure and print out the values in the format 11/28/2004 by function. Pass the structure to the function*/
/*#include <iostream>
using namespace std;

struct Date {
    int mm;
    int dd;
    int yy;
};

void printDate(Date d) {
    cout << d.mm << "/" << d.dd << "/" << d.yy << endl;
}

int main() {
    Date today;
    today.mm = 11;
    today.dd = 28;
    today.yy = 2004;

    printDate(today);

    return 0;
}
*/

/*2. Write a program using the function overloading that converts feet to inches. Use function with no argument, one argument and two arguments. Decide yourself the types of arguments. Use pass by reference in any one of the function above.*/
/*#include <iostream>
using namespace std;

// Function with no argument
void convert() {
    int feet;
    cout << "Enter feet (no argument version): ";
    cin >> feet;
    cout << feet << " feet = " << feet * 12 << " inches" << endl;
}

// Function with one argument
void convert(int feet) {
    cout << feet << " feet = " << feet * 12 << " inches" << endl;
}

// Function with two arguments (pass by reference)
void convert(int feet, int &inches) {
    inches = feet * 12;
}

int main() {
    convert();  // No argument version

    int feet1;
    cout << "Enter feet (one argument version): ";
    cin >> feet1;
    convert(feet1);  // One argument version

    int feet2, inches;
    cout << "Enter feet (two arguments version): ";
    cin >> feet2;
    convert(feet2, inches);  // Two arguments with pass by reference
    cout << feet2 << " feet = " << inches << " inches" << endl;

    return 0;
}
*/

/*3. Define two namespaces: Square and Cube. In both the namespaces, define an integer variable named "num" and a function named "fun". The "fun" function in "Square" namespace, should return the square of an integer passed as an argument while the "fun" function in "Cube" namespace, should return the cube of an integer passed as an argument. In the main function, set the integer variables "num" of both the namespaces with different values. Then, compute and print the cube of the integer variable "num" of the "Square" namespace using the "fun" function of the "Cube" namespace and the square of the integer variable "num" of the "Cube" namespace using the "fun" function of the "Square" namespace.*/
/*#include <iostream>
using namespace std;

// Define Square namespace
namespace Square {
    int num;
    int fun(int x) {
        return x * x;
    }
}

// Define Cube namespace
namespace Cube {
    int num;
    int fun(int x) {
        return x * x * x;
    }
}

int main() {
    // Take user input for both num values
    cout << "Enter value for Square::num: ";
    cin >> Square::num;

    cout << "Enter value for Cube::num: ";
    cin >> Cube::num;

    // Compute and display swapped results
    cout << "Cube of Square::num using Cube::fun: " 
         << Cube::fun(Square::num) << endl;

    cout << "Square of Cube::num using Square::fun: " 
         << Square::fun(Cube::num) << endl;

    return 0;
}
*/


/*4. Write a function that passes two temperatures by reference and sets the larger of the two numbers to a value entered by user by using return by reference.*/

/*#include <iostream>
using namespace std;

// Function to return reference to the larger value
float& updateLarger(float &temp1, float &temp2) {
    return (temp1 > temp2) ? temp1 : temp2;
}

int main() {
    float t1, t2;

    // Input temperatures
    cout << "Enter first temperature: ";
    cin >> t1;
    cout << "Enter second temperature: ";
    cin >> t2;

    // Get new value from user to set the larger temperature
    float newTemp;
    cout << "Enter new value to assign to the larger temperature: ";
    cin >> newTemp;

    // Assign new value to the larger temperature
    updateLarger(t1, t2) = newTemp;

    // Display updated temperatures
    cout << "Updated temperatures:\n";
    cout << "Temperature 1: " << t1 << endl;
    cout << "Temperature 2: " << t2 << endl;

    return 0;
}
*/

/*5. Assume that employee will have to pay 10 percent income tax to the government. Ask user to enter the employee salary. Use inline function to display the net payment to the employee by the company.*/

/*#include <iostream>
using namespace std;

// Inline function to calculate net payment
inline float netPayment(float salary) {
    return salary - (salary * 0.10);  // Deduct 10% tax
}

int main() {
    float salary;

    // Get salary from user
    cout << "Enter employee salary: ";
    cin >> salary;

    // Display net payment
    cout << "Net payment to employee: " << netPayment(salary) << endl;

    return 0;
}
*/

/*6. Write a program that displays the current monthly salary of chief executive officer, information officer, and system analyst, programmer that has been increased by 9, 10, 12, and 12 percentages respectively in year 2010. Let us assume that the salaries in year 2009 are

Chief executive officer Rs. 35000/m

Information officer Rs. 25000/m

System analyst Rs. 24000/m

Programmer Rs. 18000/m

Make a function that takes two arguments; one salary and the other increment. Use proper default argument.*/

/*#include <iostream>
using namespace std;

// Function to calculate updated salary with default increment of 10%
float updatedSalary(float salary, float increment = 10.0) {
    return salary + (salary * increment / 100);
}

int main() {
    // 2009 salaries
    float ceo_salary_2009 = 35000;
    float info_officer_salary_2009 = 25000;
    float analyst_salary_2009 = 24000;
    float programmer_salary_2009 = 18000;

    // Display updated salaries in 2010
    cout << "Salaries in 2010 after increments:\n";
    cout << "Chief Executive Officer: Rs. " 
         << updatedSalary(ceo_salary_2009, 9) << "/m\n";

    cout << "Information Officer: Rs. " 
         << updatedSalary(info_officer_salary_2009, 10) << "/m\n";

    cout << "System Analyst: Rs. " 
         << updatedSalary(analyst_salary_2009, 12) << "/m\n";

    cout << "Programmer: Rs. " 
         << updatedSalary(programmer_salary_2009, 12) << "/m\n";

    return 0;
}
*/