#include <iostream>
#include <fstream>
using namespace std;

void printHeading(void);
void readID(int &);


	ofstream fout;
	ifstream iout;
	
	
int main(){
	
	iout.open("grades.txt");
	int trailer=1;
	int grade1=0;
	int grade2=0;
	int grade3=0;
	int count=0;
	char letterGrade;
	
	printHeading();
	readID(trailer);
	//cout << readID() << endl;	
	
	while(trailer!=-1){
		
		
		cout << "Enter -1 to Stop" << endl;
		cin >> trailer;
	}
	
	}
	
		


void printHeading(){
    cout << "ID\tG1\tG2\tG3\tAVG\tL" << endl ; 
}

void readID(int &a){
	
	iout >> a;
	
	/*
	int a,b,c,d;
	while(iout >> a >> b >> c >> d){
	// iout >> a;
	cout << a << "\t" << b << "\t" << c << "\t" << d << endl ;
	}
	*/
	

	
}
	

// findAvg
		
		
	
	
 



