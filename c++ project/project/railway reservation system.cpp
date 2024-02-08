#include<bits/stdc++.h>

#include <iostream>
#include <fstream>
#include <cstring> // Include <cstring> for strcpy and other string functions
#include <cstdlib> // Include <cstdlib> for the declaration of getpass
#include <unistd.h>


using namespace std;

void manage();
void can();  						// for cancellation
void cancell();						 // cancelling tickets
void user(); 						// user menu
void database(); 					// database for details
void res(); 						// reservation?
void reserve();						 // reserving tickets
void displaypassdetail(); 			// displaying ticket details
void enquiry();						 // If user wants to enquire about the details

char f[10]="f", s[10]="s";
int addr,ad,flag,f1,d,m,i,amt;
float tamt;



// Class for the train details
class train_details  
{
     public:
          int train_no,c1_seats,c2_seats,c1_fare,c2_fare,day,month,year;
          char t_name[100],start[100],destination[100];
          void gettraindetails()
          {
               cout<<"\n\nEnter the train details: ";
               cout<<"\nEnter train no.: ";
               cin>>train_no;
               cout<<"\nEnter train name: ";
               cin>>t_name;
               cout<<"\nEnter date: ";
               cin>>day>>month>>year;
               cout<<"\nEnter staring point: ";
               cin>>start;
               cout<<"\nEnter destination: ";
               cin>>destination;
               cout<<"\nFor first class: \nEnter no. of seats and fare for each seat: ";
               cin>>c1_seats>>c1_fare;
               cout<<"\nFor second class: \nEnter no. of seats and fare for each seat: ";
               cin>>c2_seats>>c2_fare;
          }

          void displaytraindetails()
          {
               cout<<"\n\nTrain details: "<<"\nTrain no.: "<<train_no<<"\nTrain name: "<<t_name<<"\nDate: "<<day<<"/"<<month<<"/"<<year;
               cout<<"\nStarting point: "<<start<<"\nDestination: "<<destination;
               cout<<"\nFor first class: \nNo. of seats: "<<c1_seats<<"\nFare: "<<c1_fare;
               cout<<"\nFor second class: \nNo. of seats: "<<c2_seats<<"\nFare: "<<c2_fare;
          }
};


 // Reservation class
class reservation
{
     public: 
          int pnr,tno,age[7],noseats,dd,mm,yy,fare;
          char tname[100],boarding[100],destiny[100],name[7][100],c[10];
          
          void getreservationdetails()
          {
               cout<<"\nEnter your journey details: ";
               cout<<"\nEnter train no.: ";
               cin>>tno;
               cout<<"\nEnter train name: ";
               cin>>tname;
               cout<<"\nEnter boarding point: ";
               cin>>boarding;
               cout<<"\nEnter destination: ";
               cin>>destiny;
               cout<<"\nEnter date of travel: ";
               cin>>dd>>mm>>yy;
               cout<<"\nEnter class: ";
               cin>>c;
               cout<<"\nEnter no. of seats: ";
               cin>>noseats;
               while(noseats>7)
               {
                    cout<<"\nSorry you can book 7 tickets at a time\nRe-enter no. of seats: ";
                    cin>>noseats;
               }
               for(int i=0;i<noseats;i++)
               {
                    cout<<"\nEnter name of passanger: ";
                    cin>>name[i];
                    cout<<"\nEnter age: ";
                    cin>>age[i];
               }
          }

          void displayreservationdetails()
          {
               cout<<"\nYour booking details: ";
               cout<<"PNR no.: "<<pnr;
               cout<<"\nTrain no.: "<<tno;
               cout<<"\nTrain name: "<<tname;
               cout<<"\nBoarding points: "<<boarding;
               cout<<"\nDestiny: "<<destiny;
               cout<<"\nDate of travel: "<<dd<<"/"<<mm<<"/"<<yy;
               cout<<"\nClass: "<<c;
               cout<<"\nNo. of seats preserved: "<<noseats;
               for(int i=0;i<noseats;i++)
               {
                    cout<<"\nName of passanger: "<<name[i];
                    cout<<"\nAge: "<<age[i];
               }
               cout<<"\nAmount to be paid: "<<fare;

          }
};


// ticket cancellation class
class cancel 
{
     public:
          int pnr,tno,noseats,dd,mm,yy,fare,age[7];
          char tname[100],boarding[100],destiny[100],name[7][100],c[10];

