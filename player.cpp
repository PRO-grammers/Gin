#include "player.h"
#include "stdafx.h"

ostream &operator<<(ostream& cout, player &p){
	cout << Card::name;
	return cout;
}

void PrintHand(player p){
	for(int i = 0; i < HAND_SIZE; i++){
		cout << p.hand.at(i) << " ";	//Need to fix this, make it a cout << card
	}

}

void PlayerTurn(hand h)
{
	if(GotGin() != true)
	{
		cout << "Here are the cards currently in your hand:" << endl;
		cout << PrintHand() << endl;
		char ans;
		cout << "Would you like to pick up the " <<  << " from the discard pile, or" << endl;
		cout << "pick up from the deck? ('P' for the pile, 'D' for the deck)" << endl;
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

void SelectCard(char ans)
{
	if(ans =='P')
	{

	}
	if(ans == 'D')
	{

	}
}

void DiscardCard(){
	char the_value;
	string the_suit;
	cout << "What is the value of the card you would like to discard?" << endl;
	cin.get(the_value);
	cout << "What is the suit of the card you would like to discard?" << endl;
	cin >> the_suit;
}

void FindSets()
{

}

bool GotGin()
{

}
