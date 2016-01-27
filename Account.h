#include"head.h"
class Account
{
protected:
    char* name; 
    char* userID;
    double balance;
    string pass;
public: 
	//Constructor
    Account(); 
    Account(char*,string,char*,double);
    //Destructor
    ~Account();
    //Get
    char* getName();
    char* getUserID();
    string getPass();
    double getBalance();
    virtual int getType() {}
    //Set
    void set(char*,string,char*,double);
    //Show menu
    virtual void showMenu() {}
    //Credit,debit
    virtual void credit() {}
    virtual void debit() {}
    //View Balance
    virtual void viewBalance();
};

void mainMenu(Account**);
void createDefault(Account**,int&);     //Op. 1
void createAnAccount(Account**,int&);   //Op. 2
void login(Account**,int&);			    //Op. 3
void viewAll(Account**,int&);		    //Op. 4
//Accept
char* acceptID();
string acceptPW(char*);
double acceptPos(char*);

void saveDataToFile(Account**,const char *filename,int&);
string inputPassword(size_t length_max);//Code tham khao tren Internet
