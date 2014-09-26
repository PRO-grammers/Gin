//Gin Rummy
/*
  Authors: Nick Fryer, Logan MacKenzie, Zachary Kuligin, Guilherme Pereira
  Course: COMP 220, Computer Programming II
  Date: September 25, 2014
  Purpose: This program will initiate all of the other classes
*/

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

//includes the header file for Gin
#include "Gin.h"

using namespace std;

int main()
{
	//calls the Gin class and runs the game
	Gin game;
	game.RunGame();
	return 0;
}
