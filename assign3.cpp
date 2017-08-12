#include <iostream>
#include <cmath> 
#include <fstream>
#include <iomanip>


using namespace std;
int main(){

ofstream fout; 
fout.open("output.txt");
  
    
int foward;
int stop; 
int count = 0;
int controlTwo; 

double hammer= 19.99;
double tape= 14.99;
double screwdriver= 6.99;
double glue= 7.50;
double fryingPan = 25.50;
double pencil = 1.00; 

double finalTotal=0;
double endCredit= 0;
int paid= 0;
double paidtotal=0;
double total=0;
double paymentSum=0;

fout << "Customers   Hammers   Tape   Screwdrivers   Glue    Frying Pans   Pencil   Paid   Credit/Owed   " << endl << endl; //Output


cout << "WELCOME TO BRIAN'S HARDWARDSTORE" << endl << "Are you buying items today? Hit 1 TWICE for YES, 0  TWICE for NO" << endl; // This is the prompt to know that i have a customer
int control;
cin >> control;

if(control==0){
  while(foward!=1){ // When there is no customers  
     cout << "Please Look around our selection! Hit 1 to begin shopping"<< endl;
     cin >> foward;                               
}                               

}
               
      cout << "Hit one to begin shopping" << endl;           
      cin >> controlTwo;         

if((control==1) || (controlTwo==1)){                      
  while(stop!=0){ // the loop 
  count++;     //Customer Number 
  cout << fixed <<setprecision(2);                                
  cout << "Welcome Customer: " << count << endl;
                      
 double sum=0;
 double h;
 double t;
 double s;
 double g;
 double f;
 double p;

 cout << "How many hammers are you buying?" << endl;
 cin >> h;
 cout << "How many rolls of tape are you buying?" << endl;
 cin >> t;
 cout << "How many screwdriver are you buying?" <<  endl;
 cin >> s;
 cout << "How many bottles of glue are you buying?" << endl;
 cin >> g;
 cout << "How many frying pans are you buying?" << endl;
 cin >> f;
 cout << "How many pencils are you buying?" <<  endl;
 cin >> p;
 
 
 sum = sum+ (hammer*h)+(tape*t)+(screwdriver*s)+(glue*g)+(fryingPan*f)+(pencil*p);
 finalTotal=finalTotal+sum;
 
 cout << endl << "Customer: " << count<<  ", Your Total is: $" << sum << endl << endl; 
 
 double payment;
 
 cout << "How much are you paying?" << endl << endl;
 cin >> payment;
 paymentSum += payment; 
 
 
 if((payment-sum)<0){
    cout << "Credit: $" << (sum-payment) << endl << endl;    
     endCredit= endCredit + (sum-payment);  
      fout << count << "             " << h << "        " << t << "         " << s << "            " << g << "         " << f << "         " << p << "      " << payment  <<"       " <<(sum-payment) << endl << endl;           
    }                   
 else{
   cout << "Amount Owed: $" << (payment-sum) << endl << endl;
   total=total+sum;
   paid++;   
   fout << count << "              " << h << "         " << t << "       " << s << "            " << g << "           " << f << "         " << p << "      " << payment << "        " <<(payment-sum) << endl << endl; 
    
   } 
	
 cout << "Are you the last Customer? Hit 1 to start again. Hit 0 to exit for today" << endl << endl << endl;              
 cin >> stop;  // STOP 
 cout << endl;
 
     
	}      // END OF WHILE LOOP 
	
	
  cout << "TOTAL DOLLARS PLACED: $" << finalTotal << endl;
  cout << "AMOUNT OF ORDERS PAID FOR: $" << paymentSum << endl; 
  cout << "TOTAL DUE: $" << endCredit << endl; 
  cout << "The average amount paid is: $" << finalTotal/count << endl;
  cout << "Percantage paid: " << (100-((paymentSum/finalTotal)*100)) << "%" << endl;   
  
  
  fout << endl;
  fout << "TOTAL DOLLARS PLACED: $" << finalTotal << endl;
  fout << "AMOUNT OF ORDERS PAID FOR: $" << paymentSum << endl; 
  fout << "TOTAL DUE: $" << endCredit << endl; 
  fout << "The average amount paid is: $" << finalTotal/count << endl;
  fout << "Percantage paid: " << (100-((paymentSum/finalTotal)*100)) << "%" << endl;
             
                
  }       // END OF IF 
  else{
       cout << "If you're buying anything look around or leave!THANK YOU AND HAVE A NICE DAY" << endl;
}
     
  
  system("Pause");
  return 0; 
}    

