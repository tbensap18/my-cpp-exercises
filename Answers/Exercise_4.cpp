#include <iostream>
#include <iomanip>
using namespace std;
class Account
{ ///-------Base class Account header
public:
    Account();
    // default connector
    Account(double in_dep);
    // connector with initial deposit
    Account(double in_dep, double in_with); // connector with initial deposit and
    // initial withdrawal
    void make_deposit(double in_dep);     // method to make deposit
    void make_withdrawal(double in_with); // method to make withdrawal
    double get_balance();
    // method to get balance
    virtual double daily_interest() = 0; // virtual member for daily_interest member functions
private:
    double balance;  // current balance of account
    double deposit;  // amount of deposit
    double withdraw; // amount of withdrawal
};
///------------Begin member functions implementations of Acccount base class--------- -- -- - ////
Account::Account()
{
    balance = 0.0;
}
Account::Account(double in_dep)
{
    balance = in_dep;
}
Account::Account(double in_dep, double in_with)
{
    balance = in_dep - in_with;
}
void Account::make_deposit(double in_dep)
{
    balance = balance + in_dep;
}
void Account::make_withdrawal(double in_with)
{
    balance = balance - in_with;
}
double Account::get_balance()
{
    return balance;
}
//---------------------end Account member functions--------------//
class Checking : public Account
{ //-------------Checking derived class header
public:
    Checking();
    // default connector
    Checking(double in_dep);
    // connector with just deposit specified
    Checking(double in_dep, double in_with);
    // connector with both deposit and withdrawal
    virtual double daily_interest();
    // method for calculating interest and updating balance
private:
    double interest_rate = 0.03 / 30; // daily interest rate
    double min_balance = 1000;        // minimum balance for collecting interest
};
//-----------------------Begin member function implementations for Checking ---///
Checking::Checking() : Account() {}
Checking::Checking(double in_dep) : Account(in_dep) {}
Checking::Checking(double in_dep, double in_with) : Account(in_dep, in_with) {}
double Checking::daily_interest()
{
    bool more = true;
    double amt = 0.0;
    int day = 0;
    if (Account::get_balance() - min_balance <= 0)
    {
        // verify balance is above minimum balance
        // to collect interest
        more = false;
        amt = 0.0;
    }
    else
    {
        amt = (Account::get_balance() - min_balance) * interest_rate; // calculate amount of interest earned
        Account::make_deposit(amt);
        // update balance by interest earned
    }
    return amt;
    // return amount of daily interest earned
}
///--------------------end member functions for Checking-----------------////
class Savings : public Account
{ //------------------Savings derived class header
public:
    Savings();
    // default connector
    Savings(double in_dep);
    // connector with just deposit
    Savings(double in_dep, double in_with);
    // connector w/ deposit and withdrawal
    virtual double daily_interest();
    // method to calculate interest and update balance
private:
    double interest_rate = 0.06 / 30; // daily interest rate
    double min_balance = 0.0;
    // min balance for collecting interest
};
//--------------begin member function implementation for Savings---------//
Savings::Savings() : Account() {}
Savings::Savings(double in_dep) : Account(in_dep) {}
Savings::Savings(double in_dep, double in_with) : Account(in_dep, in_with) {}
double Savings::daily_interest()
{
    double amt = 0.0;
    amt = Account::get_balance() * interest_rate;
    Account::make_deposit(amt);
    return amt;
}
///-----------end Savings member functions------------------//
/*main() will ask for the account type and the number of days (enter 30 for a
full month), then will display interest earned that day and the current balance
for each day.*/
int main()
{
    int n = 0;
    // how many days worth of deposits/withdrawals to make
    double deposit = 0.0;
    // amount of daily deposit
    double withdrawal = 0.0; // amount of daily withdrawal
    bool more = true;        // flag to continue
    int i = 1;
    // counter for displaying current day
    char type = ' '; // flag for account type
    Account *account;
    // pointer to Account object type
    cout << "Enter account type (\"c\" for checking, \"s\" for savings): " << endl;
    cin >> type;
    if (type == 'c')
    { // if this is a checking account, instantiate a Checking
        Checking c;
        // object and assign the "account" pointer to its address
        account = &c;
    }
    else if (type == 's')
    { // if this is a savings account, instantiate a Savings
        Savings s;
        // object and assign the "account" pointer to its address
        account = &s;
    }
    else
    {
        cout << "Not a valid entry." << endl; // bail if user gives invalid input for account type
        more = false;
    }
    if (more)
    {
        // get the number of days (we could set this to 30 to meet strict
        // requirements of assignment, but this makes it easier to test).
        cout << "How many days of deposits/withdrawals would you like to make? " << endl;
        cin >> n;
        if (n < 1)
            more = false;
        cout << fixed << setprecision(2); // set number of digits todisplay in output (these are persistent
        // so I'll set them here to avoid unecessary repetition in below loop).
    }
    while (more)
    {
        cout << "Enter deposit for day " << i << endl; // get deposit amount
        cin >> deposit;
        cout << "Enter withdrawal for day " << i << endl; // get withdrawal amount
        cin >> withdrawal;
        account->make_deposit(deposit);                                             // update account balance with deposit amount
        account->make_withdrawal(withdrawal);                                       // update account balance with withrawal amount
        cout << "Daily interest earned is: $" << account->daily_interest() << endl; // display daily interest earned AND update balance by that amount
        cout << "Balance is: $" << account->get_balance() << endl;
        // display total balance (just a sanity check).
        i++; // increment i
        n--; // decrement n
        if (n < 1)
            more = false; // bail if all days have been entered
    }
    cout << "Xiexie.\n";
    system("PAUSE");
    return 0;
}
