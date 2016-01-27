#include "head.h"
#define RATE 6 //In percentage

//Constructor 0 para
SavingAccount::SavingAccount():Account()
{
	creditMoney=debitMoney=interest=0;
}

SavingAccount::SavingAccount(char* id,string pa,char* na,double ba,double cr,double db,double it):Account(id,pa,na,ba)
{
	creditMoney=cr;
	debitMoney=db;
	interest=it;
}
//Show Menu
void SavingAccount::showMenu()
{
	char choice;
	do
    {
        system("cls");
        cout<<"+========================================+"<<endl;
        cout<<"|       Saving Account  Management       |"<<endl;
        cout<<"+========================================+"<<endl;
        cout<<"| 1. View Balance                        |"<<endl;
        cout<<"| 2. View Interest Amount                |"<<endl;
        cout<<"| 3. Credit                              |"<<endl;
        cout<<"| 4. Debit                               |"<<endl;
        cout<<"| 0. Exit to main menu                   |"<<endl;
		cout<<"+----------------------------------------+"<<endl;
        cout<<"| Your selection(0->2): ";
        fflush(stdin);
        cin>>choice;
        
        if(choice=='0') break;
        switch(choice)
        {
	        case '1':
				viewBalance();
	            break;
	        case '2':
	            calculateInterest();
	            break;
	        case '3':
	            credit();
	            break;
	        case '4':
	            debit();
	            break;
	        default:
				cout<<"Wrong choice!"<<endl;
	        	system("pause");
	        	break;
        }
    }while(1);
}
//Cal Interes
void SavingAccount::calculateInterest()
{
	interest=(balance*RATE)/100;
	cout<<"| Interest rate                  : "<<RATE<<"%"<<endl;
	cout<<"| Your current account Balance is: "<<balance<<endl;
	cout<<"| Your current interest Amount is: "<<interest<<endl<<endl;
	system("pause");
}

//View Balance
void SavingAccount::viewBalance()
{
    Account::viewBalance();
    cout<<"| Account type       : Saving Account"<<endl<<endl;
    system("pause");
}
//Credit
void SavingAccount::credit()
{
	creditMoney=acceptPos("| Input amount to credit: ");
	balance+=creditMoney;
	cout<<"| Successfully!"<<endl<<endl;
	system("pause");
}
//Debit
void SavingAccount::debit()
{
    bool isOk=false;
    do
    {
	    debitMoney=acceptPos("| Input amount to debit: ");
	    if(balance<=debitMoney)
	    {
	        cout<<"| Balance is not enough to debit"<< endl;
	        continue;
	    }else isOk=true;
	    balance-=debitMoney;
	}while(!isOk);
	cout<<"| Successfully!"<<endl<<endl;
	system("pause");
}
//Get Type
int SavingAccount::getType()
{
	return 1;
}