          void getcancel()
          {
               cout<<"\nEnter pnr no.: ";
               cin>>pnr;
          }

          void displaycancel()
          {
               cout<<"\nPNR no.: "<<pnr;
               cout<<"\nTrain no.: "<<tno;
               cout<<"\nTrain name: "<<tname;
               cout<<"\nBoarding points: "<<boarding;
               cout<<"\nDestiny: "<<destiny;
               cout<<"\nDate of travel: "<<dd<<"/"<<mm<<"/"<<yy;
               cout<<"\nClass: "<<c;
               cout<<"\nNo. of seats cancelled: "<<noseats;
               for(int i=0;i<noseats;i++)
               {
                    cout<<"\nName of passanger: "<<name[i];
                    cout<<"\nAge: "<<age[i];
               }
               cout<<"\nMoney to be refunded: "<<fare;
          }
};



//  Login class
class user_login  
{
     public:
char id[100], *password, pass[100];

void getlogindetail()
{
	cout << "\nEnter your id:";
	cin >> id;
	cout << "\nEnter your password: ";
	password = getpass("Enter the password:");
	cout << "\n";
	strcpy(pass, password);
}

void displaylogindetail()
{
	cout << "\nUser ID:" << id << "\t" << "\nPassword" << pass << "\n\n";
}
};



// driver function
int main()
{
    cout<<"\n\t\t\t Welcome to the Railway Reservation Site!!!  ";
    do
    {
          cout<<"\n MAIN MENU: \n";
          cout<<"\n1.Admin mode \n2.User mode \n3.Exit"<<endl<<endl;
          cout<< "Choice: ";
          
          int ch;   cin>>ch;
          switch(ch)
          {
               case 1: database();
                         break;

               case 2: user();
                         break;
               
               case 3: exit(0);
          
               default: cout<<"\n Invalid choice!! Please check your input and try again "; break;
          }
    }while(1);
     
return 0;
}


// DEFINITION OF MEMBER FUNCTIONS OF THE PROJECT


//1. DATABASE FUNCTION
void database()   // For handling, adding, displaying and storing user details
{
	 // Include the <cstring> header for the getpass() function

	char *password;
	const char *pass = "uts";
	password = getpass("Admininistrator password:");

	train_details a;
	fstream f;
	int ch;
	char c;

	if (strcmp(pass, password) != 0)
	{
		cout << "WRONG PASSWORD!! \n"
			 << endl
			 << endl;
		return;
	}
	
	if(strcmp(pass,password)==0)
	{
		char c;
		do
			{
				cout<<"\t\t\t\t ADMINISTRATOR MENU  \n";
				cout<<"1. Create data base \n 2. Add new details\n"<<"3. Display details \n 4. User \n";
				cout<<"5. Display passenger details \n 6. Return to main menu\n"<<"Enter your choice: "; 
				cin>>ch;
				
				switch(ch)
				{
					case 1:
						f.open("t.txt",ios::out|ios::binary);
						do
						{
						a.gettraindetails();
						f.write((char *) & a,sizeof(a));
						cout<<" To add one more record\n";
						cout<<"Y-for Yes\n N-for No\n";
						cin>>c;
						}while(c=='y');
						f.close();
					break;
					
					case 2:
						f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
						a.gettraindetails();
						f.write((char *) & a,sizeof(a));
						f.close();
					break;
					
					case 3:
						f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
						f.seekg(0);
						while(f.read((char *) & a,sizeof(a)))
						{
							a.displaytraindetails();
						}
						f.close();
					break;
					
					case 4:
						manage();
					break;
					
					case 5:
						displaypassdetail();
					break;
					default: ch=0; break;
				}
			}while(ch);
		f.close();
	}
}


//2. Asking for resrvation
void reserve()  
{
	int ch;
	do
		{
			cout<<"1.Reserve ticket \n2.Return to the main menu\n"<<"Choice: ";
			cin>>ch;
			
			switch(ch)
			{
			case 1: 	res(); break; // takes user to the res function where reservation will be done
			default: break;
			}
		}while(ch==1);

}

