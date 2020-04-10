// ==========================================
// Name: Matthew Hamilton
// Date: Apr.7,2016
// ==========================================
#include <iostream>
#include "PositionList.h"
using namespace std;

#ifndef GUEST_H
#define GUEST_H

class Guest{

private:
	char name;
	int happiness;
	int rowPos;
	int colPos;
	int rideNum;
	PositionList rideTrack;

public:
	//
	// Guest
	//
	// Purpose: Initialize default values to member variables
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: The guest's member variables are initialized to valid values
	//
	Guest();

	//
	// init
	//
	// Purpose: Sets the Guest's member variables to the values provided
	// Parameter(s):
	// char name1: guest's letter that is displayed
	// int happiness1: guests starting happiness value
	// int row_pos1: guests row position on the canvas
	// int col_pos1: guests column position on the canvas
	// int ride_num1: ride for the guest to move towards
	// int time1: length of time the guest stays on the ride for
	//
	// Precondition(s): The values passed in must agree with the invariant function
	// Return: N/A
	// Side Effect: The guest's member variables are initialized to the passed in valid values
	//
	void init(char name1, int happiness1, int row_pos1, int col_pos1, int ride_num1, bool onRide1);

	//
	// load
	//
	// Purpose: Loads in values from a file into Guest member variables
	// Parameter(s):
    // ifstream& game_in: file name to load from and open
	//
	// Precondition(s): game_in must be a valid file name, and have values that agree with the invariant function
	// Return: N/A
	// Side Effect: The guest's member variables are initialized to the read in file values
	//
	void load(ifstream& game_in);

	//
	// debugPrint
	//
	// Purpose: Prints the Guest's member variable values to the screen
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: N/A
	//
	void debugPrint()const;

	//
	// reset
	//
	// Purpose: The Guest's rideNum, and remTime is set to the values provided
	// Parameter(s):
	// int ride_num1: new ride for the guest to move towards
	// int time1: length of time required to stay on the next ride for
	//
	// Precondition(s): The values passed in must agree with the invariant function
	// Return: N/A
	// Side Effect: The guest's rideNum and remTime are set to the values passed in
	//
	void reset(int ride_num1);

	//
	// invariant
	//
	// Purpose: Checks if the Guest's name is a letter and if the position of the Guest is valid for the Canvas
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: True if the guest name is a letter and position is valid for the canvas otherwise False
	// Side Effect: N/A
	//
	bool invariant()const;

	//
	// getName
	//
	// Purpose: Provides the Guest's name
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: the member variable char name
	// Side Effect: N/A
	//
	char getName() const;

	//
	// getName
	//
	// Purpose: Provides the Guest's happiness
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: the member variable int happiness
	// Side Effect: N/A
	//
	int getHappiness() const;

	//
	// getRowPos
	//
	// Purpose: Provides the Guest's row position
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: the member variable int rowPos
	// Side Effect: N/A
	//
	int getRowPos() const;

	//
	// getColPos
	//
	// Purpose: Provides the Guest's column position
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: the member variable int colPos
	// Side Effect: N/A
	//
	int getColPos() const;

	//
	// getRideNum
	//
	// Purpose: Provides the Guest's ride number
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: the member variable int rideNum
	// Side Effect: N/A
	//
	int getRideNum() const;

	//
	// changeHappiness
	//
	// Purpose: Adds or subtracts to the Guest's happiness from the value provided
	// Parameter(s):
	// int change: The amount to add or subtract from the guests happiness
	//
	// Precondition(s): The values passed in must agree with the invariant function
	// Return: N/A
	// Side Effect: happiness has a greater or less value than previous 
	//
	void changeHappiness(int change);

	//
	// changeRowPos
	//
	// Purpose: Adds or subtracts to the Guest's row position from the value provided
	// Parameter(s):
	// int change: The amount to add or subtract from the guests row position
	//
	// Precondition(s): The values passed in must agree with the invariant function
	// Return: N/A
	// Side Effect: row position has a greater or less value than previous
	//
	void changeRowPos(int change);

	//
	// changeColPos
	//
	// Purpose: Adds or subtracts to the Guest's column position from the value provided
	// Parameter(s):
	// int change: The amount to add or subtract from the guests row position
	//
	// Precondition(s): The values passed in must agree with the invariant function
	// Return: N/A
	// Side Effect: column position has a greater or less value than previous
	//
	void changeColPos(int change);

	//
	// save
	//
	// Purpose: Saves values from Guest member variables to a file
	// Parameter(s):
	// ifstream& game_out: file name to save to and open
	//
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: N/A
	//
	void save(ofstream& game_out) const;

	//
	// setPosition
	//
	// Purpose: rowPos and colPos are set equal to the values passed in
	// Parameter(s):
	// int rowPos1: value of a row position to be copied from
	// int col: column value of a column position to be copied from
	//
	// Precondition(s): rowPos1 and colPos1 must be within the canvas boundaries
	// Return: True if the row and col are equal to a Exit position otherwise False
	// Side Effect: N/A
	//
	void setPosition(const int rowPos1, const int colPos1);

	//
	// isonRide
	//
	// Purpose: Returns if the guest is on the ride or not
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: True if the member variable bool onRide is true otherwise false
	// Side Effect: N/A
	//
	bool Guest::isOnRide()const;

	//
	// setCurrentRideTrack
	//
	// Purpose: Sets the PositionList object provided to the guest's PositionList named rideTrack
	// Parameter(s):
	// PositionList& positionList: positionList to set equal to
	//
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: rideTrack is assigned the positionList value provided
	//
	void setCurrentRideTrack(const PositionList& positionList);

	//
	// moveAlongRideTrack
	//
	// Purpose: Guest's position is set to the next row and pos values of rideTrack which moves the guest along the track once every call to moveAlongRideTrack
	// Parameter(s): N/A
	// Precondition(s): guest's rideTrack (PositionList) is not empty
	// Return: N/A
	// Side Effect: row and pos values updated to rideTrack's current row and pos values, and the front of the rideTrack's list is removed
	//
	void moveAlongRideTrack();

};

#endif
