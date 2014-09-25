#include "stdafx.h"
#include "Deck.h"
#include "Gin.h"
#include "Player.h"

using namespace std;

Gin::Gin(){
	
}

void Gin::RunGame(){
	for(int i = 0; player[i%2].WannaKnock(); i++){
		player[i].PlayerTurn();
	}
	SumPoints();
	return;
}

void Gin::SumPoints(){
	int one = player[0].Sum();
	int two = player[1].Sum();

	if(one > two){
		cout << "Player One wins!!" << endl;	//Do something fancy
	}else if(one < two){
		cout << "Player Two wins!!" << endl;
	}else
		cout << "Players Tie:}   A little boring and probably contrived. " << endl;
	return;
}