// 3. Reservation function
void res() 
{
	train_details a;	reservation b;	fstream f1,f2;  	time_t t;

	f1.open("t.txt",ios::in|ios::out|ios::binary);	f2.open("p.txt",ios::in|ios::out|ios::binary|ios::app);

	int ch;	b.getreservationdetails();

	while(f1.read((char *) &a,sizeof(a))) //reads till the last character of the file
	{
		if(a.train_no==b.tno)
		{
			if(strcmp(b.c,f)==0)
			{
				if(a.c1_seats>=b.noseats)
				{
					amt = a.c1_fare;
					addr = f1.tellg();
					ad = sizeof(a.c1_seats);
					f1.seekp(addr-(7*ad));
					a.c1_seats=a.c1_seats-b.noseats;
					f1.write((char *) & a.c1_seats,sizeof(a.c1_seats));
					b.fare=b.noseats*amt;
					srand((unsigned) time(&t));
					b.pnr=rand();
					f2.write((char *) & b,sizeof(b));
					b.displayreservationdetails();
					cout<<"________________\n\n";
					cout<<"\t\t\t TICKET RESERVED!! \n";
					cout<<"______End of reservation menu______\n";
				}
				else
				{		cout<<"\n\t\t\t Sorry, no seats available!!!  \n"; 	}
			}
			else if(strcmp(b.c,s)==0)
			{
				if(a.c2_seats>=b.noseats)
				{
					amt=a.c2_fare;
					addr=f1.tellg();
					ad=sizeof(a.c2_seats);
					f1.seekp(addr-(5*ad));
					a.c2_seats=a.c2_seats-b.noseats;
					f1.write((char *) & a.c2_seats,sizeof(a.c2_seats));
					cout<<"NO DISCOUNT AVAILABLE FOR THIS ENTRY\n";
					b.fare=b.noseats*amt;
					
					f2.write((char *) & b,sizeof(b));
					b.displayreservationdetails();
					cout<<"_____________\n\n";
					cout<<"_____TICKET RESERVED_____\n";
				}
				
				else
				{	cout<<"___Sorry, requested no of seats not available!!____\n";		}
			}
			
			return;
		}
		else
		{
		flag=0;
		}
	}
	
	if(flag==0)
	{	cout<<"\n....................Wrong train no......................\n"; 	}
	f1.close();	f2.close();


}


//4. Displaying passenger details
void displaypassdetail()
{
	fstream f;	reservation b;
	f.open("p.txt",ios::in|ios::out|ios::binary);
	f.seekg(0);
	
	while(f.read((char *) & b,sizeof(b)))
	{	b.displayreservationdetails();  	}
	f.close();

}

// 5. Ticket enquiry function
void enquiry()
{
	fstream f;
	f.open("t.txt",ios::in|ios::out|ios::binary);
	train_details a;
	
	while(f.read((char *) &a,sizeof(a)))   	{	a.displaytraindetails();  	}

}


