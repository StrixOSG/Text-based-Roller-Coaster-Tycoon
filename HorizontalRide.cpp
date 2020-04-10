// ==========================================
// Name: Matthew Hamilton
// Date: Mar.26,2016
// ==========================================

#include "HorizontalRide.h"
#include <iostream>
#include <fstream>
using namespace std;

HorizontalRide::HorizontalRide():Ride(){

	moveDirection = 0;

}

HorizontalRide::HorizontalRide(const HorizontalRide& original):Ride(original){

	moveDirection = original.moveDirection;

}

HorizontalRide& HorizontalRide::operator= (const HorizontalRide& original){

	Ride::operator=(original);
	moveDirection = original.moveDirection;

	return *this;

}

int HorizontalRide::getEntranceRow() const{

		return getRowPos();

}

int HorizontalRide::getEntranceCol() const{

	if (moveDirection == 0){

		return getColPos();

	}
	else{

		return (getColPos() + (getColSize() - 1));

	}

}

int HorizontalRide::getExitRow() const{

	return getRowPos();

}

int HorizontalRide::getExitCol() const{

	if (moveDirection == 0){

		return (getColPos() + (getColSize() - 1));

	}
	else{

		return getColPos();
	}


}

void HorizontalRide::debugPrint() const{

	cout << "Horizontal Ride: " << endl;
	Ride::debugPrint();
	if (moveDirection == 0){

		cout << "Ride guest direction: left to right" << endl;

	}
	else{

		cout << "Ride guest direction: right to left" << endl;

	}

}

void HorizontalRide::load(ifstream& game_in){

	Ride::load(game_in);
	game_in >> moveDirection;

}

void HorizontalRide::save(ofstream& game_in)const{

	game_in << "h ";
	Ride::save(game_in);
	game_in << moveDirection << endl;

}

void HorizontalRide::calculateMove(int& row, int& col) const{

	if (moveDirection == 0){

		col++;

	}
	else if (moveDirection == 1){

		col--;

	}

}