#include <iostream>
#include <string>
#include<iomanip>
#include<fstream>
#include"clerk.h"
#include<conio.h>
using namespace std;
void ExtraClerk();
void enterCustomer();
void selectSimulate();
void chooseInput();
void statistics(string filename);
void readFile(string fileName);
void setCustomerData(clerk &c);
void SetData_to_file(clerk&c);
void draw_Tobank();
void draw_Simulation();
void draw_welcome();
void writeToFile(string filename,clerk & cl);
template<typename T> void printElement(T t,int width);
void printData(clerk &c);
void max_finish(int x);
bool extra_Clerk_Withdraw=false;
bool extra_Clerk_Deposit=false;
bool extra_Clerk_Transfer=false;
bool SimulateFlag=false;
int number_of_customers=0;
int finish_all_service=0;
int Average_waiting_time=0;

int Simulate_time=0;


clerk c_withdraw1("WithDraw",10,1)
	,c_withdraw2("WithDraw",10,2)
	,c_deposit1("Deposit",5,1)
	,c_deposit2("Deposit",5,2)
	,c_transfer1("Transfer",7,1)
	,c_transfer2("Transfer",7,2);

int main()
{
	remove("output_withdraw_clerk1.txt");
	remove("output_withdraw_clerk2.txt");
	remove("output_Deposit_clerk1.txt");
	remove("output_Deposit_clerk2.txt");
	remove("output_transfer_clerk1.txt");
	remove("output_transfer_clerk2.txt");
	draw_Tobank();
	draw_Simulation();
	cout<<"press any key to enter "<<endl;
	getch();
	system("CLS");
	chooseInput();
	SetData_to_file(c_withdraw1);
	writeToFile("output_withdraw_clerk1.txt",c_withdraw1);
	SetData_to_file(c_deposit1);
	writeToFile("output_Deposit_clerk1.txt",c_deposit1);
	SetData_to_file(c_transfer1);
	writeToFile("output_transfer_clerk1.txt",c_transfer1);
	
	if(extra_Clerk_Withdraw)
	{
	SetData_to_file(c_withdraw2);
	writeToFile("output_withdraw_clerk2.txt",c_withdraw2);
	}
	if(extra_Clerk_Deposit)
	{
	SetData_to_file(c_deposit2);
	writeToFile("output_deposit_clerk2.txt",c_deposit2);
	}
	if(extra_Clerk_Transfer)
	{
	SetData_to_file(c_transfer2);
	writeToFile("output_transfer_clerk2.txt",c_transfer2);
	}
	statistics("General Statisitcs.txt");
	selectSimulate();
	
	
	return 0;
}

void ExtraClerk()
{
	string x1,x2,x3;
	cout<<"Enter 'y' for yes and 'n' for no\n";
	
		do{
	cout<<"\nDo you want to add extra clerk for service withdraw? ";
	cin>>x1;
		}
	while(x1!="y"&& x1!="n");
	do{
		cout<<"\nDo you want to add extra clerk for service deposit? ";
		cin>>x2;
	}

	while(x2!="y"&& x2!="n");
	do{
		cout<<"\nDo you want to add extra clerk for service transfer? ";
		cin>>x3;
	}
	while(x3!="y"&& x3!="n");
		cout<<endl;
	if(x1=="y")
		 extra_Clerk_Withdraw=true;
	if(x2=="y")
		 extra_Clerk_Deposit=true;
	if(x3=="y")
		 extra_Clerk_Transfer=true;
	system("CLS"); //clear the screen

}

