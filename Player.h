#ifndef ___PLAYER_H
#define ___PLAYER_H

#include "Card.h"
#include "Deck.h"


const int HAND_SIZE = 10;
const int NUM_SETS = 3;

class Player
{
public:
	Player();

	void PlayerTurn();
	void PrintHand();

	void SelectCard();
	void GetCard();
	void PickUpDiscard();
	void DiscardCard(Card& card);



	void SortIntoSets();
	void SortBySuit();
	void SortByNumber(int start, int end);
	bool DoesCardFit(Card card);

	void MatchCards();
	void FindSets(int card, int& setNum);
	void FindRuns(int card, int& setNum);
	bool CheckConflicts(vector<Card> tmp);
	void ReportErrors(vector<Card> tmp, int error[]);
	void FixErrors(vector<Card> tmp, int error[]);



private:
	void Swap(Card& one, Card& two);

	Card hand[HAND_SIZE];
	int handSize;
	vector<Card> sets[4];	//4 arrays because at most you can have 3 sets and then the unmatched cards.

	static Deck deck;
};

#endif
