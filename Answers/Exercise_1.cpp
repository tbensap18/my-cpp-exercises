#include <iostream>
using namespace std;

int Add(int &n1, int &n2)
{
    return n1 + n2;
}

int main(void)
{
    int number1, number2, sum;

    cout << "Enter two integers:\n";
    cin >> number1 >> number2;
    sum = Add(number1, number2);
    cout << "\nThe sum is " << sum << ".";
}