void enterCustomer ()
{
	int id=1;
	string input;
	int toggle_withdraw=1;
	int toggle_Deposit=1;
	int toggle_transfer=1;

	do{
		do{
		
		cout<<"Choose service for customer with ID "<<id<<":"<<endl;
		cout<<"1-Withdraw Service"<<endl;
		cout<<"2-Deposit Service"<<endl;
		cout<<"3-Transfer Service"<<endl;
		if(id!=1)
			cout<<"Enter'q' to finish adding customers"<<endl;
		cin>>input;
		system("CLS");
		}
		while(input!="1" && input!="2" && input!="3" && input!="q");

		
		if(input=="1")
		{
			if(extra_Clerk_Withdraw==true)
			{
				if(toggle_withdraw)
				{
				customer c1(id);
				c_withdraw1.AddCustomer(c1);
				toggle_withdraw=1-toggle_withdraw;
				}
				else
				{
					customer c1(id);
				c_withdraw2.AddCustomer(c1);
				toggle_withdraw=1-toggle_withdraw;
				}

			}
			else
			{
				customer c1(id);
				c_withdraw1.AddCustomer(c1);
			}
		}

		else if(input=="2")
		{
			if(extra_Clerk_Deposit==true)
			{
				if(toggle_Deposit)
				{
				customer c1(id);
				c_deposit1.AddCustomer(c1);
				toggle_Deposit=1-toggle_Deposit;
				}
				else
				{
					customer c1(id);
				c_deposit2.AddCustomer(c1);
				toggle_Deposit=1-toggle_Deposit;
				}
			}
			else
			{
				customer c1(id);
				c_deposit1.AddCustomer(c1);
			}
		}

		else if(input=="3")
		{
			if(extra_Clerk_Transfer==true)
			{
				if(toggle_transfer)
				{
				customer c1(id);
				c_transfer1.AddCustomer(c1);
				toggle_transfer=1-toggle_transfer;
				}
				else
				{
					customer c1(id);
				c_transfer2.AddCustomer(c1);
				toggle_transfer=1-toggle_transfer;
				}
			}
			else
			{
				customer c1(id);
				c_transfer1.AddCustomer(c1);
			}
		}
		id++;

		system("CLS");
	}while(input!="q");

}

