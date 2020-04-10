// ==========================================
// Name: Matthew Hamilton
// Date: Apr.7,2016
// ==========================================

#include <iostream>
#include "PositionList.h"
using namespace std;

#ifndef RIDE_H
#define RIDE_H

class Ride{

private:
	string name;
	int rowPos;
	int colPos;
	int rowSize;
	int colSize;
	int capacity;
	int timeReq;

protected:
	//
	// init
	//
	// Purpose: Sets the Ride's member variables to the values provided
	// Parameter(s):
	// const string& name1: rides name used for debug currently
	// int row_pos1: rides row position on the canvas
	// int col_pos1: rides column position on the canvas
	// int row_size1: rides row height on the canvas
	// int col_size1: rides column width on the canvas
	// int capacity1: max number of guests that can be on the ride in a step
	// int time_required1: length of time the guest stays on the ride for
	//
	// Precondition(s): The values passed in must agree with the invariant function
	// Return: N/A
	// Side Effect: The ride's member variables are initialized to the passed in valid values
	//
	void init(const string& name1, int row_pos1, int col_pos1, int row_size1, int col_size1, int capacity1);

public:
	//
	// Ride
	//
	// Purpose: Initialize default values to member variables
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: The ride's member variables are initialized to valid values
	//
	Ride();

	//
	// getName
	//
	// Purpose: Provides the Ride's name
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: the member variable string name
	// Side Effect: N/A
	//
    string getName() const;

	//
	// getRowPos
	//
	// Purpose: Provides the Ride's row postion
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: the member variable int rowPos
	// Side Effect: N/A
	//
	int getRowPos() const;

	//
	// getColPos
	//
	// Purpose: Provides the Ride's column postion
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: the member variable int colPos
	// Side Effect: N/A
	//
	int getColPos() const;

	//
	// getRowSize
	//
	// Purpose: Provides the Ride's row size
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: the member variable int rowSize
	// Side Effect: N/A
	//
	int getRowSize() const;

	//
	// getColSize
	//
	// Purpose: Provides the Ride's column size
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: the member variable int colSize
	// Side Effect: N/A
	//
	int getColSize() const;

	//
	// getCapacity
	//
	// Purpose: Provides the Ride's capacity
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: the member variable int capacity
	// Side Effect: N/A
	//
	int getCapacity() const;

	//
	// load
	//
	// Purpose: Loads in values from a file into Ride member variables
	// Parameter(s):
	// ifstream& game_in1: file name to load from and open
	//
	// Precondition(s): game_in1 must be a valid file name, game_in1 must read in correctly, and have values that agree with the invariant function
	// Return: N/A
	// Side Effect: The ride's member variables are initialized to the read in file values
	//
	virtual void load(ifstream& game_in1);

	//
	// debugPrint
	//
	// Purpose: Prints the Ride's member variable values to the screen
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: N/A
	//
	virtual void debugPrint()const;

	//
	// invariant
	//
	// Purpose: Checks if the Ride has legal values for the Canvas
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: True if the ride has valid position and size values for the canvas otherwise False
	// Side Effect: N/A
	//
	bool invariant()const;

	//
	// save
	//
	// Purpose: Saves values from Ride member variables to a file
	// Parameter(s):
	// ifstream& game_out: file name to save to and open
	//
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: N/A
	//
	virtual void save(ofstream& game_out) const;

	//
	// ~Ride
	//
	// Purpose: Deletes any dynamically allocated variables
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: Dynamically allocated variables are deleted
	//
	virtual ~Ride(){};

	//
	// Ride
	//
	// Purpose: Copy one ride's values to another
	// Parameter(s):
	// const Ride& original: ride to copy from
	//
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: The ride being created has its values changed to the original ride passed in
	//
	Ride(const Ride& original);

	//
	// operator=
	//
	// Purpose: Set one ride's values equal to another
	// Parameter(s):
	// const Ride& original: ride to set equal to
	//
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: The ride calling the function has its values changed to the original ride passed in
	//
	Ride& operator= (const Ride& original);
	
	//
	// getEntranceRow
	//
	// Purpose: Entrance row position of the appropriate type of ride is returned
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: Entrance row position as an int
	// Side Effect: N/A
	//
	virtual int getEntranceRow() const = 0;

	//
	// getEntranceCol
	//
	// Purpose: Entrance column position of the appropriate type of ride is returned
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: Entrance column position as an int
	// Side Effect: N/A
	//
	virtual int getEntranceCol() const = 0;

	//
	// getExitRow
	//
	// Purpose: Exit row position of the appropriate type of ride is returned
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: Exit row position as an int
	// Side Effect: N/A
	//
	virtual int getExitRow() const = 0;

	//
	// getExitColumn
	//
	// Purpose: Exit column position of the appropriate type of ride is returned
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: Exit column position as an int
	// Side Effect: N/A
	//
	virtual int getExitCol() const = 0;

	//
	// isEntrance
	//
	// Purpose: Determines if the row and col positions given is an entrace of a ride
	// Parameter(s):
	// int row: row position to be checked
	// int col: column position to be checked
	//
	// Precondition(s): N/A
	// Return: True if the row and col are equal to a Entrance position otherwise False
	// Side Effect: N/A
	//
    bool isEntrance(int row, int col) const;

	//
	// isExit
	//
	// Purpose: Determines if the row and col positions given is an exit of a ride
	// Parameter(s):
	// int row: row position to be checked
	// int col: column position to be checked
	//
	// Precondition(s): N/A
	// Return: True if the row and col are equal to a Exit position otherwise False
	// Side Effect: N/A
	//
	bool isExit(int row, int col) const;

	//
	// calculateMove
	//
	// Purpose: Determines which direction to move by increasing or decreasing the row and col position while in the appropriate ride
	// Parameter(s):
	// int row: row position to be modified 
	// int col: column position to be modified 
	//
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: row and col are either added or subtracted to by one
	//
	virtual void calculateMove(int& row, int& col) const = 0;

	//
	// getRideTrack
	//
	// Purpose: rideTrack PositionList is returned
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: PositionList rideTrack
	// Side Effect: N/A
	//
	virtual PositionList getRideTrack() const;

};

#endif