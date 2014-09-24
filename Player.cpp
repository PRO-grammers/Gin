/*
Authors: Nick Fryer, Zachary Kuligin, Guilherme Pereira, Logan MacKenzie
Class: Computer Programming II
Date: September 24, 2014
Description: This is the driver for the Player class.
*/



#include "stdafx.h"
#include "player.h"
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

Deck Player::deck;

Player::Player(){
	handSize = 0;

}

void Player::PrintHand(){
	for(int i = 0; i < HAND_SIZE; i++){
		cout << i << '\t' << hand[i].name() << endl;
	}
	return;
}

/*
General Turn Concept:
Print Hand
Choose Card to pick-up
Pick-Up card/Discard -> Function
If Player can knock, then ask: Do you want to knock?
End of Turn
*/
void Player::PlayerTurn(){
	cout << "Here are the cards currently in your hand:" << endl;
	PrintHand();
	char ans;

	do{
		cout << "Would you like to pick up the " << deck.PeekPile().name() << " from the discard pile, or" << endl;
		cout << "pick up from the deck? ('P' for the pile, 'D' for the deck)" << endl;
		cin >> ans;
		ans = toupper(ans);
	}while((ans != 'P')&&(ans != 'D'));

	if(ans == 'P')
		PickUpDiscard();
	else
		SelectCard();

//if(CanKnock())
//	cout << "Do you want to knock? " << endl;
}

void Player::SelectCard(){
	Card card = deck.DealCard();
	cout << "You drew: " << card.name() << endl;
	DiscardCard(card);

/*
	Print Card and Hand
	DiscardCard
	Ask if player wants to Knock
		Knock(){
			FindSets/GotGin
			CountPoints

		}
*/


}

void Player::GetCard(Card card){
	hand[handSize++] = card;
	return;
}

void Player::PickUpDiscard(){
	Card card = deck.BottomCard();
	cout << "You picked up: " << card.name() << endl;
	DiscardCard(card);
}

// By default the player will throw the card he drew
// Unless he chooses to throw a different card.
// If he chooses a number that is not between 0 and 10
// He throws the card he drew.
void Player::DiscardCard(Card& card){
	PrintHand();
	int cardNumber = -1;
	cout << "Enter the number next to the card you want to throw: " << endl;
	cout << "Or enter -1 for the card you just drew: " << endl;
	cin >> cardNumber;
	if(0 <= cardNumber && cardNumber <= 10){
		Swap(hand[cardNumber], card);
	}else{
		//Do nothing.
	}
	return;
}

bool Player::CanKnock(){
/*
vector of matched cards, vector of unmatched cards.
Find Runs: Sort by suit, sort by value. If series (3+) of values then RUN.
Find Sets: sort by number, If set (3 or 4) of numbers then SET.

If a card is in both a set and a run: Ask user which he wants.
*/

	return true;
}


//Figure out how to find sets and put them into the vector "sets"
/*
Find Sets: SortBy Number
If card1 == card2 == card3 
	put in set
else
	put card1 in unmatched

for(int i = 0; i < cards.size(); i++){
	if(cards[i].getValue() == cards[i+1].getValue()){
		if(cards[i].getValue() == cards[i+2].getValue()){
			//Put in Set / Check for fourth card.
		}else
			//Put cards i and i+1 in unmatched
	}else
		put card i in unmatched


}

Deal cards and sort into sets and unmatched


*/
bool Player::FindSets(){
	SortByNumber(0, HAND_SIZE);
	int count = 0;
	int	value = hand[0].getValue();
	for(unsigned int i = 1; i < HAND_SIZE; i++){
		if(hand[i].getValue() == value)
			count++;
		else
			count = 0;
		value = hand[i].getValue();
	}
	if(count >= 3)
		return true;
	return false;
}

void Player::SortByNumber(int start, int end){
	for(int i = start; i < end; i++){
		for(int k = i; k < end; k++){
			if(hand[k].getValue() < hand[i].getValue())
				Swap(hand[k],hand[i]);
		}
	}
	return;
}


void Player::SortBySuit(){
	Suit suit = clubs;
	int k = 0;
	for(int i = 0; i < 4; i++){
		for(int j = (HAND_SIZE-1); j >= k; j--){
//			cout << "Hand[" << j << "] = " << hand[j].name() << endl;
			while(hand[k].getSuit() == Suit(i)){
				k++;
			}
			if(j > k && hand[j].getSuit() == Suit(i))
				Swap(hand[j],hand[k++]);
		}
	}
	return;
}

bool Player::FindRuns(){
	SortBySuit();
	int start, end = 0;
	bool runs = false;
	int value, count = 0;
	for(int k = 0; k < 4; k++){
		for(start = end; hand[end].getSuit() == Suit(k); end++);
		SortByNumber(start, end);
		value = hand[start].getValue();
		for(int i = (start+1); i < end; i++){
			if(hand[i].getValue() == ++value)
				count++;
			else
				count = 0;
		}
	}
	if(count >= 3)
		return true;
	return false;
}


bool Player::GotGin()
{

	return true;
}


void Player::Swap(Card& one, Card& two){
	cout << "Swap: " << one.name() << '\t' << two.name() << endl;
	Card tmp = one;
	one = two;
	two = tmp;
	return;
}


void Player::SortIntoSets(){
	int start = 0, end = 0;
	Suit suit = clubs;
	SortBySuit();
	cout << endl << "After sorting suits: " << endl;
	PrintHand();
	
	while(end++, end < HAND_SIZE){
		if(hand[end].getSuit() != suit){
			SortByNumber(start, end);
			start = end;
			suit = hand[end].getSuit();
		}
	}
	SortByNumber(start, HAND_SIZE);


	//int setNum = 0;
	//vector<Card> cards;
	//for(int i = 0; i < HAND_SIZE; i++){
	//}	
	//return;
}

bool Player::DoesCardFit(Card card){
	int setNum = 0;
	int setCount = 0;
	for(int i = 0; i < HAND_SIZE; i++){
//		if(hand[i].name() == card.name())
//			continue;
		if(hand[i].getValue() == card.getValue()){
			setCount++;
			sets[setNum].push_back(hand[i]);
		}
	}




	return true;
}
/*
Go through hand one card at a time:
Does this card fit into any sets with the other cards
if(yes)
	put in set
else (No)
	put in unmatched




*/
