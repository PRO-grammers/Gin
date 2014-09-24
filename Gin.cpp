 #include "stdafx.h"
 #include "Gin.h"
 
 void Gin::RunGame()
 {
 	int turn;
 	player[0].PlayerTurn();
 	while(Knock()==false)
 	{
 		if(player[0].DiscardCard())
 		{
 			player[1].PlayerTurn();
 		}
 		if(player[1].DiscardCard())
 		{
 			player[0].PlayerTurn();
 		}
 	}
 }
 
 int Gin::SumPoints()
 {
 	
 }
