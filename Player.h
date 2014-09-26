/*
Authors: Nick Fryer, Zachary Kuligin, Guilherme Pereira, Logan MacKenzie
Class: Comp 220 B, Computer Programming II
Date: September 25, 2014
Description: This is the header file for the Player class which 
	represents a player, with a hand of cards.

	This file provides the definition of the type Player and Matches
	and the global constant HAND_SIZE.

*/
#ifndef ___PLAYER_H
#define ___PLAYER_H

#include "Card.h"
#include "Deck.h"


const int HAND_SIZE = 10;

typedef vector<Card> Matches;

class Player{
public:
	Player();

	void PlayerTurn();
	bool WannaKnock();
	int Sum();

private:
	void PrintHand();
	void PrintSets();
	void PrintRuns();

	void SelectCard();
	void GetCard();
	void PickUpDiscard();
	void DiscardCard(Card& card);

	void SortIntoSets();
	void SortBySuit();
	void SortByNumber(int start, int end);

	void MatchCards();
	void FindSets();
	void FindRuns();
	void FindUnmatched();

	void CheckConflicts();
	int CardInRun(Card card);
	int CardInSet(Card card);
	void FixConflicts(int setNum, int runNum);

	void Swap(Card& one, Card& two);

	Card hand[HAND_SIZE];
	int handSize;

	vector<Matches> runs;
	vector<Matches> sets;
	Matches unmatched;

// The deck is static so that both players can access the same deck.
	static Deck deck;
};

#endif
