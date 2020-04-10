// ==========================================
// Name: Matthew Hamilton
// Date: Apr.7,2016
// ==========================================

#include <iostream>
#include <cassert>
#include "Canvas.h"
#include "Guest.h"
#include "Ride.h"

using namespace std;

Canvas::Canvas(){
	clear();

}

void Canvas::clear(){

	for (int i = 0; i < CANVAS_ROWS; i++){
		
		for (int j = 0; j < CANVAS_COLUMNS; j++){
			
			canvas1[i][j] = '.';

		}

	}

}

void Canvas::display()const{

	for (int i = -1; i <= CANVAS_ROWS; i++){
		
		for (int j = 0; j < CANVAS_COLUMNS; j++){

			if (i == -1 || i == CANVAS_ROWS){
				
				cout << '-';

			}
			else{
				
				cout << canvas1[i][j];

			}

		}
		
		cout << endl;

	}

}

void Canvas::addGuest(int row_pos1, int col_pos1, char guest_letter1){

	assert((row_pos1 >= 0) && (row_pos1 < CANVAS_ROWS));
	assert((col_pos1 >= 0) && (col_pos1 < CANVAS_COLUMNS));

	canvas1[row_pos1][col_pos1] = guest_letter1;

}

void Canvas::addRide(int row_pos1, int col_pos1, int row_size1, int col_size1){

	assert(isValidRideForCanvas(row_pos1, col_pos1, row_size1, col_size1));

	for (int i = 0; i < row_size1; i++){
		
		for (int j = 0; j < col_size1; j++){
			
			if (i == 0 && j == 0){
				
				canvas1[row_pos1][col_pos1] =  '*';
				
			}
			else{
				
				canvas1[row_pos1 + i][col_pos1 + j] = '*';

			}

		}
	}

}

bool Canvas::isValidPositionForCanvas(int row_pos1, int col_pos1){

	if ((row_pos1 >= 0 && row_pos1 < CANVAS_ROWS) && (col_pos1 >= 0 && col_pos1 < CANVAS_COLUMNS)){
		
		return true;

	}
	else{
		
		return false;

	}

}

bool Canvas::isValidRideForCanvas(int row_pos1, int col_pos1, int row_size1, int col_size1){

	//assert((row_size1 >= 1) && (col_size1 >= 1));
	//assert(((row_pos1 + row_size1) <= CANVAS_ROWS) && ((col_pos1 + col_size1) <= CANVAS_COLUMNS));
	//assert((row_pos1 >= 0 && row_pos1 < CANVAS_ROWS) && (col_pos1 >= 0 && col_pos1 < CANVAS_COLUMNS));

	if ((row_size1 < 1) || (col_size1 < 1)){
		
		return false;

	}

	if ((row_pos1 >= 0 && row_pos1 < CANVAS_ROWS) && (col_pos1 >= 0 && col_pos1 < CANVAS_COLUMNS)){
		
		if (((row_pos1 + row_size1) <= CANVAS_ROWS) && ((col_pos1 + col_size1) <= CANVAS_COLUMNS)){
			
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

void Canvas::addTrack(PositionList positionList){

	while (!(positionList.isEmpty())){

		canvas1[positionList.getFrontRow()][positionList.getFrontCol()] = '+';
		positionList.removeFront();

	}

}