#ifndef ___CARD_H
#define ___CARD_H

#include <string>
using namespace std;

enum Suit {clubs, diamonds, hearts, spades};
enum Value {two, three, four, five, six, seven, eight, nine, ten, jack, king, queen, ace};

class Card {
public:
	Card (Value faceValue=two, Suit suit = clubs):
		suit (suit), faceValue(faceValue) {}
	Suit getSuit() { return suit; }
	Value getValue() { return faceValue; }
	static string suitName (Suit s);
	static string valueName (Value v);
	string name() { return valueName (faceValue) + " of " + suitName(suit);}
private:
		Suit suit;
		Value faceValue;
};


#endif
