/*
Authors: Nick Fryer, Zach Kuligin, Guilherme, Pereira, Logan MacKenzie
Class: Computer Programming II
Date: September 24, 2014
Description: This is the header file for the class Player which represents a player with
             A hand of cards.

*/

#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Deck.h"

//set player hand size to 10 cards
const int HAND_SIZE = 10;

//this class deals with each player's turn
class Player
{
public:
	Player();

	void PlayerTurn();
	void PrintHand();

	void SelectCard();
	void GetCard(Card card);
	void PickUpDiscard();

	void DiscardCard(Card& card);

	void Knock();
	bool CanKnock();

	bool FindSets();
	void SortBySuit(/*vector<Card>& cards*/);
	void SortByNumber(int start, int end);
	void SortIntoSets();
	bool DoesCardFit(Card card);

	bool FindRuns();

	bool GotGin();


private:
	void Swap(Card& one, Card& two);

	Card hand[HAND_SIZE];
	int handSize;
	vector<Card> sets[4];	//4 arrays because at most you can have 3 sets and then the unmatched cards.

	static Deck deck;
};

#endif
