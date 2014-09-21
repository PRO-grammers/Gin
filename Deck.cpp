/*
  Author:  Logan MacKenzie
  Course:  Comp 220, Computer Programming II
  Date:    20 September 2014
  Description:  This file implements the Deck class
*/

#include "stdafx.h"
#include "Deck.h"

// Initializes deck with all the cards.
// The deck is initialized organized by suit.
Deck::Deck(void)
{
	Card tmp;
	for(unsigned int suit = 0; suit < 4; suit++){
		for(unsigned int value = 0; value < 13; value++){
			deck.push_back(Card(Value(value),Suit(suit)));
		}
	}
}

// Clears the deck.
Deck::~Deck(void)
{
	deck.clear();
}


// Randomly selects cards in the deck and swaps them
// To create a random order of cards.
void Deck::Shuffle(){
	int j, k;
	Card ctmp;
	for(unsigned int i = 0; i < deck.size(); i++){
		j = rand() % deck.size();
		k = rand() % deck.size();
		Swap(deck[j],deck[k]);
	}
	return;
}



// Returns the card on the top of the deck
// And removes that card from the deck.
Card Deck::DealCard(){
	Card tmp = deck.back();
	deck.pop_back();
	return tmp;	
}


// Places the card back at the bottom of the deck.
// Note: the bottom of the deck is represented by the front of the vector.
void Deck::GetCard(Card tmp){
	deck.insert(deck.begin(), tmp);
	return;
}

// Sequentially prints every card in the deck
void Deck::Print(){
	Card tmp;
	for(unsigned int i = 0;  i < deck.size(); i++){
		cout << deck[i].name() << endl;
	}

	return;
}

// Private function, Not needed outside class.
// Swaps two cards
void Deck::Swap(Card x, Card y){
	Card card = x;
	x = y;
	y = card;
	return;
}


