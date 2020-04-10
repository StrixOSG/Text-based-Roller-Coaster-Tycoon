// ==========================================
// Name: Matthew Hamilton
// Date: Apr.7,2016
// ==========================================

#include <cctype>
#include <cassert>
#include <fstream>
#include <iostream>
#include "Guest.h"
#include "Canvas.h"
#include "Ride.h"

using namespace std;

Guest::Guest(){

	name = 'a';
	happiness = 0;
	rowPos = 0;
	colPos = 0;
	rideNum = 0;

}

void Guest::init(char name1, int happiness1, int row_pos1, int col_pos1, int ride_num1, bool onRide1){

	name = name1;
	happiness = happiness1;
	rowPos = row_pos1;
	colPos = col_pos1;
	rideNum = ride_num1;

	assert(invariant());

}

void Guest::load(ifstream& game_in){

	game_in >> name;
	game_in >> happiness;
	game_in >> rowPos;
	game_in >> colPos;
	game_in >> rideNum;
	rideTrack.load(game_in);

	assert(invariant());

}

void Guest::debugPrint()const{

	cout << "Guest name: " << name << endl;
	cout << "Guest happiness: " << happiness << endl;
	cout << "Guest row pos: " << rowPos << endl;
	cout << "Guest col pos: " << colPos << endl;
	cout << "Guest ride number: " << rideNum << endl;
	rideTrack.debugPrint();

}

void Guest::reset(int ride_num1){

	rideNum = ride_num1;

	assert(invariant());

}

bool Guest::invariant()const{

	//'isalpha' checks if the name of the guest is a letter
	if (isalpha(name) && Canvas::isValidPositionForCanvas(rowPos, colPos)){
		
		return true;

	}
	else {
		
		return false;

	}

}

char Guest::getName() const{
	
	return name;

}

int Guest::getHappiness() const{
	
	return happiness;

}

int Guest::getRowPos() const{
	
	return rowPos;

}

int Guest::getColPos() const{
	
	return colPos;

}

int Guest::getRideNum() const{
	
	return rideNum;

}

void Guest::changeHappiness(int change){

	happiness += change;
	assert(invariant());

}

void Guest::changeRowPos(int change){

	rowPos += change;
	assert(invariant());

}

void Guest::changeColPos(int change){

	colPos += change;
	assert(invariant());
}

void Guest::save(ofstream& game_out) const{

	game_out << name << " ";
	game_out << happiness << " ";
	game_out << rowPos << " ";
	game_out << colPos << " ";
	game_out << rideNum << " ";
	rideTrack.save(game_out);

}

void Guest::setPosition(const int rowPos1, const int colPos1){

	rowPos = rowPos1;
	colPos = colPos1;


}

bool Guest::isOnRide()const{

	if (!rideTrack.isEmpty()){
		return true;
	}
	else{
		return false;
	}

}

void Guest::setCurrentRideTrack(const PositionList& positionList){

	rideTrack = positionList;

}

void Guest::moveAlongRideTrack(){

	assert(!rideTrack.isEmpty());

	setPosition(rideTrack.getFrontRow(), rideTrack.getFrontCol());
	rideTrack.removeFront();

}

