// ==========================================
// Name: Matthew Hamilton
// Date: Apr.7,2016
// ==========================================

#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include "Guest.h"
#include "Canvas.h"
#include "Ride.h"

using namespace std;

Ride::Ride(){

	name = "";
	rowPos = 0;
	colPos = 0;
	rowSize = 1;
	colSize = 1;
	capacity = 0;
	timeReq = 10;

}

void Ride::init(const string& name1, int row_pos1, int col_pos1, int row_size1, int col_size1, int capacity1){

	name = name1;
	rowPos = row_pos1;
	colPos = col_pos1;
	rowSize = row_size1;
	colSize = col_size1;
	capacity = capacity1;

	assert(invariant());

}

void Ride::load(ifstream& game_in1){

	game_in1 >> name;
	game_in1 >> rowPos;
	game_in1 >> colPos;
	game_in1 >> rowSize;
	game_in1 >> colSize;
	game_in1 >> capacity;

	if (!Canvas::isValidRideForCanvas(rowPos, colPos, rowSize, colSize)){
		
		cout << "Error: The ride is not valid." << endl;
		exit(1);

	}

	assert(invariant());

}

void Ride::debugPrint()const{

	cout << "Ride name: " << name << endl;
	cout << "Ride row pos: " << rowPos << endl;
	cout << "Ride col pos: " << colPos << endl;
	cout << "Ride row size: " << rowSize << endl;
	cout << "Ride col size: " << colSize << endl;
	cout << "Ride capacity: " << capacity << endl;
	cout << "Row Entrance: " << getEntranceRow() << endl;
	cout << "Row Exit: " << getExitRow() << endl;
	cout << "Column Entrance: " << getEntranceCol() << endl;
	cout << "Column Exit: " << getExitCol() << endl;

}

bool Ride::invariant()const{

	if ((rowPos >= 0 && rowPos < Canvas::CANVAS_ROWS) && (colPos >= 0 && colPos < Canvas::CANVAS_COLUMNS)){

		if ((rowSize > 0 && rowSize <= Canvas::CANVAS_ROWS) && (colSize > 0 && colSize <= Canvas::CANVAS_COLUMNS)){
			
			return true;

		}
		else{
			
			return false;

		}

	}
	else{
		
		return false;

	}

}

string Ride::getName() const{
	
	return name;

}

int Ride::getRowPos() const{
	
	return rowPos;

}

int Ride::getColPos() const{
	
	return colPos;

}

int Ride::getRowSize() const{
	
	return rowSize;

}

int Ride::getColSize() const{
	
	return colSize;

}

int Ride::getCapacity() const{
	
	return capacity;

}

void Ride::save(ofstream& game_out) const{

	game_out << name << " ";
	game_out << rowPos << " ";
	game_out << colPos << " ";
	game_out << rowSize << " ";
	game_out << colSize << " ";
	game_out << capacity << " ";

}

Ride::Ride(const Ride& original){

	name = original.name;
	rowPos = original.rowPos;
	colPos = original.colPos;
	rowSize = original.rowSize;
	colSize = original.colSize;
	capacity = original.capacity;

}

Ride& Ride::operator= (const Ride& original){

	name = original.name;
	rowPos = original.rowPos;
	colPos = original.colPos;
	rowSize = original.rowSize;
	colSize = original.colSize;
	capacity = original.capacity;

	return *this;

}

bool Ride::isEntrance(int row, int col) const{

	if ((row == getEntranceRow()) && (col == getEntranceCol())){
		
		return true;

	}
	else{
		
		return false;

	}

}

bool Ride::isExit(int row, int col) const{

	if ((row == getExitRow()) && (col == getExitCol())){

		return true;

	}
	else{

		return false;

	}

}

PositionList Ride::getRideTrack() const{

	PositionList rideTrack;
	int tRow = getEntranceRow();
	int tCol = getEntranceCol();

	while (tRow != getExitRow() || tCol != getExitCol()){

		calculateMove(tRow, tCol);
		rideTrack.addToBack(tRow, tCol);

	}

	return rideTrack;

}