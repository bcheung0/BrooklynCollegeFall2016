#include <iostream>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <string>

using namespace std;

void rules(void);
int randomCard(int []);
int pickCard(int [],int );
void switchPlaces(int,int [],int);

void numPlayers(string *arr,int );

void printArr(int [],int);
void printArrString(string [],int);

void nameSort(string *,int);

bool checkWinner(int [],int);
string play(string [],int [], int [],int,int [],int);

int main(){
	srand(time(NULL));
	
	rules();
	
	const int SWITCH=11;
	const int LOSE=0;
	const int GOAGAIN=4;
	//const int BOARDSIZE=28;
	
	int boardSize;
	cout << "What should the board size be? (OVER 25)" << endl;
	cin >> boardSize;
	
	int *board;
	board=new int[boardSize];
	
	int obst;
	cout << "How many obstacles do you want on the board?" << endl;
	cin >> obst;
	
	
	
	for(int i=0;i<boardSize;i++){
		*(board+i)=0;
	}
	
	int maxObst;
	cout << "What is the largest obstacle you want on the board?(1-4)" << endl;
	cin >> maxObst;
	//maxObst++;
	for(int z=0;z<obst;z++){
		board[rand()%boardSize]=rand()%maxObst+1;
	}
	//printArr(board,boardSize);
	
	//int board[SIZE]
	
	int deck[10]={1,1,2,2,3,3,4,4,SWITCH,LOSE};
	randomCard(deck);
	//printArr(deck,10);
	
	
	int SIZE;
	cout << "How many players are you using?" << endl;
	cin >> SIZE;
	
	string *players;
	players=new string[SIZE];
	
	int *count;
	count=new int[SIZE];
	
	
	//string players[SIZE];
	//int count[SIZE];
	
	for(int i=0;i<SIZE;i++){
		*(count+i)=0;
	}
	numPlayers(players,SIZE); 
	nameSort(players,SIZE);
	
	cout << endl;
	//printArrString(players,SIZE);
	
	string winner;
	winner= play(players,board,count,SIZE,deck,boardSize);
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


// Chooses the amount of players
void numPlayers(string *a,int b){
	
	for(int i=0;i<b;i++){
		cout << "What is the name of PLAYER: " << i+1 << " ?" << endl;
		cin >> *(a+i);
	}	
	cout << endl;
}


// 1) Sorts the name without using braces notation
void nameSort(string *a,int b){
	
	bool swap;
	int pass=0;
	string temp;
	do{
		pass++;
		swap=false;
		for(int i=0;i<b-pass;i++){
			
			if((*((a+i).length)) > (*(a+i+1))) { // change < to > for asending order
				temp=*(a+i);
				*(a+i)=(*(a+i+1));
				*(a+i+1)=temp;
				swap=true;
			}
		}
	}while(swap);
	
}

// Switches name without using braces notation
void switchPlaces(int a,int b[],int c){
	//current pos,board of pos,size of array
	int temp=0;
	int pos;
	
	for(int i=0;i<(c-1);i++){
		if(b[i]>=b[i+1]){
			temp=i;
		}
	}
		int temp2=pos;
	b[pos]=b[a];
	b[a]=temp2;
	//cout << "POS: " << a << endl;
	}
	
bool checkWinner(int a[],int b){
	for(int i=0;i<b;i++){
		if(a[i]==25);
		return true;
	}
}	



string play(string a[],int b[],int c[],int d,int e[],int f){
	
	// names , board, count(player[number]), size, deck, SIZE OF ARRAY
	int count=0;
	int count2=0;
	int index=0;
	
	while(c[count]!=f){
		int card;
		card=e[count2];
		
		if(card==11){
			switchPlaces(c[count],c,f);
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
			
				if((c[count]+card)>f){
				c[count]=c[count]-card;
				//c[count]=c[count]-card;
				cout << "You PASSED HOME AND MOVED BACK TO: " << c[count] << endl;
				}
				
				else{
					
					c[count]=c[count]+card;
					 
					if( (b[c[count]]>0) && (b[c[count]] >4) ){ //  player positon == 
					c[count]=c[count]-b[count];
					cout <<a[count] <<" MOVED BACK: " << b[count] << " SPACES" << endl;
					cout << "You are now at position: " << c[count] << endl << endl; 
				}
					else if(b[count]==4){
					count2++;
					card=e[count2];
					c[count]=c[count]+card;
					
					cout << a[count] <<" MOVED for the 2nd TIME: " << card << " SPACES" << endl;
					cout << "You are now at position: " << c[count] << endl<< endl;	
				}
					else{
				cout << a[count] <<" MOVED: " << card << " SPACES" << endl;
				cout << "You are now at position: " << c[count] << endl<< endl;	
					}
					
				if(c[count]==f){
					break;
				}		
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
			if(c[count]==f){
				return a[count];
			}
		}
}

/*
                        RULES
1. FIRST PLAYER TO REACH HOME WINS
2. PLAYERS WILL DRAW CARDS TO MOVE FOWARDS AND ENCOUNTER OBSTACLES
3. OBSTACLES MOVE THE PLAYER A CERTAIN AMOUNT OF SQAURES DEPENDING ON THE NUMBER LANDED ON

What should the board size be? (OVER 25)
30
How many obstacles do you want on the board?
5
What is the largest obstacle you want on the board?(1-4)
4
How many players are you using?
4
What is the name of PLAYER: 1 ?
Brian
What is the name of PLAYER: 2 ?
Jacky
What is the name of PLAYER: 3 ?
Bo
What is the name of PLAYER: 4 ?
Matthew


Bo MOVED: 2 SPACES
You are now at position: 2

Brian MOVED: 2 SPACES
You are now at position: 2

Jacky MOVED: 1 SPACES
You are now at position: 1

Matthew MOVED: 3 SPACES
You are now at position: 3

Bo MOVED: 4 SPACES
You are now at position: 6

Brian MOVED: 3 SPACES
You are now at position: 5

Jacky MOVED: 1 SPACES
You are now at position: 2

Matthew MOVED: 4 SPACES
You are now at position: 7

Bo SWITCHED POSITIONS with the furthest player
You are now at position: 7

Jacky MOVED: 3 SPACES
You are now at position: 5

Matthew MOVED: 4 SPACES
You are now at position: 11

Brian MOVED: 2 SPACES
You are now at position: 7

Jacky MOVED: 1 SPACES
You are now at position: 6

Matthew MOVED: 3 SPACES
You are now at position: 14

Brian MOVED: 2 SPACES
You are now at position: 9

Jacky SWITCHED POSITIONS with the furthest player
You are now at position: 6

Bo MOVED: 4 SPACES
You are now at position: 4

Brian MOVED: 0 SPACES
You are now at position: 9

Jacky MOVED: 2 SPACES
You are now at position: 8

Matthew MOVED: 2 SPACES
You are now at position: 16

Bo MOVED: 1 SPACES
You are now at position: 5

Brian MOVED: 3 SPACES
You are now at position: 12

Jacky MOVED: 1 SPACES
You are now at position: 9

Matthew MOVED: 3 SPACES
You are now at position: 19

Bo SWITCHED POSITIONS with the furthest player
You are now at position: 0

Jacky MOVED: 0 SPACES
You are now at position: 9

Matthew SWITCHED POSITIONS with the furthest player
You are now at position: 19

Brian MOVED: 2 SPACES
You are now at position: 14

Jacky MOVED: 1 SPACES
You are now at position: 10

Matthew MOVED: 3 SPACES
You are now at position: 22

Brian MOVED: 3 SPACES
You are now at position: 17

Jacky MOVED: 4 SPACES
You are now at position: 14

Matthew MOVED: 4 SPACES
You are now at position: 26

Brian MOVED: 4 SPACES
You are now at position: 30 



Brian has won the game!!!
*/

