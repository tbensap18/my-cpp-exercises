#include <iostream>
#include <math.h>
using namespace std;
double power(double m, int n)
{
    double t;
    t = pow(m, n);
    return t;
}
int power(int m, int n)
{
    int p;
    p = pow(m, n);
    return p;
}
int main()
{
    double m, ans1;
    int n, ans2;
    cout << "enter the base number\n";
    cin >> m;
    cout << "enter the power\n";
    cin >> n;
    ans1 = power(m, n);
    ans2 = power(m, n);
    cout << "First answer is: " << ans1 << endl;
    cout << "Second answer is: " << ans2 << endl;
    return 0;
}
