#include "head.h"

#define FEE 5
//Ctor 0 para
CheckingAccount::CheckingAccount():Account()
{
    creditMoney=debitMoney=0;
}
//Ctor 5 para.s
CheckingAccount::CheckingAccount(char* id,string pa,char* na,double ba,double cr,double db):Account(id,pa,na,ba)
{
	creditMoney=cr;
	debitMoney=db;
}

//Show menu
void CheckingAccount::showMenu()
{
	char choice;
	do
    {
        system("cls");
        cout<<"+========================================+"<<endl;
        cout<<"|       Cheking Account Management       |"<<endl;
        cout<<"+========================================+"<<endl;
        cout<<"| 1. View Balance                        |"<<endl;
        cout<<"| 2. Credit                              |"<<endl;
        cout<<"| 3. Debit                               |"<<endl;
        cout<<"| 0. Exit                                |"<<endl;
        cout<<"+----------------------------------------+"<<endl;
        cout<<"| Your selection(0->3) : ";
        fflush(stdin);
        cin>>choice;
        
        if(choice=='0') break;
        switch(choice)
        {
	        case '1':
				viewBalance();
	            break;
	        case '2':
	            credit();
	            break;
	        case '3':
	            debit();
	            break;
	        default:
				cout<<"Invalid choice!"<<endl;
	        	break;
        }
    }while(1);
}
//View Balance
void CheckingAccount::viewBalance()
{
    Account::viewBalance();
    cout<<"| Account type       : Checking Account"<<endl<<endl;
    system("pause");
}

void CheckingAccount::credit()
{
	creditMoney=acceptPos("| Input amount to credit : ");
	balance=balance+creditMoney-FEE;
	cout<<"| Successfully!"<<endl<<endl;
	system("pause");
}

void CheckingAccount::debit()
{
	bool isOk=false;
    do
    {
	    debitMoney=acceptPos("| Input amount to debit: ");
		if(balance<=debitMoney)
	    {
	        cout<<"| Balance is not enough to debit!"<<endl;
	        continue;
	    }else isOk=true;
	    balance=balance-debitMoney-FEE;
	}while(!isOk);
	cout<<"| Successfully!"<<endl<<endl;
	system("pause");
}

int CheckingAccount::getType()
{
	return 2;
}