/*       OUTPUT 

WELCOME TO BRIAN'S HARDWARDSTORE
Are you buying items today? Hit 1 TWICE for YES, 0  TWICE for NO
0
Please Look around our selection! Hit 1 to begin shopping
1
Hit one to begin shopping
1
Welcome Customer: 1
How many hammers are you buying?
0
How many rolls of tape are you buying?
0
How many screwdriver are you buying?
0
How many bottles of glue are you buying?
0
How many frying pans are you buying?
0
How many pencils are you buying?
50

Customer: 1, Your Total is: $50.00

How much are you paying?

100
Amount Owed: $50.00

Are you the last Customer? Hit 1 to start again. Hit 0 to exit for today


1

Welcome Customer: 2
How many hammers are you buying?
0
How many rolls of tape are you buying?
0
How many screwdriver are you buying?
0
How many bottles of glue are you buying?
5
How many frying pans are you buying?
3
How many pencils are you buying?
10

Customer: 2, Your Total is: $124.00

How much are you paying?

100
Credit: $24.00

Are you the last Customer? Hit 1 to start again. Hit 0 to exit for today


1

Welcome Customer: 3
How many hammers are you buying?
0
How many rolls of tape are you buying?
0
How many screwdriver are you buying?
0
How many bottles of glue are you buying?
47
How many frying pans are you buying?
12
How many pencils are you buying?
100

Customer: 3, Your Total is: $758.50

How much are you paying?

750.45
Credit: $8.05

Are you the last Customer? Hit 1 to start again. Hit 0 to exit for today


1

Welcome Customer: 4
How many hammers are you buying?
1
How many rolls of tape are you buying?
3
How many screwdriver are you buying?
4
How many bottles of glue are you buying?
1
How many frying pans are you buying?
3
How many pencils are you buying?
4

Customer: 4, Your Total is: $180.92

How much are you paying?

200
Amount Owed: $19.08

Are you the last Customer? Hit 1 to start again. Hit 0 to exit for today


1

Welcome Customer: 5
How many hammers are you buying?
3
How many rolls of tape are you buying?
4
How many screwdriver are you buying?
1
How many bottles of glue are you buying?
2
How many frying pans are you buying?
4
How many pencils are you buying?
5

Customer: 5, Your Total is: $248.92

How much are you paying?

300
Amount Owed: $51.08

Are you the last Customer? Hit 1 to start again. Hit 0 to exit for today


1

Welcome Customer: 6
How many hammers are you buying?
12
How many rolls of tape are you buying?
4
How many screwdriver are you buying?
2
How many bottles of glue are you buying?
3
How many frying pans are you buying?
4
How many pencils are you buying?
5

Customer: 6, Your Total is: $443.32

How much are you paying?

600
Amount Owed: $156.68

Are you the last Customer? Hit 1 to start again. Hit 0 to exit for today


0

TOTAL DOLLARS PLACED: $1805.66
AMOUNT OF ORDERS PAID FOR: $2050.45
TOTAL DUE: $32.05
The average amount paid is: $300.94
Percantage paid: -13.56%
Press any key to continue . . .





.TXT OUTPUT 

Customers   Hammers   Tape   Screwdrivers   Glue    Frying Pans   Pencil   Paid   Credit/Owed   

1              0         0       0            0           0         50      100        50

2             0        0         0            5         3         10      100       24

3             0        0         0            47         12         100      750.45       8.05

4              1         3       4            1           3         4      200        19.08

5              3         4       1            2           4         5      300        51.08

6              12         4       2            3           4         5      600        156.68


TOTAL DOLLARS PLACED: $1805.66
AMOUNT OF ORDERS PAID FOR: $2050.45
TOTAL DUE: $32.05
The average amount paid is: $300.943
Percantage paid: -13.5568%





TRACE

Customer 2: 5 Bottles of Glue, 3 Frying Pans, 10 Pencils =     (5*7.50) + (3*25.50) + 10 = 37.5+76.50+10= 124     124=124

Customer: 2, Your Total is: $124.00
How much are you paying?
100
Credit: $24.00

PAID WITH Hundred but total is less then paid so Credit 24 dollars.



Customer 3: 47 Bottles of glue, 12 Frying Pans, 100 Pencils =     (47*7.50)+(12*25.50)+(100*1)= 356.25+150+100 =  758.5

Customer: 3, Your Total is: $758.50
How much are you paying?
750.45
Credit: $8.05

Total is 758.50, paided with 750.45 so the credit is 8.05.





*/





