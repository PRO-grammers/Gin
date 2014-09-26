/*
Authors: Nick Fryer, Zachary Kuligin, Guilherme Pereira, Logan MacKenzie
Class: Comp 220 B, Computer Programming II
Date: September 25, 2014
Description: This file contains the implementation of the Player class.
*/

#include "stdafx.h"
#include "player.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

Deck Player::deck;

// Sets up the player
Player::Player(){
	handSize = 0;
	sets.resize(3);
	runs.resize(3);

}


// Prints the hand with numbers associated to each card
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
Turn over

*/
void Player::PlayerTurn(){
	SortIntoSets();
	cout << "You have these combinations:" << endl;
	PrintSets();
	PrintRuns();
	cout << "You currently have " << Sum() << " points. " << endl;
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

	SortIntoSets();
	MatchCards();
	return;
}

void Player::SelectCard(){
	Card card = deck.DealCard();
	cout << "You drew: " << card.name() << endl;
	DiscardCard(card);
	return;
}

// Inserts cards into the player's hand
void Player::GetCard(){
	hand[handSize++] = deck.DealCard();
	return;
}

// Inserts card from discard pile into player's hand.
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
	if(0 <= cardNumber && cardNumber < 10)
		Swap(hand[cardNumber], card);
	deck.DiscardCard(card);
	return;
}



void Player::MatchCards(){
	FindSets();
	FindRuns();
	FindUnmatched();
	SortIntoSets();

	CheckConflicts();
	return;
}

/*
FindUnmatched finds all all the cards not in "sets" or "runs" and puts those
cards into "unmatched".
*/
void Player::FindUnmatched(){
	unmatched.clear();
	for(int card = 0; card < HAND_SIZE; card++){
		if(!CardInRun(hand[card]) && !CardInSet(hand[card])){
			unmatched.push_back(hand[card]);
		}
	}
	return;
}


// Seems to work
void Player::FindSets(){
	SortByNumber(0, HAND_SIZE);
	for(int i = 0; i < sets.size(); i++){
		sets[i].clear();
	}
	vector<Card> cards;
	Card tmp;
	int k = 0;
	int setNum = 0;
	for(int i = 0; i < HAND_SIZE;){
		cards.push_back(hand[i]);
		while(hand[++i].getSuit() != cards[k].getSuit() && hand[i].getValue() == cards[k].getValue()){
			cards.push_back(hand[i]);
			k++;
		}
		if(k >= 2){
			sets[setNum++] = cards;
		}
		k = 0;
		cards.clear();
	}
	return;
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
			while(hand[k].getSuit() == Suit(i)){
				k++;
			}
			if(j > k && hand[j].getSuit() == Suit(i))
				Swap(hand[j],hand[k++]);
		}
	}
	return;
}

//Works!!
void Player::FindRuns(){
	SortIntoSets();
	for(int i = 0; i < runs.size(); i++){
		runs[i].clear();
	}
	vector<Card> cards;
	int k = 0;
	int runNum = 0;
	for(int i = 0; i < HAND_SIZE;){
		cards.push_back(hand[i]);
		while(hand[++i].getSuit() == cards[k].getSuit() && hand[i].getValue() == cards[k].getValue()+1){
			cards.push_back(hand[i]);
			k++;
		}
		if(k >= 2){
			runs[runNum++] = cards;
		}
		k = 0;
		cards.clear();
	}
	return;
}

/*
CheckConflicts checks to make sure that a card in a set is not also in a run.
If it is then it calls FixConflicts to take care of it.
Note: in the if-statement, the assignment operator is used intentionally.
	CardInRun returns 0 if the card is not in a run and 1+ the "runNumber" otherwise.
	The assignment operator will return the value returned by the CardInRun
	Thus: if the card is not in a run, this condition will be false
		  if the card is in a run, the condition will be true and runNum will have 1+which run the card is in.
 */
void Player::CheckConflicts(){
	PrintSets();
	PrintRuns();
	int runNum = 0;
	for(unsigned int setNum = 0; setNum < sets.size(); setNum++){
		for(int cardNum = 0; cardNum < sets[setNum].size(); cardNum++){
			if(runNum = CardInRun(sets[setNum][cardNum])){		// Using the assignment operator here is intentional
				FixConflicts(setNum, --runNum);
			}

		}
	}
	return;
}

int Player::CardInRun(Card card){
	for(int runNum = 0; runNum < runs.size(); runNum++){
		for(int cardNum = 0; cardNum < runs[runNum].size(); cardNum++){
			if(card.name() == runs[runNum][cardNum].name())
				return runNum + 1;
		}
	}
	return 0;
}

int Player::CardInSet(Card card){
	for(int setNum = 0; setNum < sets.size(); setNum++){
		for(int cardNum = 0; cardNum < sets[setNum].size(); cardNum++){
			if(card.name() == sets[setNum][cardNum].name())
				return setNum + 1;
		}
	}
	return 0;
}


void Player::FixConflicts(int setNum, int runNum){
	cout << "Set " << setNum << " and Run " << runNum << " conflict!" << endl;
	char ans;
	do{
		cout << "Which do you wish to keep (enter S for Set or R for Run): ";
		cin >> ans;
		cin.sync();
		ans = toupper(ans);
	}while((ans != 'S') && (ans != 'R'));
	cout << "Out of loop: ans = " << ans << endl; 

	if(ans == 'S'){
		// Keep Set / Throw out run
		runs[runNum].clear();
	}else{
		// Keep Run / Throw out set
		sets[setNum].clear();
	}
	return;
}

// Prints player's runs
void Player::PrintRuns(){
	for(int run = 0; run < runs.size(); run++){
		if(runs[run].empty())
			continue;
		cout << "Run " << run << ": ";
		for(int card = 0; card < runs[run].size(); card++){
			cout << runs[run][card].name() << '\t';
		}
		cout << endl;
	}
	return;
}

// Prints player's sets
void Player::PrintSets(){
	for(int set = 0; set < sets.size(); set++){
		if(sets[set].empty())
			continue;
		cout << "Set " << set << ": ";
		for(int card = 0; card < sets[set].size(); card++){
			cout << sets[set][card].name() << '\t';
		}
		cout << endl;
	}
	return;
}

// Swaps card one and two.
void Player::Swap(Card& one, Card& two){
	Card tmp = one;
	one = two;
	two = tmp;
	return;
}


// Works!!
void Player::SortIntoSets(){
	int start = 0, end = 0;
	Suit suit;
	SortBySuit();
	suit = hand[end].getSuit();
	
	while(end++, end < HAND_SIZE){
		if(hand[end].getSuit() != suit){
			SortByNumber(start, end);
			start = end;
			suit = hand[end].getSuit();
		}
	}
	SortByNumber(start, HAND_SIZE);
	return;
}



bool Player::WannaKnock(){
	if(Sum() <= 10){
		char ans = 'a';
		cout << "Do you wish to knock?" << endl;
		cin >> ans;
		cin.sync();
		if(toupper(ans) == 'Y'){
			return true;
		}
	}	
	cout << endl << endl << endl << endl;
	return false;
}


/*
Sum sums up the points in a player's hand.
The +1 for each card is due to the fact that each card has in int value
of 1 less than its actual value.
*/
int Player::Sum(){
	int sum = 0;
	for(unsigned int i = 0; i < unmatched.size(); i++){
		sum += int(unmatched[i].getValue()) + 1;
	}
	return sum;
}