void selectSimulate()
{
	string select;
	do
	{
		do
		{
			cout<<"                                  SIMULATION "<<endl<<endl;
			cout<<"Which service do you want to simulate : "<<endl;
			cout<<"1-Withdraw Service"<<endl;
			cout<<"2-Deposit Service"<<endl;
			cout<<"3-Transfer Service"<<endl;
			cout<<"Enter'q' to finish simulation"<<endl;
			cin>>select;
		system("CLS");
		}
		while(select!="1" && select!="2" && select!="3" && select!="q");

		if(select=="1")
		{
			if(extra_Clerk_Withdraw)
			{

				printData(c_withdraw1);
				printData(c_withdraw2);
			}
			else
				printData(c_withdraw1);
		}
		else if(select=="2")
		{
				if(extra_Clerk_Deposit)
			{
				printData(c_deposit1);
				printData(c_deposit2);
			}
			else
				printData(c_deposit1);
		}
		else if (select=="3")
		{
				if(extra_Clerk_Transfer)
			{
				printData(c_transfer1);
				printData(c_transfer2);
			}
			else
				printData(c_transfer1);
		}

	}

	while(select!="q");


}
void chooseInput()
{string x1;
	
	do{	
	draw_welcome();
	cout<<"Choose input type \n";
	cout<<"1)from file\n";
	cout<<"2)Enter the data in the console\n";
	cin>>x1;
	if(x1=="1")
	{
		system("CLS");
		readFile("input.txt");
	}
	else if(x1=="2")
	{
		system("CLS");
		ExtraClerk();
		enterCustomer ();
	}
		system("CLS");
	}while(x1!="1" && x1!="2");


}
void printData(clerk &c)
{
	
	int x=c.getQueueSize();

	do{
		cout<<c.getService()<<" "<<"Clerk "<<c.getID()<<endl<<endl;
		printElement("ID",6);
		printElement("State",10);
		printElement("Waiting Time",15);
		printElement("Finishing Time",17);
		printElement("Ticket",9);
		printElement("Turn",7);
		cout<<endl;
		for(int i=0;i<c.getQueueSize();i++)
		{
			customer c1=c.removeCustomer();
			printElement(c1.getID(),6);
			printElement(c1.getState(),10);
			printElement(c1.getWaitTime(),15);
			printElement(c1.getFinishingTime(),17);
			printElement(c1.getTicket(),9);
			printElement(c1.getTurn(),7);
			cout<<endl;
			if(c1.getTurn()!=-1)
			c1.setTurn(c1.getTurn()-1);
			switch(c1.getTurn())
			{
				case -1:c1.setState("served");break;
				case 0:c1.setState("serving");break;
				default:c1.setState("waiting");break;
			}
			c.AddCustomer(c1);
		}
		cout<<"Press any key for next customer ";
		getch();
		system("CLS");
	
		x--;
		if(x<0)
			break;
		}while(true);
	
	setCustomerData(c);
}
void setCustomerData(clerk &c)
{
	int f=0;
	int sum=0;
	for(int i=0;i<c.getQueueSize();i++)
	{
		
	customer c1=c.removeCustomer();
	if(i==0)
		c1.setState("serving");
	else
		c1.setState("waiting");
	c1.setWaitTime(i*c.getTime());
	c1.setFinishingTime(c1.getWaitTime()+c.getTime());
	c1.setTicket(i);
	c1.setTurn(i);
	sum+=c1.getWaitTime();
	c.setTotalWaiting(sum);
	f=c1.getFinishingTime();
		max_finish(f);
	c.AddCustomer(c1);
	}

		
}
template<typename T> void printElement(T t,int width)
{
	cout<<left<<setw(width)<<setfill(' ')<<t;
}
void readFile(string fileName)
{
	int toggle_withdraw=1;
	int toggle_Deposit=1;
	int toggle_transfer=1;
	int id=1;
	ifstream infile;
	infile.open(fileName);
	
	bool addClerk=false;
	bool clerkW=false;
	bool clerkD=false;
	bool clerkT=false;

	string line;
	getline(infile,line);
	if(line=="Add Clerk"||line=="add clerk"||line=="Add clerk"||line=="add Clerk")
	{
		addClerk=true;
		string clerk;
		
		while(true)
		{
			getline(infile,clerk);
			if(clerk=="")
				continue;
			if(clerk=="withdraw"||clerk=="Withdraw")
				clerkW=true;
			else if(clerk=="deposit"||clerk=="Deposit")
				clerkD=true;
			else if(clerk=="transfer"||clerk=="Transfer")
				clerkT=true;
			else if(clerk=="add customer"||clerk=="Add Customer"||clerk=="Add customer")
				break;
			else
			{
				cout<<"Error.Cannot read from file";
				break;
			}
		}
	}
	string cu;
	while(true)
	{
		getline(infile,cu);
		if(cu=="")
			continue;
		if(cu=="withdraw"||cu=="Withdraw")
		{

			if(addClerk&&clerkW)
			{
				extra_Clerk_Withdraw=true;
					if(toggle_withdraw)
				{
				customer c1(id);
				c_withdraw1.AddCustomer(c1);
				toggle_withdraw=1-toggle_withdraw;
				}
				else
				{
					customer c1(id);
				c_withdraw2.AddCustomer(c1);
				toggle_withdraw=1-toggle_withdraw;
				}
			}
			else
				{
					customer c1(id);
					c_withdraw1.AddCustomer(c1);
				}
		}
		else if(cu=="deposit"||cu=="Deposit")
		{
			if(addClerk&&clerkD)
			{
				extra_Clerk_Deposit=true;
				if(toggle_Deposit)
				{
				customer c1(id);
				c_deposit1.AddCustomer(c1);
				toggle_Deposit=1-toggle_Deposit;
				}
				else
				{
				customer c1(id);
				c_deposit2.AddCustomer(c1);
				toggle_Deposit=1-toggle_Deposit;
				}
				
			}
			else
			{
				customer c1(id);
				c_deposit1.AddCustomer(c1);
			}
		}
		else if(cu=="transfer"||cu=="Transfer")
		{
			if(addClerk&&clerkT)
			{
				extra_Clerk_Transfer=true;
		
				if(toggle_transfer)
				{
				customer c1(id);
				c_transfer1.AddCustomer(c1);
				toggle_transfer=1-toggle_transfer;
				}
				else
				{
					customer c1(id);
				c_transfer2.AddCustomer(c1);
				toggle_transfer=1-toggle_transfer;
				}
			}
			
			else
			{
				customer c1(id);
				c_transfer1.AddCustomer(c1);
			}
		}
		else if(cu=="end")
				break;
		else
		{
			cout<<"Error.Cannot read from file";
			break;
		}
		id++;
	} 
	while(!infile.eof())
	{
	string sim;
	infile>>sim;
	if(sim=="simulate")
		infile>>Simulate_time;
	}
}

