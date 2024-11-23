#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

class bank{
	private:
		char name[100],address[100],y;
		float balance,deposit,withdraw;
	public:
		void open_account();
		void deposit_money();
		void withdraw_money();
		void display_account();
		
};

void bank::open_account(){
	cout << "Enter your name :";
	cin.clear();
	cin.getline(name,100);
	cout << "Enter your address :";
	cin.ignore();
	cin.getline(address,100);
	cout << "Which type of account :" <<endl;
	cout << "For saving (a) \n For current (c):" ;
	cin >> y;
	cout << "Enter amount for deposit :";
		cin >> balance;
		cout << "Your account is created"<< endl;
	
}
void bank::deposit_money(){
	cout << "How much you deposit :" ;
	cin >> deposit;
	balance +=deposit;
	cout << "Total balance is " << balance << endl;
}
void bank::display_account(){
	cout << "Your full name is " << name << endl;
	cout << "Your address is " << address << endl;
	cout << "Your account type " << y << endl;
	cout << "Your balance is " << balance << endl;
}
void bank::withdraw_money(){
	cout << "\n Withdraw " << endl;
	cout << "Enter amount to withdraw :";
	cin >> withdraw ;
	balance-=withdraw;
	cout << "Your balance is now " << balance << endl;
}
int main()
{
	bank obj;
	int choice;
	char x;
	do
	{
	system("cls");
	cout <<"\n\n\n"<<endl;
	cout <<"1.Open Account" << endl;
	cout <<"2.Deposite Account " << endl;
	cout <<"3.withdraw money" << endl;
	cout <<"4.Display account" << endl;
	cout <<"0.exit" << endl;
	cout << "Enter your choice" << endl;
	cin >> choice;
	switch(choice)
	{
		case 1:
			cout << "\nOpen account " << endl;
			obj.open_account();
			break;
		case 2 :
			cout << "\nDeposit Account " << endl;
			obj.deposit_money();
			break;
		case 3:
			cout << "\nWithdraw Money" << endl;
			obj.withdraw_money();
			break;
		case 4:
			cout <<"\nDisplay account " << endl;
			obj.display_account();
			break;
		case 0:
			cout << "\nExiting...." << endl;
			exit(0);
			break;
		default:
			cout << "\nInvalid...." << endl;
	}
	cout << "\nDo you want other option(y/n)";
	cin >> x;
	}
	while(x=='Y'||x=='y');
	return 0;
}

