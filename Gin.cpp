#include "stdafx.h"
#include "Deck.h"
#include "Gin.h"
#include "Player.h"
 
void Gin::getPlayer1(Player first_player){
	player1 = first_player;
}

void Gin::getPlayer2(Player second_player){
	player2 = second_player;
}

 void Gin::RunGame()
 {
 	player1.PlayerTurn();
 	while(WannaKnock()==false)
 	{
 	 player2.PlayerTurn();
 	 player1.PlayerTurn();
 	}
 	return;
 }
 
 int Gin::SumPoints(vector<Card> tmp)
 {
 	
 }
