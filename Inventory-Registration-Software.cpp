#include <iostream>
#include <fstream>
using namespace std;
struct stock
{
int product_number,product_quantity;
float product_price,total;
char product_name[40],product_barcode[40]; 
};
void program_begin();
void password_change();
void add_stock(struct stock item[], int& arrival);
void display_stock(struct stock item[], int arrival);
void edit_stock(struct stock item[], int arrival);
void delete_stock(struct stock item[], int& arrival);
void search_stock(struct stock item[], int arrival);
void save_into_file (struct stock item[], int arrival);
void algorithm_sort(struct stock item[], int num);
int check (int check,struct stock item[],int arrival);

main()
{
program_begin(); // function to start the program
int arrival=1;// for the add
system("color 03");					
stock item[1000];
int redo; 
do{
system("cls");	

cout<<" _____________________________________ \n";
cout<<"|                                    |\n";
cout<<"|     [1] Add a new stock      	     |\n";
cout<<"|     [2] display all stocks         |\n";
cout<<"|     [3] Edit for stock             |\n";
cout<<"|     [4] Delete a stock             |\n";
cout<<"|     [5] Search a stock             |\n";
cout<<"|     [6] change the password        |\n";
cout<<"|     [7] compile all records        |\n";
cout<<"|     [0] Exit                       |\n";
cout<<"|____________________________________|\n";



 
int switch1;
cin>>switch1;					//this is select statement for the main menu page
switch (switch1)	
{

case 1 :	
	add_stock(item,arrival);
	break;
case 2 :
	display_stock(item,arrival);
	break;	
case 3 :
	edit_stock(item,arrival);
	break;		
case 4 :
	delete_stock(item, arrival);
	break;
case 5 :
	search_stock(item, arrival);
	break;
case 6 :
	password_change();  
	break;  
case 7 :	
	save_into_file(item,arrival);
   	break;

}
cout<<"Press [1] go back\nPress [2] exit:";
cin>>redo;                   // to go back to the  main  
}
while(redo==1||redo>2);


}


void add_stock(  stock item[], int& arrival)
{       cout<<"Enter the product_number: ";
 	    cin>>item[arrival].product_number;
        cout<<"Enter the product_name: ";
        cin>> item[arrival].product_name;
        cout<<"Enter The price: ";
        cin>> item[arrival].product_price;
        cout<<"Enter The quantity: ";
        cin>> item[arrival].product_quantity;
        cout<<"Enter The Barcode: ";
        cin>> item[arrival].product_barcode;
        item[arrival].total=(item[arrival].product_price*item[arrival].product_quantity);   
		arrival=arrival+1; 	
		cout<<"the product is successfully added" <<endl;
		algorithm_sort(item, arrival); // ask the to sotr it
}


void display_stock(struct stock item[], int arrival)
{
	for ( int j=1; j<=1000; j++)		
	{									
		if (j<arrival)
			{
			if (item[j].product_number!=0)
				{
				cout<<"==================================================================================="<<endl;
        		cout<< "product number :"<< item[j].product_number << endl;
        		cout << "product name :"<< item[j].product_name << endl;
        		cout << "product price :"<< item[j].product_price << endl;
        		cout << "product quantity :"<< item[j].product_quantity << endl;
        		cout << "product barcode :"<< item[j].product_barcode << endl;
        		cout << "Total price :"<< item[j].total << endl;
        
				}
			else ;
			}


	}

	
	
}

void delete_stock(struct stock item[], int& arrival)
{
int delete_stock_entered;
cout<<"Please Enter The stock number to delete :";
cin>>delete_stock_entered;
int i= check(delete_stock_entered,item,arrival);   // go to function and give the number on array 
int b=item[i].product_number  ;     // to give the product number from the array (only use it to make if statement)

		if (delete_stock_entered==b)
		{
      
			item[i].product_number=0;
			item[i].product_name[40]=='0';
			item[i].product_price=0;
			item[i].product_quantity=0;
			item[i].product_barcode[40]=='0';
			item[i].total=0;
			cout<<"the product is successfully deleted" <<endl;
			algorithm_sort(item, arrival); // ask  to sotr it after delete
			
		}
	 	else if (delete_stock_entered!=b)
	 	{
    	cout<<"The product number which you have  entered is wrong!\n ";
		 }

}
void edit_stock(struct stock item[], int arrival)
{
	
int change_stock_entered;		//when you enter the stock you want to edit, it fetches the particular index in the array and you just redo the record
cout<<"Please Enter The stock number to edit :";
cin>>change_stock_entered;
int i= check(change_stock_entered,item,arrival);   // go to function and give the number on array 
int b=item[i].product_number  ;     // to give the product number from the array (only use it to make if statement)
if (change_stock_entered==b)
		{
	cout<<"[1]product_number \n[2]product_name \n[3]The price \n[4]The quantity \n[5]The Barcode";
	cout<<"\n what field do you want to change?";
	int choose;
	cin>>choose;		
	switch (choose)
			{
			case 1:
		    		cout<<"Enter the product_number: ";
        			cin>> item[i].product_number;
        			break;
			case 2:
				cout<<"Enter the product_name: ";
        			cin>> item[i].product_name;
        			break;
			case 3:
					cout<<"Enter The price: ";
        			cin>> item[i].product_price;
        			break;
			case 4 :
					cout<<"Enter The quantity: ";
        			cin>> item[i].product_quantity;
        			break;
			case 5 :
					cout<<"Enter The Barcode: ";
        			cin>> item[i].product_barcode;
        			break;	
			}
			item[i].total=(item[i].product_price*item[i].product_quantity);
        	cout<<endl;
        	cout<<"the product is successfully edited" <<endl;	
    	}
         else if (change_stock_entered!=b)
        cout<<"The product number which you have  entered is wrong!\n ";
        
	algorithm_sort(item, arrival);      // ask the to sotr it
}


