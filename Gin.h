/*
Authors: Nick Fryer, Zachary Kuligin, Guilherme Pereira, Logan MacKenzie
Class: Comp 220 B, Computer Programming II
Date: September 25, 2014
Description: This is the header file for the class Gin which is the
	class that contains everything needed to play Gin.

*/

#pragma once

#include "stdafx.h"
#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <cstdlib>


class Gin{
public:
	Gin();
	void RunGame();


private:
	void SumPoints();

	Player player[2];
};
