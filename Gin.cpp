 #include "stdafx.h"
 #include "Gin.h"
 
 void Gin::RunGame()
 {
 	player1.Player.PlayerTurn();
 	while(Player.WannaKnock()==false)
 	{
 	 player2.Player.PlayerTurn();
 	 player1.Player.PlayerTurn();
 	}
 }
 
 int Gin::SumPoints()
 {
 	
 }