void writeToFile(string filename,clerk &c)
{
	ofstream outfile;
	outfile.open(filename);
	outfile<<c.getService()<<" "<<"clerk "<<c.getID()<<endl<<endl;
	outfile<<left<<setw(7)<<setfill(' ')<<"ID";
	outfile<<left<<setw(10)<<setfill(' ')<<"State";
	outfile<<left<<setw(17)<<setfill(' ')<<"Waiting Time";
	outfile<<left<<setw(16)<<setfill(' ')<<"Finish Time";
	outfile<<left<<setw(11)<<setfill(' ')<<"Ticket";
	outfile<<left<<setw(7)<<setfill(' ')<<"Turn";
	outfile<<endl;
	outfile<<"--------------------------------------------------------------------"<<endl;
	for(int i=0;i<c.getQueueSize();i++)
	{
	customer c1=c.removeCustomer();
	outfile<<left<<setw(7)<<setfill(' ')<<c1.getID();
	outfile<<left<<setw(10)<<setfill(' ')<<c1.getState();
	outfile<<left<<setw(17)<<setfill(' ')<<c1.getWaitTime();
	outfile<<left<<setw(16)<<setfill(' ')<<c1.getFinishingTime();
	outfile<<left<<setw(11)<<setfill(' ')<<c1.getTicket();
	outfile<<left<<setw(7)<<setfill(' ')<<c1.getTurn();
	outfile<<endl;
	c.AddCustomer(c1);
	}
	
	setCustomerData(c);
}

void SetData_to_file(clerk&c)
{
	int k=Simulate_time/(c.getTime());
	for(int i=0;i<c.getQueueSize();i++)
	{
		customer c1=c.removeCustomer();
		if(i<k)
		{
			c1.setState("served");
			c1.setTurn(-1);
		}
		else if(i==k)
		{
			c1.setState("serving");
			c1.setTurn(0);
		}
		else
		{
			c1.setState("waiting");
			c1.setTurn(i-k);
		}
	c1.setWaitTime(i*c.getTime());
	c1.setFinishingTime(c1.getWaitTime()+c.getTime());
	c1.setTicket(i);
	c.AddCustomer(c1);
	}
}
void draw_Tobank()
{
	cout<<"                    0000000    0000    000    00  00   00  "<<endl;
	cout<<"                    00   00  00    00  0000   00  00 00    "<<endl;
	cout<<"                    000000   00 00 00  00 00  00  0000     "<<endl;
	cout<<"                    00   00  00    00  00  00 00  00 00    "<<endl;
	cout<<"                    0000000  00    00  00   0000  00   00  "<<endl<<endl<<endl;
   
}
void draw_Simulation()
{
	cout<<"  00000   0  0    0  0   0  0        0000     000000    0    00000    00   0"<<endl;
	cout<<" 00      00  00  00  0   0  0      00    00     00     00  00     00  00   0"<<endl;
	cout<<" 00000   00  0 00 0  0   0  0      00 00 00     00     00  00     00  0 0  0"<<endl;
	cout<<"    00   00  0    0  0   0  0      00    00     00     00  00     00  0  0 0"<<endl;
	cout<<"00000    00  0    0  00000  000000 00    00     00     00    00000    0   00"<<endl<<endl<<endl;
   
}
void draw_welcome()
{
	cout<<"      00      00  000000   00       0000000    00000     00    00  000000  "<<endl;
	cout<<"      00  00  00  00       00       00       00     00   000  000  00      "<<endl;
	cout<<"      00  00  00  0000     00       00       00     00   00 00 00  0000    "<<endl;
	cout<<"      00  00  00  00       00       00       00     00   00    00  00      "<<endl;
	cout<<"       000  000   000000   0000000  0000000    00000     00    00  000000  "<<endl<<endl<<endl;
   
}


