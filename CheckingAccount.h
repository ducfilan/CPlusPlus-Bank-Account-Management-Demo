#include "head.h"

class CheckingAccount:public Account
{
    double creditMoney;
    double debitMoney;
public:
    CheckingAccount();
    CheckingAccount(char*,string,char*,double,double,double);
    void showMenu();
    
    void viewBalance();
    void credit();
    void debit();
    int getType();
};
