#include <iostream>
using namespace std;
class person
{
public:
    person(string na) : name(na) {}
    virtual int Time() = 0; // Spend time doing something
    virtual void print()    // Display the name
    {
        cout << name << endl;
    }

private:
    string name; // the name of person
};
class student : public person
{
private:
    int classNum;

public:
    // constructor to get name, classNum and send to respective base constructor
    student(string na, int num) : person(na)
    {
        classNum = num;
    }
    int Time()
    { // compute time
        return classNum * 2;
    }
    void print() // call base print method
    {
        person::print();
    }
};
class teacher : public person
{
private:
    int teachingNum;

public:
    // constructor to get name, teachingNum and send to respective base constructor
    teacher(string na, int num) : person(na)
    {
        teachingNum = num;
    }
    int Time()
    { // compute time
        return teachingNum * 2;
    }
    void print() // call base print method
    {
        person::print();
    }
};
class teachAssistant : public student, public teacher
{
public:
    // constructor to get name, classNum, teachingNum and send to respective base constructors
    teachAssistant(string na, int num1, int num2) : student(na, num1), teacher(na,
                                                                               num2)
    {
    }
    int Time()
    { // compute time
        return student::Time() + teacher::Time();
    }
    void print() // call base print method
    {
        student::print();
    }
};
int main()
{
    // create objects
    cout << "Creating objects..." << endl;
    student s("student", 2);                   // for student
    teacher t("teacher", 3);                   // for teacher
    teachAssistant ta("teachAssistant", 4, 5); // for teaching assistant
    // print their names using print methods
    cout << "Printing names..." << endl;
    s.print();  // print student's name
    t.print();  // print teacher's name
    ta.print(); // print teaching assistant's name
    // print their spending time
    cout << "Printing spending time..." << endl;
    cout << "Spending time for a student is " << s.Time() << endl;
    cout << "Spending time for a teacher is " << t.Time() << endl;
    cout << "Spending time for a teachAssistant is " << ta.Time() << endl;
    return 0;
}