// 6. if user asks for cancellation
void can() 
{
	int ch;
	do
	{
		cout<<"____CANCELLATION MENU____\n";
		cout<<"1.Cancel ticket \n2.Return to the main menu  \n";
		cout<<"Enter your choice:";	cin>>ch;
		
		switch(ch)
		{
			case 1:	cancell();	break;
			default: ch=0; break;
		}
	}while(ch);

}	
	
	
//7. ticket cancellation
void cancell() 
{
	train_details a;	reservation b;	cancel c;		fstream f1,f2,f3;
	
	f1.open("t.txt",ios::in|ios::out|ios::binary);
	f2.open("p.txt",ios::in|ios::out|ios::binary);
	f3.open("cn.txt",ios::in|ios::out|ios::binary);
	
	cout<<"____CANCELLATION MENU____\n";		c.getcancel();
	while(f2.read((char *) & b,sizeof(b)))
	{
		if(b.pnr==c.pnr)
		{
			c.tno=b.tno;
			strcpy(c.tname,b.tname);
			strcpy(c.boarding,b.boarding);
			strcpy(c.destiny,b.destiny);
			c.noseats=b.noseats;
			for(int j=0;j<c.noseats;j++)		{		strcpy(c.name[j],b.name[j]);		c.age[j]=b.age[j];		}
			strcpy(c.c,b.c);
			
			if(strcmp(c.c,f)==0)
			{
			while(f1.read((char *) & a,sizeof(a)))
			{
			if(a.train_no==c.tno)
			{
				a.c1_seats=a.c1_seats+c.noseats;
				d=a.day;
				m=a.month;
				addr=f1.tellg();
				ad=sizeof(a.c1_seats);
				f1.seekp(addr-(7*ad));
				f1.write((char *) & a.c1_seats,sizeof(a.c1_seats));
				tamt=b.fare;
				if((c.dd==d)&&(c.mm==m))  // cancellation on the date oif the departure
				{				cout<<"CANCELLATION ON THE DATE OF DEPARTURE!! \n";				c.fare=tamt-((tamt*60)/100);			}
				else if(c.mm==m)
				{			c.fare=tamt-((tamt*50)/100); 		}  	// cancellation during the month of the departure
				else if(m>c.mm)				{	c.fare=tamt-((tamt*20)/100);				}  // cancellation one month before the departure
				else  // CANCELLATION AFTER THE DEPARTURE
				{		cout<<"Cancelling after the departure\n";			cout<<"Your request cannot be completed\n"; 		}
			goto h;
			c.displaycancel();  // display cancellation details
			}
			}
			}
			else if(strcmp(c.c,s)==0)
			{
				while(f1.read((char *) & a,sizeof(a)))
				{
					if(a.train_no==c.tno)
					{
						a.c2_seats=a.c2_seats+c.noseats;
						d=a.day;		m=a.month;
						
						addr = f1.tellg();
						ad = sizeof(a.c2_seats);
						f1.seekp(addr-(5*ad));
						f1.write((char *) & a.c2_seats,sizeof(a.c2_seats));
						tamt=b.fare;
						
						if((c.dd==d)&&(c.mm==m))  // cancellation on the date oif the departure
						{	cout<<"You are cancelling at the date of departure\n";	c.fare=tamt-((tamt*60)/100);		}
						else if(c.mm==m) // cancellation during the month of the departure
						{	c.fare=tamt-((tamt*50)/100);		}
						else if(m>c.mm)  // cancellation one month before the departure
						{			cout<<"You are cancelling one month before the date of departure\n";	c.fare=tamt-((tamt*20)/100);	}
						else  // cancellation after the departure
						{	cout<<"Cancelling after the departure\n"<<"Your request cannot be completed\n"; 	}
					goto h;
					c.displaycancel();
			}	}	}
		}
		else	{	flag=0;		}
	}
h:
	if(flag==0)	{	cout<<"Enter the correct pnr no\n";	}
	f1.close();	f2.close();	f3.close();

}


// 8. user module
void user()
{
	user_login a;	int ch;
	cout<<"__________________\n";	cout<<"\t\t\t\t USER MENU  \n";
	cout<<"___________________\n";
	
	char *password;
	
	fstream f;  	f.open("id.txt",ios::in|ios::out|ios::binary);
	char id[100];	puts("Enter your id:");		gets(id);
	password=getpass("Enter your password:");
	
	while(f.read((char *) & a,sizeof(a)))
	{
		if((strcmp(a.id,id)==0)&&(strcmp(a.pass,password)==0))
		{
			do
			{
				cout<<"1.Reserve \n2.Cancel \n3.Enquiry \n4.Return to the main menu\n";
				cout<<"Enter your choice:";		cin>>ch;	cout<<endl;
				switch(ch)
				{
					case 1:	reserve();	break;
					case 2:	cancell();	break;
					case 3:	enquiry();	break;
					default: ch=0; break;
				}
			}while(ch);
			return;
		}
		else	{	d=1;	}
	}
	
	if(d==1)	{ cout<<"	INVALID USER ID!!  \n";	}
	


}


// 9. management of tickets
void manage() 
{
	int ch; 	fstream f;  	char c; 	user_login a;
	
	cout<<"_____WELCOME TO THE USER MANAGEMENT MENU______\n";
	do
	{
		cout<<"1.Create new ID \n2.Add details \n"<<"3.Display details  \n4.Return to the main menu  \n";
		cout<<"Enter your choice:";		cin>>ch; cout<<endl<<endl;
		
		switch(ch)
		{
			case 1: 	f.open("id.txt",ios::out|ios::binary);
						do
						{
							a.getlogindetail();
							f.write((char *) & a,sizeof(a));
							cout<<"Do you want to add one more record\n";
							cout<<"y-Yes\nn-No\n";
							cin>>c;
						}while(c=='y');
						f.close();
					break;
			case 2:		f.open("id.txt",ios::in|ios::out|ios::binary|ios::app);		a.getlogindetail();
						f.write((char *) & a,sizeof(a));	f.close();
					break;
			
			case 3:		f.open("id.txt",ios::in|ios::out|ios::binary);		f.seekg(0);
						while(f.read((char *) & a,sizeof(a)))
						{	a.displaylogindetail();		}		f.close();
					break;
			default: ch = 0; break;
		}
	}while(ch);

}
