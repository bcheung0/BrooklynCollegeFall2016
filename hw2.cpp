#include <iostream>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <string>

using namespace std;
void rules(void);
void goFirst(string &,string &);
int randomCard(string);
string play(string, string, int[]);
void checkPos(int &,int []);

const int SWITCH = 11;
const int LOSE= 0;
const int SIZE=28;

int main(){

	srand(time(NULL));
	
	
	rules();
	string player1;
	string player2;
	string winner;
	
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
	
	
	goFirst(player1,player2);
	
	winner=play(player1,player2,board);
	cout << "The winner is: " << winner<< endl;
}

// Prints Rules
void rules(){ 
	cout << "			RULES" << endl <<"1. FIRST PLAYER TO REACH HOME WINS" << endl << "2. PLAYERS WILL DRAW CARDS TO MOVE FOWARDS AND ENCOUNTER OBSTACLES" << endl <<
			"3. OBSTACLES MOVE THE PLAYER A CERTAIN AMOUNT OF SQAURES DEPENDING ON THE NUMBER LANDED ON" << endl << endl;
}

// Chooses a random card 
int randomCard(string a){

	int deck[10] = {1,1,2,2,3,3,4,4,LOSE,SWITCH};
	int ran = rand()%10;
	int insert=deck[ran];
	if(insert==10){
		cout << "Sorry! " << a << " Lose a Turn. Moved 0 Spaces" << endl;
		return 0;
	}
	else if(insert==SWITCH){
		cout << a << " Switched with another player!" << endl;
		return 11;
	}
	else
		return insert;
}

//Decides who go first
void goFirst(string &name1,string &name2){
	
	cout<< "Enter PLAYER1'S FIRST NAME: " << endl;
	cin >> name1;
	cout << "Player1 is: "<< name1 << endl << endl;
	
	cout << "Enter PLAYER2's FIRST NAME: " << endl;
	cin >> name2;
	cout << "Player2 is: " << name2 << endl << endl;
	
    string temp;
	if(name1.size()>name2.size()){ // If name one is larger then name 2
        name1=temp;
		name1=name2;
		name2=temp;	
	}
	

}

// Checks position 
void checkPos(int &a, int b[]){
	
	if(b[a]!=0){
		cout << "You are at position: " << a << " and you've reached an obstacle, MOVE BACKWARDS: " << b[a] << " SPACES " << endl;	
		a=a-b[a];
		cout << "You are now at position: " << a << endl << endl;
	}
	else{
		cout << "You are at position: " << a << endl << endl;
	}
	
}


// Combines all the functions into a game
string play(string playerone,string playertwo,int c[]){
	int countp1=0;
	int countp2=0;
	cout << playerone << " will go first." << endl << endl;

	while(countp1 < (25) && countp2 <(25)){
		int temp;
		int card1;
		int card2;
		card1=randomCard(playerone);
	
		if(card1==11){
		temp=countp1;
		countp1=countp2;
		countp2=temp;	
		}
		else{
		countp1=countp1+card1;
		cout << playerone << " moved " << card1 << " spaces." << endl; 	
		}
		
		checkPos(countp1,c);
		
		if(countp1>25){
			break;
			
		}
		
		card2=randomCard(playertwo);
		if(card2==11){
		temp=countp2;
		countp2=countp1;
		countp1=temp;	
		}
		else{
		countp2=countp2+card2;
		cout << playertwo << " moved " << card2 << " spaces." << endl; 	
		checkPos(countp2,c);
		if(countp2>25){
			break;
		}
	}
	
		
}	

if(countp1>countp2){
	return playerone;
}
else 
	return playertwo;
	
	
}



