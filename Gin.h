
#pragma once;
#include "stdafx.h"

#include "Deck.h"
#include "Card.h"
#include "Player.h"

class Gin
{
public:
	friend void RunGame();
private:
	Player players[2];
};
