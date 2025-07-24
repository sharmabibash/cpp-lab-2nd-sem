/*1. Write a program that has a class to represent time. The class should have constructors to initialize data members hour, minute, and second to 0 and to initialize them to values passed as arguments. The class should have a member function to add time objects and return the result as a time object. There should be functions to display time in 12-hour and 24-hour format.*/

/*#include<iostream>
#include<ctime>
#include<string>
#include<iomanip>
using namespace std;

class Time {
    private:
    int hour, minute, second;

    public:
    Time(){
        hour=0;
        minute=0;
        second=0;
    }
    Time(int h, int m, int s){
        hour=h;
        minute=m;
        second=s;
        normalize();
    }
    void normalize(){
        minute+=second/60;
        second%=60;
        hour+=minute/60;
        minute%=60;
        hour %= 24;
    }

    void inputTime(){
        cout<<"Enter time in the format (hour minute seconds) :"<<endl;
        cin>> hour >> minute >> second;
    }

    Time add(const Time t){
        Time Result;
        Result.second=second+t.second;
        Result.minute=minute+t.minute;
        Result.hour=hour+t.hour;
        Result.normalize();
        return Result;
    }
    void show24hrs() const {
        cout << setfill('0') << setw(2) << hour << ":"
             << setw(2) << minute << ":"
             << setw(2) << second << " (24-hour format)" << endl;
    }

    void show12hrs() const {
        int showhrs= hour%12;
        if(showhrs==0)
        showhrs=12;

        string period = (hour>=12) ? "PM" : "AM";
        cout << setfill('0') << setw(2) << showhrs << ":"
             << setw(2) << minute << ":"
             << setw(2) << second << " " << period
             << " (12-hour format)" << endl;
    }

};

int main(){
    Time t1,t2;
    cout<<"Enter first time\n";
    t1.inputTime();

    cout<<"Enter second time\n";
    t2.inputTime();

    Time t3 = t1.add(t2);
    cout<<"\nFirst Time\n";
    t1.show24hrs();
    t1.show12hrs();

    cout << "\nSecond Time:\n";
    t2.show12hrs();
    t2.show12hrs();

    cout << "\nSum of Times:\n";
    t3.show24hrs();
    t3.show12hrs();

    return 0;
}*/

/*2. Write a program that has a class with a dynamically allocated character array as its data member. One object should contain "Engineers are" and another should contain " Creatures of logic". Member function join() should concatenate two strings by passing two objects as arguments. Display the concatenated string through a member function. Use constructors to allocate and initialize the data member. Also, write a destructor to free the allocated memory for the character array. Make your own function for the concatenation of two strings.*/

/*#include <iostream>
#include <cstring>
using namespace std;

class Sentence {
private:
    char* str;

public:
    Sentence(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    ~Sentence() {
        cout << "Releasing memory for: \"" << str << "\"\n";
        delete[] str;
    }

    void join(const Sentence& s1, const Sentence& s2) {
        delete[] str;
        int totalLength = strlen(s1.str) + strlen(s2.str) + 1;
        str = new char[totalLength];
        strcpy(str, s1.str);
        strcat(str, s2.str);
    }

    void display() const {
        cout << str << endl;
    }
};

int main() {
    Sentence part1("Engineers are");
    Sentence part2(" Creatures of logic");
    Sentence fullSentence("");

    fullSentence.join(part1, part2);

    cout << "\nCombined Sentence:\n";
    fullSentence.display();

    return 0;
}*/

/*3. Write a class that can store Department ID and Department Name with constructors to initialize its members. Write destructor member in the same class and display the message "Object n goes out of the scope". Your program should be made such that it should show the order of constructor and destructor invocation.*/

/*#include<iostream>
#include<cstring>
using namespace std;
class Department{
    private:
    int deptID;
    string deptName;
    int objNum;
    static int count;

    public:
    Department(){
        cout<<"Enter Department ID :";
        cin>>deptID;
        cout<<"Enter Department Name :";
        cin>>deptName;
        objNum = count++;

        cout << "Constructor called for Object " << objNum << endl;
    }
    ~Department() {
        cout << "Object " << objNum << " goes out of the scope" << endl;
    }

    void display() {
        cout << "Department ID: " << deptID << ", Name: " << deptName << endl;
    }
};
int Department::count=0;
int main(){
     {
        Department d1;
        d1.display();

        Department d2;
        d2.display();
    }

    Department d3;
    d3.display();
    return 0;
}*/

/*4. Assume that one constructor initializes data member say num_vehicle, hour, and rate. There should be a 10% discount if num_vehicle exceeds 10. Display the total charge. Use two objects and show a bit-by-bit copy of one object to another (make your own copy constructor).*/

/*#include <iostream>
using namespace std;
class Park
{
private:
    int num_vehicle;
    int hour;
    float rate;
    float total_charge;

public:
    Park(int nv, int h, float r)
    {
        num_vehicle = nv;
        hour = h;
        rate = r;

        float charge = num_vehicle * hour * rate;

        if (num_vehicle > 10)
        {
            charge -= charge * 0.10;
        }

        total_charge = charge;

        cout << "Constructor called.\n";
    }

    Park(const Park &p) {
        num_vehicle = p.num_vehicle;
        hour = p.hour;
        rate = p.rate;
        total_charge = p.total_charge;

        cout << "Copy Constructor copy done.\n";
    }

    void display() {
        cout << "Vehicles: " << num_vehicle << ", Hours: " << hour
             << ", Rate: " << rate << ", Total Charge: Rs. " << total_charge << endl;
    }
};
int main()
{ int v, h;
    float r;

    cout << "Enter number of vehicles: ";
    cin >> v;

    cout << "Enter number of hours: ";
    cin >> h;

    cout << "Enter rate per hour: ";
    cin >> r;

    Park p1(v, h, r);   
    p1.display();

    Park p2 = p1;       
    p2.display();

    return 0;
    
}*/

/*5. Write a program that illustrates the following relationship and comment on them. 

i) const_object.non_const_mem_function

ii) const_object.const_mem_function

iii) non_const_object.non_const_mem_function

iv) non_const_object.const_mem_function*/

/*#include<iostream>
using namespace std;
class Test {
public:
    void nonConstFunction() {
        cout << "Non-const member function called." << endl;
    }

    void constFunction() const {
        cout << "Const member function called." << endl;
    }
};

int main(){
    Test obj;               
    const Test constObj;  

    // i) const_object.non_const_mem_function 
    // constObj.nonConstFunction(); 
    //ii) const_object.const_mem_function 
    constObj.constFunction(); 

    // iii) non_const_object.non_const_mem_function 
    obj.nonConstFunction(); 

    // iv) non_const_object.const_mem_function 
    obj.constFunction(); 

    return 0;
   
}*/

/*6. Create a class with a data member to hold a "serial number" for each object created from the class. That is, the first object created will be numbered 1, the second 2, and so on by using the basic concept of static data members. Use static member function if it is useful in the program. Otherwise, make a separate program that demonstrates the use of static member function.*/

#include <iostream>
using namespace std;

class MyClass {
private:
    int serialNumber;
    static int count;

public:
    MyClass() {
        serialNumber = ++count;
        cout << "Object " << serialNumber << " created.\n";
    }

    void display() const {
        cout << "This is object number: " << serialNumber << endl;
    }

 
    static void showTotalObjects() {
        cout << "Total objects created: " << count << endl;
    }
};

int MyClass::count = 0;

int main() {
    MyClass obj1;
    obj1.display();

    MyClass obj2;
    obj2.display();

    MyClass obj3;
    obj3.display();
    MyClass::showTotalObjects();

    return 0;
}


