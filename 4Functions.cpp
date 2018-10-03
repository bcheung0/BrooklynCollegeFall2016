/*
BRIAN CHEUNG
CISC 1110
Assignment 4
Date Due: 9/22/16
Date Submitted: 9/17/16
Finds the sum of 4 formulas 
*/

#include <iostream>
using namespace std;

int sumOfCubes(int);  // Prototype
int sumOfForm2(int);
int sumOfForm3(int);
int sumOfForm4(int);
int compareFunction(int,int);


int main(){
	
	int input=4;
	int result;
	int result2;
	int result3;
	int result4;
	
	
	result=sumOfCubes(input);    
	result2=sumOfForm2(input);
	result3=sumOfForm3(input);
	result4=sumOfForm4(input);
	
	cout << result << " is the sum of n cubes" << endl;  
	
	cout << result2 << " is the sum for formula 2" << endl;
 
 	cout << result3 << " is the sum for formula 3" << endl;
 	
 	cout << result4 << " is the sum for formula 4" << endl;  
 	
 	int compare;
 	int compareSum2Sum3;
 	int compareSum3Sum4;
 	
 	compare=compareFunction(result,result2);
 	compareSum2Sum3= compareFunction(result2,result3);
 	compareSum3Sum4= compareFunction(result3,result4);
 	
 	
 	cout << "The comparison of result and result2 is returned as "<< compare << endl; 
 	cout << "The comparison of result2 and result3 is returned as "<< compareSum2Sum3 << endl; 
 	cout << "The comparison of result3 and result4 is returned as "<< compareSum3Sum4 << endl; 
 	
 	
 	int resultLoop;
 	int result2Loop;
 	int result3Loop;
 	int result4Loop;
 	
 	
 	int n;
 	cout << endl << "What would you like n to be?" << endl;
 	cin >> n;
 	
 	while(n!=-1){
	resultLoop=sumOfCubes(n);    
	result2Loop=sumOfForm2(n);
	result3Loop=sumOfForm3(n);
	result4Loop=sumOfForm4(n);
	
	cout << resultLoop << " is the sum of n cubes" << endl;  
	
	cout << result2Loop << " is the sum for formula 2" << endl;
 
 	cout << result3Loop << " is the sum for formula 3" << endl;
 	
 	cout << result4Loop << " is the sum for formula 4" << endl;	
 	
 	cout << "Enter -1 to stop" << endl; 
 	cin >> n;	 
	 }
				 
	system("pause");
	return 0;
}	
// Sum of n amount of cubes
int sumOfCubes(int a)
{
 	
 	int sum=0;
 	for(;a>0;a--){	 				  
 	  sum += ((a*a)*a);
	}	
 	return sum ;
 	
}
// Sum of the formula given on the worksheet
int sumOfForm2(int x)
{
 	int sum;
	sum=((x*x *((x+1)*(x+1)))/4);

	 return sum;
}


// The Square of the sum of the first n numbers
int sumOfForm3(int c)
{
 	int sum3;
	int sum=0;
	for(;c>0;c--){
        sum=sum+c;                 
     }
  	 sum3=sum*sum;
  	 
  	 return sum3;
} 	
// Sum of the 2 formula given on the worksheet 
int sumOfForm4(int b)
{
 	int sum;
 	sum=(b*(b+1)*((2*b)+1))/(4+2);
 	
 	return sum;
 	
}
// Compares 
int compareFunction(int a,int b)
{
 	if(a==b)
 	  return 1;
 	
 	else
 	  return 0;
}


/*
36 is the sum of n cubes
36 is the sum for formula 2			
36 is the sum for formula 3
14 is the sum for formula 4
The comparison of result and result2 is returned as 1
The comparison of result2 and result3 is returned as 1
The comparison of result3 and result4 is returned as 0

What would you like n to be?					TRACE
3
36 is the sum of n cubes					1^3+2^3+3+3^3=36									36=36
36 is the sum for formula 2					(3^2(3+1)^2) / 4 = 9*16 /4 = 144/4 =36				36=36	
36 is the sum for formula 3					(1+2+3)^3= 6^2 = 36									36=36
14 is the sum for formula 4					(3*(3+1)*(2*3+1))/4+2  =   12*7/4 =16				14=14
Enter -1 to stop
5
225 is the sum of n cubes					1^3 + 2^3 + 3^3 + 4^3 + 5^3 = 1+8+27+64+125=225     225=225
225 is the sum for formula 2				(5^2(5+1)^2) /4= 25 * 36/4=900/4 = 225				225=225
225 is the sum for formula 3				(1+2+3+4+5)^3 = 15^2 = 225							225=225
55 is the sum for formula 4					(5*(5+1)*(2*5+1))/4+2  = 5*6*7/(4+2) = 330/6 = 55	55=55
Enter -1 to stop
-1
Press any key to continue . . .
*/





	

    
