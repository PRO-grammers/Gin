#include "player.h"
#include <string>

using namespace std;

void player::PrintHand()
{
  
}

void player::PlayerTurn()
{
  if(GotGin() != true)
  {
    cout << "Here are the cards currently in your hand:" << endl;
    cout << player.PrintHand() << endl;
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
    player.SelectCard(ans);
  }
}

void player::SelectCard(char ans)
{
  if(ans =='P')
  {
    
  }
  if(ans == 'D')
  {
    
  }
}

void player::DiscardCard()
{
  char the_value;
  string the_suit;
  cout << "What is the value of the card you would like to discard?" << endl;
  cin.get(the_value);
  cout << "What is the suit of the card you would like to discard?" << endl;
  cin >> the_suit;
}

void player::FindSets()
{
  
}

bool player::GotGin()
{
  
}