void search_stock(struct stock item[], int arrival)
{
	int item_num;
cout <<"Please Enter The stock number to search";
cin>>item_num;	
int size =arrival;
int low = 0;
int high = size - 1;
int mid;
while(low <= high)
{
	mid = (low+high)/2;
	if (item_num == item[mid].product_number)
	{
        cout<< "product number :"<< item[mid].product_number << endl;
        cout << "product name :"<< item[mid].product_name << endl;
        cout << "product price :"<< item[mid].product_price << endl;
        cout << "product quantity :"<< item[mid].product_quantity << endl;
        cout << "product barcode :"<< item[mid].product_barcode << endl;
        cout << "Total price :"<< item[mid].total << endl;
		break;
	}
	else if (item_num > item[mid].product_number){
		low = mid + 1;
	}else{
		high = mid - 1;
	}
}	
	
}

void save_into_file (struct stock item[], int arrival)
{
		
		ofstream dbrecords ("dbrecords.txt" );
		for (int x=1;x<arrival;++x)
		{
			if (item[x].product_number!=0)
			{
       dbrecords<<"==========================================================\n";
         dbrecords<< "product number :"<< item[x].product_number << endl;
        dbrecords << "product name :"<< item[x].product_name << endl;
        dbrecords << "product price :"<< item[x].product_price << endl;
        dbrecords << "product quantity :"<< item[x].product_quantity << endl;
        dbrecords << "product barcode :"<< item[x].product_barcode << endl;
        dbrecords << "the total :"<< item[x].total << endl;
			}
        
		}
        cout<<"done!"<<endl;	
}
void algorithm_sort(struct stock item[], int num)
{
    int i, j;
    for (i = 0; i < num; ++i)
        for (j = num - 1; j > i; j--)
            if (item[j].product_number < item[j - 1].product_number)
			{
                stock sort = item[j];
                item[j] = item[j - 1];
                item[j - 1] = sort;
            }
}
void program_begin()
{
int password;	
system ("color 3");
cout<<endl;
cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
cout<<"\t@@ _______________________________________________________________________________________ @@\n";
cout<<"\t@@|                                           		                                  |@@\n";
cout<<"\t@@|                                           		                                  |@@\n";
cout<<"\t@@|                                           		                                  |@@\n";
cout<<"\t@@|                                  WELCOME TO                                           |@@\n";
cout<<"\t@@|                                                                                       |@@\n";
cout<<"\t@@|                         inventory registration software                               |@@\n";
cout<<"\t@@|                                                                                       |@@\n";
cout<<"\t@@|                                                                                       |@@\n";
cout<<"\t@@|                                                                                       |@@\n";
cout<<"\t@@|                                     designed by a group of students studying at INTI  |@@\n";
cout<<"\t@@|_______________________________________________________________________________________|@@\n";
cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"<<endl;
cout<<"\t\t\t\t\tPlease enter the password\t\n"<<"\t\t\t\t\t"; // note that there is file must be added manmed (password_database) 
int true_password,Enter_password ;                            //  and the password must be entered in the file to recive it by the program 
ifstream db ;
db.open("password_database" );
db>>true_password;
cin>>Enter_password;
if (Enter_password==true_password)
	{
	cout<<"\t\t\t\t\tYou entered right password";	
	system("cls");
	}
else if (Enter_password!=true_password)
	{
	system ("color 4");	
	cout<<"\t\t\t\t\tYou entered wrong password";
	exit(0);
	}
}

void password_change()
{
int new_password ;
cout<<"Enter the new password ";
cin>>new_password;	
ofstream db ("password_database" );
db<<new_password;
cout<<"\nThe password in the database has changed ";	
}
int check (int check,struct stock item[],int arrival) // for the delete and edit 
{
	for(int i;i<arrival;++i)
	{
	if (check==item[i].product_number)	
	return i;
	}
}

