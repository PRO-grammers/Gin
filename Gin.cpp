#include "stdafx.h"
#include "Deck.h"
#include "Gin.h"
#include "Player.h"

using namespace std;

//The constructor sets each player for 10 cards.
Gin::Gin(){
	for(int i = 0; i < HAND_SIZE; i++){
		player[0].GetCard();
		player[1].GetCard();
	}
}

//It runs the game and calls both players' turns. If a player knocks then it calls SumPoints()
void Gin::RunGame(){
	int turn = -1;
	do{
		turn++;
		cout << "Player " << turn%2+1 << "'s turn!" << endl;
		player[turn%2].PlayerTurn();
		cout << endl << endl << endl << endl;
	}while(!player[turn%2].WannaKnock());

	SumPoints();
	return;
}

//This will take the sum of each player's points, compare them and determine a winner.
void Gin::SumPoints(){
	int one = player[0].Sum();
	int two = player[1].Sum();

	cout << "Player one's score: " << one << endl;
	cout << "Player two's score: " << two << endl;

	if(one < two){
		cout << "Player One wins!!" << endl;	//Do something fancy
	}else if(one > two){
		cout << "Player Two wins!!" << endl;
	}else
		cout << "Players Tie:]   A little boring and probably contrived. " << endl;
	return;
}

