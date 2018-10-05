/*
BRIAN CHEUNG
CISC 1110 
*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void readFile(string [], int &);
void printArr(string[],int);
void breakUp(string[],string [],string[],int);
string form1(string[],string[],int,int);
void printChart(string[],string[],string[],string[],int);
bool findLast(string[],string,int);
void BubbleSort(string[],int);

int main(){
	int count=0;
	string arrFL[5]; // First Last
	readFile(arrFL,count);
	
	string lastName[count]; // Last
	string firstName[count]; // First
	
	for(int i=0;i<count;i++){
		breakUp(arrFL,lastName,firstName,count); 
	}
	
	string modFirstLast[count];
	
	for(int v=0;v<count;v++){
		modFirstLast[v]=form1(arrFL,lastName,count,v);
		
	}
	printArr(arrFL,count);
	printArr(lastName,count);
	
	
	printChart(arrFL,firstName,lastName,modFirstLast,count);
	string input;
	
	cout <<  endl <<"Last Name? (Capital letters count!)" << endl;
	cin >> input;
	
	if(findLast(lastName,input,count)){ 
		cout << input << " was found in the array" << endl << endl; 
		
	}
	else{
		cout << input << " was NOT found in the array" << endl << endl;
	}
	
	printArr(lastName,count); 
	BubbleSort(lastName,count);
	cout << endl;
	printArr(lastName,count);
	
}
	
	
void readFile(string a[],int &b){
	string line;
	ifstream infile("names.txt");
	b=0;
	while(getline(infile,line)){
		a[b]=line;
		b++;
	}
	infile.close();
}

void printArr(string a[],int b){
	for(int i=0;i<b;i++){
		cout << a[i] << endl;
	}
}

void breakUp(string a[],string b[],string d[],int c){
	for(int i=0;i<c;i++){
		string one=a[i];
		int pos;
		pos=one.find(" ",0);
		b[i]=one.substr(pos+1);	
		d[i]=one.substr(0,pos);
		}
	
}
string form1(string a[],string b[],int c,int d){
	for(int i=0;i<c;c++){
		
		string name=a[d];
		string lines="---";
		
		int pos;
		pos=name.find(" ",0);
		name.erase(pos,name.length());
		name.insert(name.length(),lines);
		name.insert(name.length(),b[d]);
		return name;	
	}
}

void printChart(string a[],string b[],string c[], string d[],int e){
	for(int i=0;i<e;i++){
		cout << a[i] + "   " + c[i] + "," + b[i] + "   " + d[i] << endl; 
	}
}

bool findLast(string a[],string b, int c){ 
	for(int i=0;i<c;i++){
		if(a[i]==b){
			return true;
		}
	}
	return false;	
}

void BubbleSort(string a[],int b){
	
	bool swap;
	int pass=0;
	string temp;
	do{
		pass++;
		swap=false;
		for(int i=0;i<b-pass;i++){
			if(a[i] > a[i+1]){ // change < to > for asending order
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
				swap=true;
			}
		}
	}while(swap);
	
}


/*		INPUT 

Brian Cheung
Amanda Guan
Max To
Matthew Cheung
Tommy Lee
Cheung
Guan
To
Cheung
Lee
Brian Cheung   Cheung,Brian   Brian---Cheung
Amanda Guan   Guan,Amanda   Amanda---Guan
Max To   To,Max   Max---To
Matthew Cheung   Cheung,Matthew   Matthew---Cheung
Tommy Lee   Lee,Tommy   Tommy---Lee

Last Name? (Capital letters count!)
Lee
Lee was found in the array			FOUND IN THE ARRAY

Cheung			Unsorted
Guan
To
Cheung
Lee

To				Sorted
Lee
Guan
Cheung
Cheung

--------------------------------
Process exited after 11.18 seconds with return value 0
Press any key to continue . . .


Brian Cheung
Amanda Guan
Max To
Matthew Cheung
Tommy Lee
Cheung
Guan
To
Cheung
Lee
Brian Cheung   Cheung,Brian   Brian---Cheung
Amanda Guan   Guan,Amanda   Amanda---Guan
Max To   To,Max   Max---To
Matthew Cheung   Cheung,Matthew   Matthew---Cheung
Tommy Lee   Lee,Tommy   Tommy---Lee

Last Name? (Capital letters count!)
Tom
Tom was NOT found in the array			NOT FOUND IN THE ARRAY 

Cheung
Guan
To
Cheung
Lee

To
Lee
Guan
Cheung
Cheung

--------------------------------
Process exited after 3.313 seconds with return value 0
Press any key to continue . . .

*/


