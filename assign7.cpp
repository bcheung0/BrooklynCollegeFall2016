/*
BRIAN CHEUNG 
CISC 1100 
*/



#include <iostream>
#include <fstream>
#include <iomanip>
#include <fstream>
using namespace std;

void readFile(double [],int &);
void printHeading(void);



int main(){
	int countArr=0;
	cout << fixed << setprecision(2);
	double arr[5];
	readFile(arr,countArr);
	//for(int i=0;i<5;i++){
	//	cout << arr[i] << endl;	
	//	}	
	 
	
	int control;
	int count=0;
	
	int customer = 1;
	
	double finalTotal=0;
	
	double totalCredit=0;
	double totalPaid=0;
	
	cout << "Welcome to Brian's Store! Hit 1 to Start Shopping or 0 to Stop" << endl;
	cin >> control;
	
	if(control==1){
	while(control==1){
		
		cout << "Welcome Customer Number: " << customer << endl;
		cout << fixed << setprecision(2) << endl;
		
		double item1;
		double item2;
		double item3;
		double item4;
		double item5;  // ended here
		double sum=0;
		
		cout << "How many of item 1 are you buying? ($00.50)" << endl;
		cin >> item1;
		cout << "How many of item 2 are you buying? ($2.25)" << endl;
		cin >> item2;
		cout << "How many of item 3 are you buying? ($7.75)" << endl;
		cin >> item3;
		cout << "How many of item 4 are you buying? ($10.00)" << endl;
		cin >> item4;
		cout << "How many of item 5 are you buying? ($00.25)" << endl;
		cin >> item5;
		
		sum=sum+(item1*arr[0])+(item2*arr[1])+(item3*arr[2])+(item4*arr[3])+(item5*arr[4]);
		finalTotal+=sum;
		
		
		cout << "Your Total is: "<< sum << endl;
		
		double paid;
		cout << "How much are you paying?" << endl;
		cin >> paid;
		
		if((paid-sum)<0){
			cout << fixed << setprecision(2);
			printHeading();
			cout << "CREDIT" << endl;
			totalCredit=(sum-paid);
			cout << customer<< "                " << sum << "    " << paid << "    " << sum-paid << endl;
		}
		else{
			cout << fixed << setprecision(2);
			printHeading();
			cout << "AMOUNT OWED" << endl;
			totalPaid=(paid-sum);
			cout << customer<< "                " << sum << "    " << paid <<"    " <<  paid-sum <<  endl;
		}
		
		
		
		count++;
		customer++;  
		
		
		
		cout << "Welcome to Brian's Store! Hit 1 to Start Shopping or 0 to Stop" << endl;
		cin >> control;
	}	
	}
	else{
		cout << "Thank you for shopping with us today!" << endl;
		
	}
	cout << fixed << setprecision(2) << endl;
	
	cout << "TOTAL DOLLARS PLACED: $" << finalTotal << endl;
  	cout << "TOTAL DUE: $" << totalCredit << endl; 
	cout << "Total ORDERS PAID FOR: $" << totalPaid << endl;	
	
	
		
}

void readFile(double a[],int &c){
	
	ifstream inp("cust.txt"); 
	c=0;
	while(inp >> a[c]){
		c++;
	}
	inp.close();
}

void printHeading(void){
	cout << "Customer\tAmount\tPaid\tBalance" << endl;
	
}

