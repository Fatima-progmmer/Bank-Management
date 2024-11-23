#include<iostream>
#include<fstream>
#include<cstdlib>
#include<time.h>
#include<string>
#include<iomanip>

using namespace std;

 class temp
 {
 	private:
 		int choice ;
		fstream file,file1;
		int accNo;
		const int width=25;
		char name[25];
		char fname[25];
		char CNIC[25];
		char pho[25];
		char email[25];
		float amount;
		int newAmount;
	
	public:
		int search;
		void createAccount(void);
		void depositAmount(void);
		void withdrawAmount(void);
		void checkInfo(void);
 };
int main()
{
	temp obj;
	int choice;
	cout << "\n\n\n\t\t::: Royal Bank :::";
	cout << "\n\t\t :: 1.Create account ::" << endl;
	cout << "\n\t\t :: 2.Login account  :: " << endl;
	cout << "\n\t\t :: 3.exit           ::" << endl;
	cout << "\n\t\t :: ................ ::\n\t\t\t\t";
	cin >> choice ;
	switch(choice)
	{
		case 1:
			obj.createAccount();
		break;
		case 2:
			{
				cout << "Enter Your account number :";
				cin >> obj.search;
				
				while(1){
						cout << "\n\n\n\t\t::: Royal Bank :::";
						cout << "\n\t\t :: 1.Deposit Amount ::" << endl;
						cout << "\n\t\t :: 2.Withdraw Amount  :: " << endl;
						cout << "\n\t\t :: 3.exit           ::" << endl;
						cout << "\n\t\t :: ................ ::\n\t\t\t\t";
						}
					switch(choice)
					{
						case 1:
							obj.depositAmount();
						break;
						case 2:
							obj.withdrawAmount();
						case 3:
							return 0;
						break;
						default:
							cout << "Invalid choice..!";
					}
					system("pause");
					system("cls");
				}
			break;
			case 3:
				exit(0);
			break;
			default:
			   cout << "\n Invalid choice .. !" ;
			break;
			
	}
		return 0;
}
void temp::createAccount(){
	srand(time(0));
			accNo=rand()/10000+1;
	
			cout << "Enter Your name :";
			cin >> name;
	
			cout << "Enter Your Father name :";
			cin >> fname;
	
			cout << "Enter Your CNIC :";
			cin >> CNIC;
	
			cout << "Enter Your Mobile number :";
			cin >> pho;
	
			cout << "Enter Your Email Address :";
			cin >> email;
	
			cout << "Enter Your Amount:";
			cin >> amount;
	
			cout << accNo <<" This is your account number..." << endl;
			cout << "pleae save it !";
		
			file.open("data.txt",ios::out|ios::app);
			file <<"\n" <<accNo++ <<setw(width) <<name <<setw(width) << fname <<setw(width)<< CNIC <<setw(width) <<pho <<setw(width)<<email <<setw(width) <<amount <<endl;
			file.close();
}
void temp::depositAmount(){
	cout<< "Enter amount to deposit :";
				cin >> newAmount;
				file.open("data.txt",ios::in);
				file1.open("data1.txt",ios::out|ios::app);
				file >> accNo >> name >> fname >> CNIC >> pho >> email >> amount ;
				while(!file.eof())
				{
				if(accNo==search)
				{
				cout << "\nCurrent amount " << amount ;
				amount =amount + newAmount ;
				cout << "\nUpdated amount " << amount ;
				file1 <<"\n" <<accNo++ <<setw(width) <<name <<setw(width) << fname <<setw(width)<< CNIC <<setw(width) <<pho <<setw(width)<<email <<setw(width) <<amount <<endl;
				}
				else
				{
				file1 <<"\n" <<accNo++ <<setw(width) <<name <<setw(width) << fname <<setw(width)<< CNIC <<setw(width) <<pho <<setw(width)<<email <<setw(width) <<amount <<endl;
				}
				file <<"\n" <<accNo++ <<setw(width) <<name <<setw(width) << fname <<setw(width)<< CNIC <<setw(width) <<pho <<setw(width)<<email <<setw(width) <<amount <<endl;
				}
				file.close();
				file1.close();
				remove("data.txt");
				remove("data1.txt","data.txt");
}
void temp::withdrawAmount(){
	cout<< "Enter amount to withdraw :";
				cin >> newAmount;
				file.open("data.txt",ios::in);
				file1.open("data1.txt",ios::out|ios::app);
				file >> accNo >> name >> fname >> CNIC >> pho >> email >> amount ;
				while(!file.eof())
				{
				if(accNo==search)
				{
				cout << "\nCurrent amount " << amount ;
				amount =amount - newAmount ;
				cout << "\nUpdated amount " << amount ;
				file1 <<"\n" <<accNo++ <<setw(width) <<name <<setw(width) << fname <<setw(width)<< CNIC <<setw(width) <<pho <<setw(width)<<email <<setw(width) <<amount <<endl;
				}
				else
				{
				file1 <<"\n" <<accNo++ <<setw(width) <<name <<setw(width) << fname <<setw(width)<< CNIC <<setw(width) <<pho <<setw(width)<<email <<setw(width) <<amount <<endl;
				}
				file <<"\n" <<accNo++ <<setw(width) <<name <<setw(width) << fname <<setw(width)<< CNIC <<setw(width) <<pho <<setw(width)<<email <<setw(width) <<amount <<endl;
				}
				file.close();
				file1.close();
				remove("data.txt");
				remove("data1.txt","data.txt");
}
