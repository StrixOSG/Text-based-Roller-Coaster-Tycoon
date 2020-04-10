// ==========================================
// Name: Matthew Allan Hamilton
// Date: Apr.7,2016
// ==========================================

#include <iostream>
#include <fstream>
#include "CyclicRide.h"
using namespace std;

CyclicRide::CyclicRide() :Ride(){

	entranceRowPos = getRowPos();
	entranceColPos = getColPos();
	exitRowPos = getRowPos();
	exitColPos = getColPos();

}

CyclicRide::CyclicRide(const CyclicRide& original) :Ride(original){

	entranceRowPos = original.getRowPos();
	entranceColPos = original.getColPos();
	exitRowPos = original.getRowPos();
	exitColPos = original.getColPos();

}

CyclicRide& CyclicRide::operator= (const CyclicRide& original){

	Ride::operator=(original);
	entranceRowPos = original.getRowPos();
	entranceColPos = original.getColPos();
	exitRowPos = original.getRowPos();
	exitColPos = original.getColPos();

	return *this;

}

int CyclicRide::getEntranceRow() const{

	return entranceRowPos;

}

int CyclicRide::getEntranceCol() const{

	return entranceColPos;

}

int CyclicRide::getExitRow() const{

	return exitRowPos;

}

int CyclicRide::getExitCol() const{

	return exitColPos;

}

void CyclicRide::debugPrint() const{

	cout << "Cyclic Ride: " << endl;
	Ride::debugPrint();

}

void CyclicRide::load(ifstream& game_in){

	Ride::load(game_in);
	game_in >> entranceRowPos;
	game_in >> entranceColPos;
	game_in >> exitRowPos;
	game_in >> exitColPos;

}

void CyclicRide::save(ofstream& game_in)const{

	game_in << "c ";
	Ride::save(game_in);
	game_in << entranceRowPos << " ";
	game_in << entranceColPos << " ";
	game_in << exitRowPos << " ";
	game_in << exitColPos << endl;

}

void CyclicRide::calculateMove(int& row, int& col) const{

	if ((row == getRowPos()) && (col == getColPos())){ //Left Corner

		col++;

	}
	else if ((col == getColPos()) && (row > getRowPos())){ //Left Edge

		row--;

	}
	else if ((row == (getRowPos() + getRowSize() - 1)) && (col > getColPos())){ //Bottom edge

		col--;

	}
	else if ((col == (getColPos() + getColSize() - 1)) && (row < (getRowPos() + getRowSize()))){ //Right Edge

		row++;

	}
	else{

		col++;

	}


}