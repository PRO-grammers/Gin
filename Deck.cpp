/*
  Author:  Logan MacKenzie
  Course:  Comp 220, Computer Programming II
  Date:    20 September 2014
  Description:  This file implements the Deck class
*/

#include "stdafx.h"
#include "Deck.h"
#include <ctime>

using namespace std;
// Initializes deck with all the cards.
// The deck is initialized organized by suit.
Deck::Deck(void){
	srand(time(NULL));
	Card tmp;
	for(unsigned int suit = 0; suit < 4; suit++){
		for(unsigned int value = 0; value < 13; value++){
			deck.push_back(Card(Value(value),Suit(suit)));
		}
	}
	Shuffle();
	pile.push(deck.back());
	deck.pop_back();
}

// Clears the deck.
Deck::~Deck(void){
	deck.clear();
}


// Randomly selects cards in the deck and swaps them
// To create a random order of cards.
void Deck::Shuffle(){
	int j, k;
	for(unsigned int i = 0; i < deck.size(); i++){
		j = rand() % deck.size();
		k = rand() % deck.size();
		Swap(deck[j],deck[k]);
	}
	return;
}



// Returns the card on the top of the deck
// And removes that card from the deck.
// DealCard also checks if the deck is empty and 
// has it refilled if it is.
Card Deck::DealCard(){
	if(deck.empty())
		ResetDeck();
	Card tmp = deck.back();
	deck.pop_back();
	return tmp;	
}

// Returns card on the bottom of the deck
// This is the card face up on the discard pile.
Card Deck::BottomCard(){
	Card tmp = pile.top();
	pile.pop();
	return tmp;
}

// Returns the card off the discard pile, without removing it.
Card Deck::PeekPile(){
	return pile.top();
}


// Places the card back at the bottom of the deck.
// Note: the bottom of the deck is represented by the front of the vector.
void Deck::GetCard(Card tmp){
	deck.insert(deck.begin(), tmp);
	return;
}

//Places card on the top of the discard pile.
void Deck::DiscardCard(Card card){
	pile.push(card);
	return;
}

// CheckDeck checks to see if the deck is empty
// If it is it calls ResetDeck to refill it.
// If the deck is not empty, CheckDeck does nothing.
void Deck::CheckDeck(){
	if(deck.empty())
		ResetDeck();
	return;
}

// ResetDeck refills the deck with the cards from the discard pile
// and Shuffles them.
void Deck::ResetDeck(){
	for(int i = pile.size(); i > 0; i--){
		deck.push_back(pile.top());
		pile.pop();
	}
	Shuffle();
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
void Deck::Swap(Card& x, Card& y){
	Card card = x;
	x = y;
	y = card;
	return;
}



