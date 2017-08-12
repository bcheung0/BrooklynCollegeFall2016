#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;


class Final{
	public:
	double avgGrade;
	char letterGrade;	
};

class Student{
	public: 
	string name;
	
}; 

class Grades{
	public:
	int grade[3];
};

class Group{
	public: 
	Student name; 
	Grades numbers;
	Final fin;
};

int main(){
	ifstream infile("data.txt"); 
	
	cout << fixed << setprecision(2);
	
	string first;
	string last;
	int grade1;
	int grade2;
	int grade3;
	
	Group identity1;
	
	while(infile >> first >> last >> grade1 >> grade2 >> grade3){
		
		
		string combo=first+" "+last; 
		identity1.name.name=combo;
		identity1.numbers.grade[0]=grade1;
		identity1.numbers.grade[1]=grade2;
		identity1.numbers.grade[2]=grade3;
		
		cout << identity1.name.name << " ";
		double avg=0;
		for(int i=0;i<3;i++){
			
			avg=avg+(identity1.numbers.grade[i]/3.0);
			cout << identity1.numbers.grade[i] << " ";
	}
	identity1.fin.avgGrade=avg;
	
		if(avg>=90){
			identity1.fin.letterGrade='A';	
		}
		else if(avg>=80){
			identity1.fin.letterGrade='B';
		}
		else if(avg>=70){
			identity1.fin.letterGrade='C';
		}
		else{
			identity1.fin.letterGrade='F';
		}
		
		cout << "        AVG: "<< identity1.fin.avgGrade << " ";
		cout << "GRADE:  " <<identity1.fin.letterGrade << endl;
		}	
	
}


/*		OUTPUT 

Brian Cheung 75 100 85    AVG: 86.67 GRADE:  B			75+100+85=260	260/3=86.67
Jerry Lu 50 0 25         AVG: 25.00 GRADE:  F			50+25+0=75		75/3=25

--------------------------------
Process exited after 0.01031 seconds with return value 0
Press any key to continue . . .


*/
