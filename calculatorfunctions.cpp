/*
BRIAN CHEUNG 
CISC 1100 TR2
Assignment 6
*/




#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

void printMenu(void);
double arith(int &,int &,char);
double arith2(double,char);


int main(){
	
	ofstream fout;
	fout.open("output.txt");
	fout << "Data\tResult\t Oper\tOper2\n" << endl; //"Result"/t "Oper 1" /t "Oper 2" ;
	
	
	printMenu();
	char inputMain;
	cout << "Which Operater" << endl;  
	
	cin >> inputMain;
	
	
	while(inputMain !=('Q')){
	
    if(inputMain == '+' || inputMain=='-' || inputMain=='*'|| inputMain=='/' || inputMain=='%' || inputMain=='A' || inputMain=='N' || inputMain=='P') { 
	//(('+') ||('-')||('*')||('/')||('%')||('A')||('N')||('P')))
    	int operand1;
   		int operand2;
    	cout << "Enter your first number" << endl;
    	cin >> operand1;
    	cout << "Enter your second number" << endl ;
    	cin >> operand2;
    	cout << endl;
    	 
    	fout << inputMain << "       " << arith(operand1,operand2,inputMain ) << "       "<< operand1 << "        " << operand2 << endl; 

    	cout << "Operater: " << inputMain << endl << "Operan1 = " << operand1 << endl << "Operan2 = " << operand2 << endl << "The result is: " << arith(operand1,operand2,inputMain) << endl << endl;
    		
	}
 	else{
		int operand3;
		cout << "Enter a number"<< endl;
		cin >> operand3;
		cout << endl;
		cout << "Operater: " << inputMain << endl << "Operan = " << operand3 << endl << "The result is: " << arith2(operand3,inputMain) << endl;
		
		fout << inputMain << "       " << arith2(operand3,inputMain) << "       "<< operand3 << "        " << endl;
	}
	
	cout  << "Type in +, -, *, /, %, A, N, P, R, F ,T (LETTERS ARE CASE SENSITIVE)" << endl << "Q TO STOP"<< endl;
	cout << "Operater: ?" << endl;  
	cin >> inputMain;
	
	}
	
    system("pause");
    return 0;
    
    }
    

double arith(int &a, int &b,char c) // First Set of arith (Addition,Subtraction,Multp, Division, Mod, Average of two numbers, and Min
{
	double result;
	if(c=='+'){
		result=a+b; 
		
		return result;
	}
	else if(c=='-'){
		result=a-b;
		return result;
	}
 	else if(c=='/'){
		result=a/b;
		return result;
	}
	else if(c=='*'){
		result=a*b;
		return result;
	}
	else if(c=='%'){
		result=a%b;
		return result;
	}
	else if(c=='A'){
		result=(a+b)/2;
		return result;
	}
	else if(c=='N'){
		if(a>b){
		return b;
		}
		else{
			return a;
		}		
	}
	else if(c=='P'){
		return pow(a,b);
	}
}

double arith2(double a,char b){		// 2nd Set of arith (1/a, factorial, and square root 
	
	if(b=='R'){
		return 1/a;	   	
	}
	else if(b=='F'){
		int product=1;
		for(int i=1;i<=a;i++){
			product=product*i;		
		}	 
		return product;  	   	
	}
	else if(b='T'){
		return sqrt(a);
	}
	
}


void printMenu(){
	
	cout << "Type in +, -, *, /, %, A, N, P, R, F ,T (LETTERS ARE CASE SENSITIVE)" << endl << "Q TO STOP"<< endl; 
	return;
}	
	


/* OUTPUT																					TRACE
Type in +, -, *, /, %, A, N, P, R, F ,T (LETTERS ARE CASE SENSITIVE)
Q TO STOP
Which Operater
+
Enter your first number
2
Enter your second number
4

Operater: +						2+4=6
Operan1 = 2
Operan2 = 4
The result is: 6

Type in +, -, *, /, %, A, N, P, R, F ,T (LETTERS ARE CASE SENSITIVE)
Q TO STOP
Operater: ?
-
Enter your first number
2								2-(-5)=7
Enter your second number
-5

Operater: -
Operan1 = 2
Operan2 = -5
The result is: 7

Type in +, -, *, /, %, A, N, P, R, F ,T (LETTERS ARE CASE SENSITIVE)
Q TO STOP
Operater: ?
*
Enter your first number
3							3*5=15
Enter your second number
5

Operater: *
Operan1 = 3
Operan2 = 5
The result is: 15

Type in +, -, *, /, %, A, N, P, R, F ,T (LETTERS ARE CASE SENSITIVE)
Q TO STOP
Operater: ?
/
Enter your first number
7							7/3=2
Enter your second number
3

Operater: /
Operan1 = 7
Operan2 = 3
The result is: 2

Type in +, -, *, /, %, A, N, P, R, F ,T (LETTERS ARE CASE SENSITIVE)
Q TO STOP
Operater: ?
%
Enter your first number
7							7%3=1
Enter your second number
3

Operater: %
Operan1 = 7
Operan2 = 3
The result is: 1

Type in +, -, *, /, %, A, N, P, R, F ,T (LETTERS ARE CASE SENSITIVE)
Q TO STOP
Operater: ?
R							
Enter a number
4

Operater: R
Operan = 4
The result is: 0.25						1/4=.25
Type in +, -, *, /, %, A, N, P, R, F ,T (LETTERS ARE CASE SENSITIVE)
Q TO STOP
Operater: ?
F
Enter a number
8

Operater: F
Operan = 8				!8 = 40320
The result is: 40320
Type in +, -, *, /, %, A, N, P, R, F ,T (LETTERS ARE CASE SENSITIVE)
Q TO STOP
Operater: ?
T
Enter a number
25

Operater: T
Operan = 25				square root of 25 is 5
The result is: 5
Type in +, -, *, /, %, A, N, P, R, F ,T (LETTERS ARE CASE SENSITIVE)
Q TO STOP
Operater: ?
T
Enter a number
20

Operater: T
Operan = 20
The result is: 4.47214
Type in +, -, *, /, %, A, N, P, R, F ,T (LETTERS ARE CASE SENSITIVE)
Q TO STOP
Operater: ?
A
Enter your first number
3
Enter your second number
5

Operater: A
Operan1 = 3					3+5=8  8/2=4 
Operan2 = 5
The result is: 4

Type in +, -, *, /, %, A, N, P, R, F ,T (LETTERS ARE CASE SENSITIVE)
Q TO STOP
Operater: ?
N
Enter your first number
3
Enter your second number
5

Operater: N
Operan1 = 3
Operan2 = 5
The result is: 3

Type in +, -, *, /, %, A, N, P, R, F ,T (LETTERS ARE CASE SENSITIVE)
Q TO STOP
Operater: ?
P
Enter your first number
3
Enter your second number
4

Operater: P
Operan1 = 3
Operan2 = 4
The result is: 81

Type in +, -, *, /, %, A, N, P, R, F ,T (LETTERS ARE CASE SENSITIVE)
Q TO STOP
Operater: ?
Q
Press any key to continue . . .
*/

