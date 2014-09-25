/* 
Author:	Logan MacKenzie, Nick Fryer, Zachary Kuligin, Guilherme Pereira
Course:	Comp 220, Computer Programming II
Date:	20 September 2014
Description:	This file contains the definition of the datatype Deck
		Deck simulates a playing deck of 52 unique cards.

	This file provides the definition of type Deck and the global constant DECK_SIZE.
*/
#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <stack>

#include "Card.h"

using namespace std;

const int DECK_SIZE = 52;

class Deck
{
public:
	Deck(void);
	~Deck(void);

	void Shuffle();
	Card DealCard();	//returns card off top of deck
	Card BottomCard();	//returns card off discard pile
	Card PeekPile();	//returns card on discard pile, without removing it.

	void GetCard(Card card);	//Places card on bottom of deck
	void DiscardCard(Card card); //Places card on top of discard pile.

	void CheckDeck();
	void ResetDeck();
	void Print();

private:
	void Swap(Card& x, Card& y);

	vector<Card> deck;	//This is the deck
	stack<Card> pile;	//This is the discard pile.
};

