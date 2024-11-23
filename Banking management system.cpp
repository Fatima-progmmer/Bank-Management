#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

class account_query{
	private:
		char accNO[20];
		char fname[10];
		char lname[10];
		float total_balance;
	public:
		void read_data();
		void show_data();
		void write_rec();
		void read_rec();
		void search_rec();
		void edit_rec();
		void del_rec();
};
void account_query::read_data(){
	cout << "\nEnter Account Number :";
	cin >> accNO;
	cout <<"Enter first name :";
	cin >> fname;
	cout <<"Enter last name: ";
	cin >>lname;
	cout << "Enter balance :";
	cin >> total_balance;
	cout << endl;
}
void account_query::show_data(){
	cout << "Account Number :" << accNO <<endl;
	cout << "First name :" << fname << endl;
	cout << "Last name :" << lname << endl;
	cout << "Current Balance :Rs. " << total_balance << endl;
	cout << "---------------------------------" << endl;
}
void account_query::write_rec(){
	ofstream outline;
	outfile.open("record.bank",ios::binary|ios::app);
	read_data();
	outfile.write(reinterpret_cast<char*>(this),sizeof(*this));
	outfile.close();
	
}
void account_query::read_rec(){
	ifstream infile;
	infile.open("record.bank",ios::binary);
	if(!infile)
	{
		cout << "Error in Opening" << endl;
		return;
	}
	cout << "\n****Data from file****" << endl;
	while(!infile.eof())
	{
		if(infile.read(reinterpert_cast<char*>(this),sizeof(*this))>0)
		{
			show_data();
		}
	}
	infile.close();
}
void account_query::search_rec(){
	int n;
	ifstream infile;
	infile.open("record.bank",ios::binary);
	if(!infile)
	{
		cout << "Error is opening" << endl;
		return;
	}
	infile.seekg(0,ios::end);
	int count=infile.tellg()/sizeof(*this);
	cout << "\nThere are " << count << " record in the file ";
	cout << "\nEnter Record Number to Search :";
	cin >> n;
	infile.seekg((n-1)*sizeof(*this));
	infile.read(reinterpret_cast<char*>(this),sizeof(*this));
	show_data();
}
void account_query::edit_rec(){
	int n;
	fstream iofile;
	iofile.open("record.bank",ios::in|ios::binary);
	if(!iofile)
	{
		cout << "Error in opening" << endl;
		return;
	}
	iofile.seekg(0,ios::end);
	int count =iofile.tellg()/sizeof(*this);
	cout << "\nThere are " << count << " record in the file";
	cout << "\nEnter Record number to edit :";
	cin >> n;
	iofile.seekg(n-1)*sizeof(*this);
	iofile.read(reinterpret_cast<char*>(this),sizeof(*this));
	cout << "Record " << n << " has following data" << endl;
	show_data();
	iofile.close();
	iofile.open("record.bank",ios::out|ios::Init|ios::binary);
	iofile.seekp((n-1)*sizeof(*this));
	cout << "\nEnter data to Modify " << endl;
	read_data();
	iofile.write(reinterpret_cast<char*>(this),sizeof(*this));
	
	}
void account_quert::delete_rec(){
	int n;
	ifstream infile;
	infile.open("record.bank",ios::binary);
	if(!infile)
	{
		cout << "Error in Opening" << endl;
		return;
	}
	infile.seekg(0,io::end);
	int count=infile.tellg()/sizeOf(*this);
	cout << "\nThere are " << count << " record in the file";
	cout << "\nEnter Record Number to Delete:";
	cin >> n;
	fstream tmpfile;
	tmpfile.open("tmpfile.bank",ios::out|ios::binary);
	infile.seekg(0);
	for(int i=0;i<count;i++)
	{
		infile.read(reinterpret_cast<char*>(this),sizeof(*this));
		if(i==(n-1))
		continue;
		tmpfile.write(reinterpret_cast<char*>(this),sizeof(*this));
	}
	infile.close();
	tmpfile.close();
	remove("record.bank")
	rename("tmpfile.bank","record.bank");
}
int main()
{
	account_query A;
	int choice;
	cout << "***Account Information system***" << endl;
	while(true)
	{
		cout<< "Select one option Below" << endl;
		cout << "\t1->Add record to file " << endl;
		cout << "\t2->Show record from file" << endl;
		cout <<"\t3->Search record from file " << endl;
		cout << "\t4->Update Record" << endl;
		cout << "\t5->Delete Record" << endl;
		cout << "\t6->Quit" << endl;
		cout << "\nEnter your choice :";
		cin >> choice;
		switch(choice)
		{
			case 1:
				A.write_rec();
				break;
			case 2:
				A.read_data();
				break;
			case 3:
				A.search_rec();
				break;
			case 4:
				A.edit_rec();
				break;
			case 5:
				A.del_rec();
				break;
			case 6:
				exit(0);
				break;
			default:
				cout << "\nEnter correct choice :";
				exit(0);
		}
	}
	system("pause");
	return 0;
}

