//Design a Banking System with Account, SavingsAccount, and CurrentAccount classes using inheritance, encapsulation, and virtual functions for interest calculation and overdraft limits.
#include<iostream>
using namespace std;
class Account{
protected:
    string n;
    double b;
public:
    Account(string na,double ba){
        n=na;
        b=ba;
    }
    virtual void display(){
        cout<<"Account Holder:"<<n<<", Balance:"<<b<<endl;
    }
    virtual void calculateInterest()=0;
};
class SavingsAccount:public Account{
    double r;
public:
    SavingsAccount(string na,double ba,double ra):Account(na,ba),r(ra){}
    void calculateInterest(){
        b+=b*(r/100);
        cout<<"Savings Interest applied. New balance:"<<b<<endl;
    }
};
class CurrentAccount:public Account{
    double o;
public:
    CurrentAccount(string na,double ba,double ov):Account(na,ba),o(ov){}
    void calculateInterest(){
        cout<<"No interest for Current Account."<<endl;
    }
    void withdraw(double a){
        if(a<=b+o){
            b-=a;
            cout<<"Withdrawal successful. Balance:"<<b<<endl;
        }else{
            cout<<"Exceeds overdraft limit."<<endl;
        }
    }
};
int main(){
    SavingsAccount s("A",1000,5);
    CurrentAccount c("B",500,200);
    s.calculateInterest();
    c.withdraw(600);
    return 0;
}