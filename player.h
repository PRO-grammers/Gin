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
	void FindSets(Value a[],Value b[],Value c[]);
	bool GotGin(player p);
	void get_set1(Value set1[])
	void get_set2(Value set2[])
	void get_set3(Value set3[])
private:
	vector<Card> hand;
	Value set1[4];
	Value set2[4];
	Value set3[3];
};

#endif
