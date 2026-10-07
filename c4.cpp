#include <iostream>
using namespace std;

// Single Base Class
class Ledger {
protected:
    double balance;
public:
    void setBalance(double b) {
        balance = b;
    }
    void showBalance() {
        cout << "Current Ledger Balance: $" << balance << endl;
    }
};

// Derived Class 1
class SavingsAccount : public Ledger {
private:
    double interestRate;
public:
    void setInterest(double rate) { interestRate = rate; }
    void applyInterest() {
        balance += (balance * interestRate);
        cout << "[Savings Account] Interest applied." << endl;
        showBalance();
    }
};

// Derived Class 2
class CheckingAccount : public Ledger {
private:
    double overdraftLimit;
public:
    void setOverdraft(double limit) { overdraftLimit = limit; }
    void withdraw(double amount) {
        cout << "\n[Checking Account] Attempting withdrawal of $" << amount << endl;
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            cout << "Withdrawal successful." << endl;
        } else {
            cout << "Transaction declined: Exceeds overdraft limit." << endl;
        }
        showBalance();
    }
};

int main() {
    SavingsAccount savings;
    savings.setBalance(1000);
    savings.setInterest(0.05);
    savings.applyInterest();

    CheckingAccount checking;
    checking.setBalance(500);
    checking.setOverdraft(200);
    checking.withdraw(600);
    
    return 0;
}