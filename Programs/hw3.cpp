 #include <iostream>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <string>

using namespace std;

void rules(void);
int randomCard(int []);
int pickCard(int [],int );
void switchPlaces(int,int []);
void numPlayers(string [],int &);
void printArr(int [],int);
void printArrString(string [],int);
void nameSort(string [],int);
bool checkWinner(int [],int);
string play(string [],int [], int [],int,int []);

int main(){
	srand(time(NULL));
	
	rules();
	
	const int SWITCH=11;
	const int LOSE=0;
	const int BOARDSIZE=28;
	int SIZE;
	
	
	
	int deck[10]={1,1,2,2,3,3,4,4,SWITCH,LOSE};
	randomCard(deck);
	//printArr(deck,10);
	
	int board[SIZE];
	for(int i=0;i<SIZE;i++){
		board[i]=0;
	}
	
	board[0]=0;
	board[4]=1;
	board[2]=2;
	board[9]=3;
	board[11]=1;
	board[16]=2;
	board[20]=3;
	board[23]=1;
	
	cout << "How many players are you using?" << endl;
	cin >> SIZE;
	string players[SIZE];
	int count[SIZE];
	
	for(int i=0;i<SIZE;i++){
		count[i]=0;
	}
	numPlayers(players,SIZE); 
	nameSort(players,SIZE);
	
	//cout << endl;
	//printArrString(players,SIZE);
	
	string winner;
	winner= play(players,board,count,SIZE,deck);
	cout << endl << endl;
	cout << winner << " has won the game!!!" << endl;
	
	
}

// Prints Rules
void rules(){ 
	cout << "			RULES" << endl <<"1. FIRST PLAYER TO REACH HOME WINS" << endl << "2. PLAYERS WILL DRAW CARDS TO MOVE FOWARDS AND ENCOUNTER OBSTACLES" << endl <<
			"3. OBSTACLES MOVE THE PLAYER A CERTAIN AMOUNT OF SQAURES DEPENDING ON THE NUMBER LANDED ON" << endl << endl;
}

// Shuffles deck
int randomCard(int a[]){

	int count=0;
	int random= rand()%5+2;
	for(int i=0;i<random;i++){
		int randomNum;
		int temp;
		randomNum=rand()%10;
		temp=a[i];
		a[i]=a[randomNum];
		a[randomNum]=temp;	
		}
	
}

// Prints an array 
void printArr(int a[], int b){
	for(int i=0;i<b;i++){
		cout << a[i] << endl; 
	}
}

void printArrString(string a[], int b){
	for(int i=0;i<b;i++){
		cout << a[i] << endl; 
	}
}

// Picks a card
//int pickCard(int deck[],int index){
//	return deck[index];
//}

// Chooses the amount of players
void numPlayers(string a[],int &b){
	
	for(int i=0;i<b;i++){
		cout << "What is the name of PLAYER: " << i+1 << " ?" << endl;
		cin >> a[i];
	}	
	cout << endl;
}


// Sorts the name
void nameSort(string a[],int b){
	
	bool swap;
	int pass=0;
	string temp;
	do{
		pass++;
		swap=false;
		for(int i=0;i<b-pass;i++){
			
			if(a[i].size() > a[i+1].size()){ // change < to > for asending order
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
				swap=true;
			}
		}
	}while(swap);
	
}

void switchPlaces(int a,int b[],int c){
	//current pos,board of pos,size of array
	int high=b[0];
	
	int pos;
	
	for(int i=1;i<c;i++){
		                                                                                                                                             
		if(b[i]>high){
			high=b[i];
			pos=i;
		}	
	}
		
		int temp=a;
		b[a]=b[pos];
		b[pos]=b[temp];
		
	
	for(int i=0;i<c;i++){
		cout << b[i] << " ";
	}
	//cout << "POS: " << a << endl;
}

	
bool checkWinner(int a[],int b){
	for(int i=0;i<b;i++){
		if(a[i]==25);
		return true;
	}
}	




string play(string a[],int b[],int c[],int d,int e[]){
	
	// names , board, count, size, deck
	int count=0;
	int count2=0;
	int index=0;
	
	while(c[count]!=25){
		int card;
		card=e[count2];
		
		if(card==11){
			switchPlaces(c[count],c,d);
			cout << a[count]<< " SWITCHED POSITIONS with the furthest player" << endl;
			cout << "You are now at position: " << c[count] << endl << endl;;
	
			count++;
			if(count>(d-1)){
				count=0;
			}
			
			count2++;
			if(count2>9){
				randomCard(e);
				count2=0;	
			}
	
			
		}
		else{
				if((c[count]+card)>25){
				//c[count]=c[count]-card;
				c[count]-=card;
				cout << "You PASSED HOME AND MOVED BACK TO: " << c[count] << endl;
				}
				
			
				c[count]=c[count]+card;
				
				if(c[count]==b[count]){
					c[count]=c[count]-b[count];
					cout <<a[count] <<" MOVED BACK: " << b[count] << " SPACES" << endl;
				}
				else{
				cout << a[count] <<" MOVED: " << card << " SPACES" << endl;
				cout << "You are now at position: " << c[count] << endl<< endl;	
				}
				
			
				
				if(c[count]==25){
				break;
				}	
			}			
			
			// resets count
			count++;
			if(count>(d-1)){
				count=0;
			}
			count2++;
			if(count2>9){
			randomCard(e);
			count2=0;	
			}
			
		}
		for(int i=0;i<d;i++){
			if(c[count]==25){
				return a[count];
			}
		}
}








