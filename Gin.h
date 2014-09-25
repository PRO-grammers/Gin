
#pragma once;
#include "stdafx.h"

#include "Deck.h"
#include "Card.h"
#include "Player.h"

class Gin
{
public:
	friend void RunGame();
	int SumPoints(vector<Card> tmp);
private:
	Player player1,player2;
};
