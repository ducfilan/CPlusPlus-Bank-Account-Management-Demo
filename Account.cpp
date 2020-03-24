#include"head.h"

//Ctor 0 para
Account::Account()
{
    name=new char[30];
    userID=new char[10];
    strcpy(name,"");
    strcpy(userID,"");
    pass="";
    balance=0;
}
//Dtor
Account::~Account()
{
    if(name!=NULL)
    {
        delete[] name;
        name=NULL;
    }
    if(userID!=NULL)
    {
        delete[] userID;
        userID=NULL;
    }
        
}

//Set
void Account::set(char AuserID[],string Apass,char Aname[],double Abalance)
{
    strcpy(userID,AuserID);
    strcpy(name,Aname);
    pass=Apass;
    balance=Abalance;
}

//Ctor 3 para.s
Account::Account(char AuserID[],string Apass,char Aname[],double Abalance)
{
    name=new char[strlen(name)+1];
    userID=new char[strlen(AuserID)+1];
    set(AuserID,Apass,Aname,Abalance);
}

//MAIN MENU
void mainMenu(Account** a)
{
    
    int n=0;
    char choice;
    while(1)
    {
        system("cls");
        cout<<"+========================================+"<<endl;
        cout<<"|         BANK ACCOUNT MANAGEMENT        |"<<endl;
        cout<<"+========================================+"<<endl;
        cout<<"| 1. Create default 2 Saving accounts    |"<<endl;
        cout<<"|    and 2 Checking account              |"<<endl;
        cout<<"| 2. Create Account                      |"<<endl;
        cout<<"| 3. Login                               |"<<endl;
        cout<<"| 4. View All                            |"<<endl;
        cout<<"| 5. Save your work to file: Accounts.txt|"<<endl;
        cout<<"| 0. Exit Program                        |"<<endl;
        cout<<"+----------------------------------------+"<<endl;
        cout<<"| Your seclection(0->3): ";
        fflush(stdin);
        cin>>choice;
        if(choice=='0') exit(0);
        switch(choice)
        {
        case '1':
            createDefault(a,n);
            break;
        case '2':
            createAnAccount(a,n);
            break;
        case '3':
            login(a,n);
            break;
        case '4':
            viewAll(a,n);
            break;
        case '5':
            saveDataToFile(a,"Account.txt",n);
            cout<<"| Successfully saved to Accounts.txt!"<<endl<<endl;
            break;
        default:
            cout<<"| Your selection must(0->2). Try again! "<<endl;
            break;
        }
        system("pause");
    }
}

//Create default
void createDefault(Account** a,int& n)
{
    if(n == 0)
    {
        a[n]=new SavingAccount;
            a[n++]->set("ducfilan","123456","Hoang Nghia Duc",9999);
        a[n]=new SavingAccount;
            a[n++]->set("clever_sheep","123456","Tran Trong Tien Dat",1000);
        a[n]=new CheckingAccount;
            a[n++]->set("anhcam_yb","123456","Vu Manh Cam",2000);
        a[n]=new CheckingAccount;
            a[n++]->set("l.daBest","123456","Nguyen Tung Lam",2500);
    }
    
    cout<<"|"<<endl<<"| Successfully created Accounts!"<<endl<<endl;
}

//Accept Account
char* acceptID()
{
    char* value;
    value=new char[50];
    do
    {
        cout<<"| Enter your user ID  : ";
        fflush(stdin);
        cin.getline(value,50);
        if(strlen(value)>15 || strlen(value)<1)
        {
            cout<<"| UserID's length is unaccepted. Try again!"<<endl;
            continue;
        }
        return value;
    }while(1);
}
//Accept Password
string acceptPW(char* x)
{
    string Apass;
    do
    {
        cout<<x;
        Apass=inputPassword(50);
        if(Apass.size()<6)
        {
            cout<<"| Password must contain at least 6 chars!"<<endl;
            continue;
        }
        return Apass;
    } while(1);
}

//Accept Pos
double acceptPos(char* x)
{
    double bTemp;
    bool Ok=false;
    do
    {
        cout<<x;
        cin>>bTemp;

        if(cin.fail())
        {
            cerr<<"| Invalid number! Try again!"<<endl;
            cin.clear();
            fflush(stdin);
        }
        else if(char(cin.get())!='\n')
        {
            cout<<"| Trailing characters! Try Again!"<<endl;
            fflush(stdin);
        }
        else if(bTemp<0)
        {
            cout<<"| The value must be positive!"<<endl;
            fflush(stdin);
        }else
            Ok=true;
    }while(!Ok);
    return bTemp;
}

