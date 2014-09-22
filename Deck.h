// Author:	Logan MacKenzie
// Course:	Comp 220, Computer Programming II
// Date:	20 September 2014
// Description:	This file contains the definition of the datatype Deck
//				Deck simulates a playing deck of 52 unique cards.

#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

#include "Card.h"

using namespace std;

const int DECK_SIZE = 52;

class Deck
{
public:
	Deck(void);
	~Deck(void);

	void Shuffle();
	Card DealCard();
	void GetCard(Card card);

	void Print();

private:
	void Swap(Card x, Card y);

	vector<Card> deck;

};

