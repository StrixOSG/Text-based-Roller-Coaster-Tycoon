// ==========================================
// Name: Matthew Hamilton
// Date: Apr.7,2016
// ==========================================

#include "PositionList.h"

#ifndef CANVAS_H
#define CANVAS_H

class Canvas{

public:
	static const int CANVAS_ROWS = 20;
	static const int CANVAS_COLUMNS = 60;

private:
	char canvas1[CANVAS_ROWS][CANVAS_COLUMNS];

public:
	//
	// Canvas
	//
	// Purpose: Initialize default values to member variables
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: Canvas array set to default value '.'
	//
	Canvas();

	//
	// clear
	//
	// Purpose: Sets all the Canvas arrays values to a default '.'
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: The canvas' values are all set to '.'
	//
	void clear();

	//
	// display
	//
	// Purpose: Prints out the Canvas to the screen in a grid shape
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: N/A
	//
	void display()const;

	//
	// addGuest
	//
	// Purpose: Takes the position and letter of the guest and adds it to the Canvas' array
	// Parameter(s):
	// int row_pos1: guest row position
	// int col_pos1: guests column positon
	// char guest_letter1: guests letter to display
	//
	// Precondition(s): row_pos1, col_pos1, and guest_letter1 must be legal values 0-19,0-59,a-A respectively
	// Return: N/A
	// Side Effect: Assigns the guests letter to the canvas array in the appropriate position to represent a guest
	//
	void addGuest(int row_pos1, int col_pos1, char guest_letter1);

	//
	// addRide
	//
	// Purpose: Takes the position and size of the ride and adds it to the Canvas' array
	// Parameter(s):
	// int row_pos1: ride row position
	// int col_pos1: ride column positon
	// int row_size1 ride row size
	// int col_size1 ride column size
	//
	// Precondition(s): must be a valid ride position for the canvas
	// Return: N/A
	// Side Effect: Assigns an '*' in the appropriate positions to the canvas array representing a ride
	//
	void addRide(int row_pos1, int col_pos1, int row_size1, int col_size1);

	//
	// isValidPositionForCanvas
	//
	// Purpose: Checks if a position is within the boundaries of the Canvas
	// Parameter(s):
	// int row_pos1: row position to be checked
	// int col_pos1: column positon to be checked
	//
	// Precondition(s): N/A
	// Return: True if position is within canvas boundaries(0-19) otherwise False
	// Side Effect: N/A
	//
	static bool isValidPositionForCanvas(int row_pos1, int col_pos1);

	//
	// isValidRideForCanvas
	//
	// Purpose: Checks if a ride's position is within the boundaries of the Canvas
	// Parameter(s):
	// int row_pos1: Ride row position to be checked
	// int col_pos1: Ride column positon to be checked
	// int row_size1: Ride row size to be checked
	// int col_size1: Ride column size to be checked
	//
	// Precondition(s): N/A
	// Return: True if position is within the rides boundaries otherwise False
	// Side Effect: N/A
	//
	static bool isValidRideForCanvas(int row_pos1, int col_pos1, int row_size1, int col_size1);

	//
	// addTrack
	//
	// Purpose: To add a '+' in appropriate row and column positions based on positionList provided to form a RollerCoaster Ride Track
	// Parameter(s):
	// PositionList positionList: list that contains row and column positions
	//
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: N/A
	//
	void addTrack(PositionList positionList);

};

#endif