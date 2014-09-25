#pragma once;
#include "stdafx.h"

#include "Deck.h"
#include "Card.h"
#include "Player.h"

class Gin: public Player
{
public:
	void RunGame();
	int SumPoints(vector<Card> tmp);
	void getPlayer1(Player first_player);
	void getPlayer2(Player second_player);

private:
	Player player1, player2;
};
