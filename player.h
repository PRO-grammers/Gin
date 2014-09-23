#ifndef ___PLAYER_H
#define ___PLAYER_H

#include <iostream>
#include <cstdlib>
#include <cmath>
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
	void FindSets(Card a[],Card b[], Card c[]);
	bool GotGin(player p);
	void get_set1(Card set1[])
	void get_set2(Card set2[])
	void get_set3(Card set3[])
private:
	vector<Card> hand;
	Card set1[4];
	Card set2[4];
	Card set3[3];
};

#endif