void max_finish(int x)
{
	if(x>=finish_all_service)
		finish_all_service=x;
}
void statistics(string filename)
{
	ofstream outfile;
	outfile.open(filename);

	number_of_customers=c_withdraw1.getQueueSize()+c_withdraw2.getQueueSize()+c_deposit1.getQueueSize()
						+c_deposit2.getQueueSize()+c_transfer1.getQueueSize()+c_transfer2.getQueueSize();
	outfile<<"General Statistics : "<<endl;
	outfile<<"-------------------------"<<endl<<endl;
	outfile<<"Total number of customers entered the bank : " <<number_of_customers<<" customers."<<endl<<endl;
	outfile<<"Average waiting time of withdraw service :"<<endl;
	if(c_withdraw1.getQueueSize()!=0)
	outfile<<"  clerk 1 = "<<c_withdraw1.getTotalWaiting()/c_withdraw1.getQueueSize()<<" mins."<<endl;
	else
		outfile<<"  clerk 1 = 0 mins."<<endl;

	if(extra_Clerk_Withdraw && c_withdraw2.getQueueSize()!=0)
	outfile<<"  clerk 2 = " <<c_withdraw2.getTotalWaiting()/c_withdraw2.getQueueSize()<<" mins."<<endl;
	else if(c_withdraw2.getQueueSize()==0)
		outfile<<"  clerk 2 = 0 mins."<<endl;
	outfile<<endl;

	outfile<<"Average waiting time of deposit service :"<<endl;
	if(c_deposit1.getQueueSize()!=0)
	outfile<<"  clerk 1 = "<<c_deposit1.getTotalWaiting()/c_deposit1.getQueueSize()<<" mins."<<endl;
	else
		outfile<<"  clerk 1 = 0 mins."<<endl;
	if(extra_Clerk_Deposit &&c_deposit2.getQueueSize()!=0)
	outfile<<"  clerk 2 = " <<c_deposit2.getTotalWaiting()/c_deposit2.getQueueSize()<<" mins."<<endl;
	else if (c_deposit2.getQueueSize()==0)
		outfile<<"  clerk 2 = 0 mins."<<endl;
		outfile<<endl;
	outfile<<"Average waiting time of transfer service :"<<endl;
	if(c_transfer1.getQueueSize()!=0)
	outfile<<"  clerk 1 = " <<c_transfer1.getTotalWaiting()/c_transfer1.getQueueSize()<<" mins."<<endl;
	else
		outfile<<"  clerk 1 = 0 mins."<<endl;
	if(extra_Clerk_Transfer&&c_transfer2.getQueueSize()!=0)
	outfile<<"  clerk 2 = " <<c_transfer2.getTotalWaiting()/c_transfer2.getQueueSize()<<" mins."<<endl;
	else if (c_transfer2.getQueueSize()==0)
		outfile<<"  clerk 2= 0 mins."<<endl;
		outfile<<endl;
	outfile<<"Percentage of customers in : "<<endl;
	outfile<<" 1.Withdraw service  = "<<(((c_withdraw1.getQueueSize()+c_withdraw2.getQueueSize())*1.0)/number_of_customers)*100.0<<"%"<<endl;
	outfile<<" 2.Deposit service   = "<<(((c_deposit1.getQueueSize()+c_deposit2.getQueueSize())*1.0)/number_of_customers)*100.0<<"%"<<endl;
	outfile<<" 3.Transfer service  = "<<(((c_transfer1.getQueueSize()+c_transfer2.getQueueSize())*1.0)/number_of_customers)*100.0<<"%"<<endl;
	outfile<<endl;
	outfile<<"Expected finishing time to finish all services = "<<finish_all_service <<" mins."<<endl;
}