# My OOP C++ Exercise

---

## Question 1

Write a program with a function that takes two integer parameters, adds them together, and takes a third, pass by reference parameter, returns the sum. The return type of this function should be void. The program should ask the user for two numbers, then call the function with the numbers as arguments, and tell the user the sum.
### Answer


---

## Question 2

Write a C++ program to implement function overloading in order to compute power(m,n), which returns the value of m<sup>n<sup/>, where
- m is double and n is int.
- m and n are int.
### Answer


---

## Question 3

Create a class called 'TIME' that has
- three integer data members for hours, minutes and seconds
- construct to initialize the object to zero
- construct to initialize the object to some constant value
- member function to add two TIME objects
- member function to display time in HH:MM:SS format

Write a main function to create two TIME objects, add them and display the result in HH:MM:SS format.
### Answer


---

## Question 4

Implement a base class Account and derived classes Savings and Checking. In the base class, supply member functions deposit and withdraw. Provide a function daily_interest that computes and adds the daily interest. For calculations, assume that every month is 30 days. Checking accounts yield interest of 3% monthly on balances over $1,000. Savings accounts yield interest of 6% on the entire balance.
### Answer


---

## Question 5

Given the definition of a class person

``` 
class person{
    public:
          person(string na):name(na) {}
          virtual int Time()=0; // Spend time doing something
          virtual void print() // Display the name
          { cout<<name<<endl; }
    private:
          string name; // the name of person
           };
```
- Define three classes student, teacher and teachAssistant.
  - Classes student and teacher are derived from class person.
  - Class teachAssistant is derived from student and teacher.
  - Class student has the data member of name and classNum.
  - Class teacher has the data members of name and teachingNum.
  - Class teachAssistant has the data members of name, classNum and teachingNum
  
- Definition of function Time for each class is
  - Spending time for a student is classNum * 2;
  - Spending time for a teacher is teachingNum * 2;
  - Spending time for a teachAssistant is classNum * 2 + teachingNum * 2;
  
- Definition of function print for each class.
- Write a main function to show how these classes are used. 
### Answer




