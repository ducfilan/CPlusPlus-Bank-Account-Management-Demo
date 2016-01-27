class SavingAccount : public Account
{
    double interest;
    double creditMoney;
    double debitMoney;
public:
    SavingAccount();
    SavingAccount(char*,string,char*,double,double,double,double);
    void credit();
    void debit();
    
    void viewBalance();
    void calculateInterest();
    void showMenu();
    int getType();
};
