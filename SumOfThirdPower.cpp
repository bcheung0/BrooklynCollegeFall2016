#include <iostream>
#include <cmath> 
using namespace std;
int main() 
{
double n;    
int sum1=0;
cout << "What number is \"n\""<< "?" << endl;
cin >> n; 

for(double i=1;i<=n;i++)
{
 sum1=sum1 + pow(i,3);       
}        
cout <<"The sum of sum1 is " <<sum1 << endl; 



system("pause");
return 0;  

}   
