#ifndef ___PLAYER_H
#define ___PLAYER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "card.h"
#include "Deck.h"

const int HAND_SIZE = 10;

class player
{
public:
	friend ostream &operator<<(ostream& cout, player &p);
	   void PlayerTurn(player p);
	friend void PrintHand(player p);
	void SelectCard(char ans);
	void DiscardCard(player p, Card card);
	void FindSets();
	bool GotGin(player p);
private:
	vector<Card> hand;
};

#endif
