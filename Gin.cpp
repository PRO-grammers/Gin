 #include "stdafx.h"
 #include "Gin.h"
 
 void Gin::RunGame()
 {
 	player[0].PlayerTurn();
 	while(WannaKnock()==false)
 	{
 	 player[1].PlayerTurn();
 	 player[0].PlayerTurn();
 	}
 }
 
 int Gin::SumPoints()
 {
 	
 }
