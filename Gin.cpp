 #include "stdafx.h"
 #include "Gin.h"
 #include "Player.h"
 
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