/*
Welcome to Brian's Store! Hit 1 to Start Shopping or 0 to Stop
0
Thank you for shopping with us today!
TOTAL DOLLARS PLACED: $0
TOTAL DUE: $0
Total ORDERS PAID FOR: $0

--------------------------------
Process exited after 1.169 seconds with return value 0
Press any key to continue . . .

Welcome to Brian's Store! Hit 1 to Start Shopping or 0 to Stop
1
Welcome Customer Number: 1

How many of item 1 are you buying? ($00.50)
2
How many of item 2 are you buying? ($2.25)
12
How many of item 3 are you buying? ($7.75)
0
How many of item 4 are you buying? ($10.00)
1
How many of item 5 are you buying? ($00.25)
23
Your Total is: 43.75
How much are you paying?
50
Customer        Amount  Paid    Balance
AMOUNT OWED
1                43.75    50    6.25
Welcome to Brian's Store! Hit 1 to Start Shopping or 0 to Stop
1
Welcome Customer Number: 2

How many of item 1 are you buying? ($00.50)
2
How many of item 2 are you buying? ($2.25)
3
How many of item 3 are you buying? ($7.75)
41
How many of item 4 are you buying? ($10.00)
2
How many of item 5 are you buying? ($00.25)
3
Your Total is: 346.25
How much are you paying?
500
Customer        Amount  Paid    Balance
AMOUNT OWED
2                346.25    500    153.75
Welcome to Brian's Store! Hit 1 to Start Shopping or 0 to Stop

Welcome to Brian's Store! Hit 1 to Start Shopping or 0 to Stop
1
Welcome Customer Number: 1

How many of item 1 are you buying? ($00.50)
1
How many of item 2 are you buying? ($2.25)
1
How many of item 3 are you buying? ($7.75)
1
How many of item 4 are you buying? ($10.00)
1
How many of item 5 are you buying? ($00.25)
1
Your Total is: 20.75
How much are you paying?

20.11
Customer        Amount  Paid    Balance
CREDIT
1                20.75    20.11    0.64
Welcome to Brian's Store! Hit 1 to Start Shopping or 0 to Stop
1
Welcome Customer Number: 2

How many of item 1 are you buying? ($00.50)
3
How many of item 2 are you buying? ($2.25)
1
How many of item 3 are you buying? ($7.75)
54
How many of item 4 are you buying? ($10.00)
3
How many of item 5 are you buying? ($00.25)
0
Your Total is: 452.25
How much are you paying?
411.35
Customer        Amount  Paid    Balance
CREDIT
2                452.25    411.35    40.90
Welcome to Brian's Store! Hit 1 to Start Shopping or 0 to Stop
1
Welcome Customer Number: 3

How many of item 1 are you buying? ($00.50)
35
How many of item 2 are you buying? ($2.25)
4
How many of item 3 are you buying? ($7.75)
4
How many of item 4 are you buying? ($10.00)
0
How many of item 5 are you buying? ($00.25)
1
Your Total is: 57.75
How much are you paying?
60.50
Customer        Amount  Paid    Balance
AMOUNT OWED
3                57.75    60.50    2.75
Welcome to Brian's Store! Hit 1 to Start Shopping or 0 to Stop
1
Welcome Customer Number: 4

How many of item 1 are you buying? ($00.50)
1
How many of item 2 are you buying? ($2.25)
1
How many of item 3 are you buying? ($7.75)
1
How many of item 4 are you buying? ($10.00)
1
How many of item 5 are you buying? ($00.25)
0
Your Total is: 20.50
How much are you paying?
20.50
Customer        Amount  Paid    Balance
AMOUNT OWED
4                20.50    20.50    0.00
Welcome to Brian's Store! Hit 1 to Start Shopping or 0 to Stop
1
Welcome Customer Number: 5

How many of item 1 are you buying? ($00.50)
36
How many of item 2 are you buying? ($2.25)
2
How many of item 3 are you buying? ($7.75)
3
How many of item 4 are you buying? ($10.00)
1
How many of item 5 are you buying? ($00.25)
4
Your Total is: 56.75
How much are you paying?
60
Customer        Amount  Paid    Balance
AMOUNT OWED
5                56.75    60.00    3.25
Welcome to Brian's Store! Hit 1 to Start Shopping or 0 to Stop
1
Welcome Customer Number: 6

How many of item 1 are you buying? ($00.50)
1
How many of item 2 are you buying? ($2.25)
0
How many of item 3 are you buying? ($7.75)
0
How many of item 4 are you buying? ($10.00)
0
How many of item 5 are you buying? ($00.25)
1
Your Total is: 0.75
How much are you paying?
5
Customer        Amount  Paid    Balance
AMOUNT OWED
6                0.75    5.00    4.25
Welcome to Brian's Store! Hit 1 to Start Shopping or 0 to Stop
0

TOTAL DOLLARS PLACED: $608.75
TOTAL DUE: $40.90
Total ORDERS PAID FOR: $4.25

--------------------------------
Process exited after 55.34 seconds with return value 0
Press any key to continue . . .

*/
