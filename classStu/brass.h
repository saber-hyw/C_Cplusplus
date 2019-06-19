#ifndef BRASS_H_
#define BRASS_H_

#include "defs.h"

class Brass {  // base class
public:
    Brass(const string &s = "Nullbody", long an = -1, double bal = 0.0);
    virtual ~Brass();  // 虚析构函数，后面会介绍基类中虚析构函数的作用；

    void Deposit(double amt);           // 存款
    void withdraw(double amt);  // 取现
    double Balance() const;             // 余额
    void viewAcct() const {cout << "Brass::viewAcct" << endl;};      // 查看

private:
    string fullName;
    long acctNum;
    double balance;
};

// brass plus
class BrassPlus : public Brass {
public:
    BrassPlus(const string &s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.1125);
    BrassPlus(const Brass &ba, double ml = 500, double r = 0.1125);
    ~BrassPlus();

    // 继承并重写虚函数
    void withdraw(double amt);  // 取现
    void viewAcct() const {cout << "BrassPlus::viewAcct" << endl;};      // 查看

    void ResetMax(double m) {maxLoan = m;};
    void ResetRate(double r) {rate = r;};
    void ResetOwes() {owesBank = 0;};

private:
    double maxLoan;
    double rate;
    double owesBank;
};

#endif