// ==========================================
// Name: Matthew Hamilton
// Date: Apr.7,2016
// ==========================================

#include "RollerCoaster.h"
#include <iostream>
#include <fstream>
using namespace std;

RollerCoaster::RollerCoaster():Ride(){



}

RollerCoaster::RollerCoaster(const RollerCoaster& original):Ride(original){

	rideTrack = original.rideTrack;

}

RollerCoaster& RollerCoaster::operator=(const RollerCoaster& original){

	Ride::operator=(original);
	rideTrack = original.rideTrack;

	return *this;

}

int RollerCoaster::getEntranceRow() const{

	return getRowPos();

}

int RollerCoaster::getEntranceCol() const{

	return getColPos();

}

int RollerCoaster::getExitRow() const{

	return getRowPos();

}

int RollerCoaster::getExitCol() const{

	return getColPos();

}

void RollerCoaster::debugPrint() const{

	Ride::debugPrint();
	cout << "RollerCoaster Ride: " << endl;
	rideTrack.debugPrint();

}

void RollerCoaster::load(ifstream& game_in){

	Ride::load(game_in);
	rideTrack.load(game_in);

}

void RollerCoaster::save(ofstream& game_out)const{

	game_out << "r ";
	Ride::save(game_out);
	rideTrack.save(game_out);

}

void RollerCoaster::calculateMove(int& row, int& col) const{

	cerr << "Error: RollerCoaster::calculateMove is not supported" << endl;

}

PositionList RollerCoaster::getRideTrack() const{

	return rideTrack;

}