//Create Accs
void createAnAccount(Account** a,int& n)
{
    system("cls");
    cout<<"+========================================+"<<endl;
    cout<<"|            [Account Register]          |"<<endl;
    cout<<"+========================================+"<<endl;
    char* AuserID,*Aname;
    string Apass,ApassConfirm;
    double Abalance;
    char choice;
    bool isOk=false;
    
    //Enter account name
    Aname=new char[50];
    do
    {
        cout<<"| Enter your name     : ";
        fflush(stdin);
        cin.getline(Aname,50);
        if (strlen(Aname)>30 || strlen(Aname)<2)
        {
            cout<<"| Account length is unaccepted! Try again!"<<endl;
            continue;
        }
        for(int i=0;i<strlen(Aname);i++)
            if(Aname[i]<' ' || (Aname[i]>' ' && Aname[i]<'A') || Aname[i]>'z')
            {
                isOk=false;
                cout<<"| Invalid name format. Try again!"<<endl;
                break;
            }else isOk=true;
    }while(!isOk);
    
    //Enter account ID
    AuserID=new char[16];
    do
    {
        AuserID=acceptID();
        //Check userID exist
    
        int k=0;
        for(int i=0;i<n;i++)
            if(strcmp(a[i]->getUserID(),AuserID)==0)
                k++;
        if(k!=0)
            cout<<"|\n| Account ID exist! Please try again!\n"<<endl;
        else break;
    }while(1);
    //Enter password
    isOk=false;
    do
    {
        Apass=acceptPW("| Enter Password      : ");
        ApassConfirm=acceptPW("| Confirm Password    : ");
        if(Apass==ApassConfirm) isOk=true;
        else cout<<"| Confirmation is not match!"<<endl;
    }while(!isOk);
    //Enter account balance
    Abalance=acceptPos("| Enter your balance  : ");

    //Enter account type
    cout<<"|\n"
        <<"+========================================+\n"
        <<"|        Choose your account type        |\n"
        <<"+========================================+\n"
        <<"| 1. Savings Account                     |\n"
        <<"| 2. Checking Account                    |\n"
        <<"+----------------------------------------+\n";
       
    do
    {
        cout<<"| Your seclection (0->2): ";
        fflush(stdin);
        cin>>choice;
             if(choice=='1') a[n++]=new SavingAccount(AuserID,Apass,Aname,Abalance,0,0,0);
        else if(choice=='2') a[n++]=new CheckingAccount(AuserID,Apass,Aname,Abalance,0,0);
        else
        {
            cout<<"| Invalid choice!"<<endl;
            continue;
        }
        cout<<"| Successful to create your account!"<<endl<<endl;
        break;
    }while(1);
}

//LOGIN
void login(Account** a,int& n)
{
    int i,choice,flag=0;
    char* acc;
    string pw;
    
    system("cls");
    cout<<"+========================================+"<<endl;
    cout<<"|                  [LOGIN]               |"<<endl;
    cout<<"+========================================+"<<endl;
    acc=new char[16];
    acc=acceptID();
    pw=acceptPW("| Enter Password      : ");
    for(i=0;i<n;i++)
    {
        if(strcmp(acc,a[i]->getUserID())==0 && (pw==a[i]->getPass()))
        {
            flag=1;
            cout<<"| Login Successfully!"<<endl<<endl;
            system("pause");
            break;
        }
    }
    if(flag==0)
    {
        cout<<"| Sorry. Invalid username or password!"<<endl<<endl;
        return;
    }
    a[i]->showMenu();
}

//VIEW BALANCE
void Account::viewBalance()
{
    cout<<"|"<<endl;
    cout<<"| Your name          : "<<getName()<<endl;
    cout<<"| User ID            : "<<getUserID()<<endl;
    cout<<"| Account balance    : "<<getBalance()<<endl;
}
//SAVE TO FILE
void saveDataToFile(Account** a,const char *filename,int& n)
{
    ofstream os(filename);
    
    os<<"+-----------------------------------------------------------------------------+\n";
    os<<"|      ID       |              NAME              |   BALANCE  |      TYPE     |\n";
    os<<"+-----------------------------------------------------------------------------+\n";
    for(int i=0;i<n;i++)
    {
        os<<"|"<<setw(15)<<left<<a[i]->getUserID()<<"|  "<<setw(30)<<left
        <<a[i]->getName()<<"|  "<<setw(10)<<left<<a[i]->getBalance()<<"|  ";
        if(a[i]->getType()==1)
            os<<setw(14)<<right<<"Saving |"<<endl;
        else os<<setw(14)<<right<<"Checking |"<<endl;
    }
    os<<"+-----------------------------------------------------------------------------+\n";
    os.close();
}

void viewAll(Account** a,int& n)
{
    system("cls");
    cout<<"+-----------------------------------------------------------------------------+\n";
    cout<<"|      ID       |              NAME              |   BALANCE  |      TYPE     |\n";
    cout<<"+-----------------------------------------------------------------------------+\n";
    for(int i=0;i<n;i++)
    {
        cout<<"|"<<setw(15)<<left<<a[i]->getUserID()<<"|  "<<setw(30)<<left
        <<a[i]->getName()<<"|  "<<setw(10)<<left<<a[i]->getBalance()<<"|  ";
        if(a[i]->getType()==1)
            cout<<setw(14)<<right<<"Saving |"<<endl;
        else cout<<setw(14)<<right<<"Checking |"<<endl;
    }
    cout<<"+-----------------------------------------------------------------------------+\n";
}

//PASSWORD - CODE THAM KHAO
string inputPassword(size_t length_max)
{
    string pass;
    char ch = 0;
    do
    {
        ch = getch();
        if((pass.size() < length_max) &&
           (::isalpha(ch) || ::isalnum(ch))) // Chi cho phep nhap ki tu và so
        {
            cout <<'*';
            pass.push_back(ch);
        }
        else if('\b' == ch && !pass.empty())
        {
            cout << "\b \b";
            pass.resize(pass.size() - 1);
        }
    } while ('\r' != ch);
    cout << endl;
    return pass;
}

//Get
char* Account::getName()
{
    return name;
}

char* Account::getUserID()
{
    return userID;
}

string Account::getPass()
{
    return pass;
}

double Account::getBalance()
{
    return balance;
}
