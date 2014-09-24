/*
Authors: Nick Fryer, Zachary Kuligin, Guilherme Pereira, Logan MacKenzie
Class: Computer Programming II
Date: September 24, 2014
Description: This is the driver for the Player class.
*/

#include "player.h"
#include "Deck.h"

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

ostream &operator<<(ostream& cout, player &p){
	cout << Card::name;
	return cout;
}

void player::PrintHand(player p){
	for(int i = 0; i < HAND_SIZE; i++){
		cout << p.hand.at(i) << " ";	//Need to fix this, make it a cout << card
	}

}
//this function deals with each on of the player's turns
void player::PlayerTurn(hand h)
{
	//as long as they do not have Gin, it will commence with player's turn
	if(GotGin() != true)
	{
		cout << "Here are the cards currently in your hand:" << endl;
		cout << PrintHand() << endl;
		char ans;
		cout << "Would you like to pick up the " <<  << " from the discard pile, or" << endl;
		cout << " pick up from the deck? ('P' for the pile, 'D' for the deck)" << endl;
		cin >> ans;
		ans = toupper(ans);
		while((ans != 'P')&&(ans != 'D'))
		{
			cout << "Please enter a 'P' for the discard pile or a 'D' for the deck" << endl;
			cin >> ans;
			ans = toupper(ans);
		}
		SelectCard(ans);
	}
}

//this function will select a card from the player's hand depending on their input
void player::SelectCard(char ans)
{
	if(ans =='P')
	{
		
	}
	if(ans == 'D')
	{

	}
}

//this function will deicard the player's chosen card
void player::DiscardCard(){
	Value the_value;
	Suit the_suit;
	cout << "What is the value of the card you would like to discard?" << endl;
	cin.get(the_value);
	cout << "What is the suit of the card you would like to discard?" << endl;
	cin >> the_suit;
}

//this function will find any sets that the player has in their hand
void player::FindSets(Value a[], Value b[], Value c[])
{
	
}

//this function will return true if the player has Gin
bool player::GotGin()
{
	if((a[1]==a[2])&&(a[2]==a[3])&&(a[3]==a[4]))
	{
		if((b[1]==b[2])&&(b[2]==b[3])&&(b[3]==b[4]))
		{
			if((c[1]==c[2])&&(c[2]==c[3]))
			{
				cout << "Congradulations! You have Gin!" << endl;
				cout << "GAME OVER" << endl;
				exit(1);
			}
		}
	}
}
