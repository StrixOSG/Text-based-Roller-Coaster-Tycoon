// ==========================================
// Name: Matthew Hamilton
// Date: Apr.7,2016
// ==========================================

#include <cassert>
#include <cstdlib>
#include <iostream>
#include "PositionList.h"
using namespace std;

PositionList::PositionList(){

	tail = nullptr;
	head = nullptr;
	numOfElements = 0;

	assert(invariant());

}

bool PositionList::isEmpty() const{

	assert(invariant());

	if (numOfElements == 0){
		
		return true;

	}
	else{

		return false;

	}

}

void PositionList::addToBack(int row, int col){
	
	assert(invariant());

	Node *newNode = new Node;
	newNode->row = row;
	newNode->col = col;
	newNode->next = nullptr;

	numOfElements++;

	if (head == nullptr){

		head = newNode;

	}
	else{

		tail->next = newNode;

	}

	tail = newNode;

	assert(invariant());

}

void PositionList::debugPrint() const{


	Node *tempNode = head;

	cout << "Num of Elements: " << numOfElements << endl;

	for (int i = 0; i < numOfElements; i++){

		cout << "Node " << i + 1 << " -->[" << tempNode->row << ", " << tempNode->col << "]" << endl;
		tempNode = tempNode->next;

	}

}

int PositionList::getFrontRow() const{

	assert(invariant());
	assert(head != nullptr);

	return head->row;

}

int PositionList::getFrontCol() const{
	
	assert(invariant());
	assert(head != nullptr);

	return head->col;

}

void PositionList::removeFront(){
	
	assert(invariant());
	assert(head != nullptr);

	Node *tempNode = head;
	head = head->next;

	delete tempNode;

	numOfElements--;

	if (head == nullptr){

		tail = nullptr;

	}

	assert(invariant());

}

void PositionList::removeAll(){
	
	assert(invariant());

	while (!isEmpty()){

		removeFront();

	}

	head = nullptr;
	tail = nullptr;

	assert(invariant());

}

void PositionList::copy(const PositionList& list2){
	
	assert(invariant());

	if (!isEmpty())
	{
		removeAll();
	}

	Node *tempNode = list2.head;

	for (int i = 0; i < list2.numOfElements; i++){

		addToBack(tempNode->row, tempNode->col);
		tempNode = tempNode->next;

	}

	assert(invariant());

}

PositionList::PositionList(const PositionList& original){
	
	head = nullptr;
	tail = nullptr;
	numOfElements = 0;
	
	copy(original);

	assert(invariant());

}

PositionList::~PositionList(){

	assert(invariant());

	removeAll();

}

PositionList& PositionList::operator= (const PositionList& original){
	
	assert(invariant());
	
	if (!isEmpty()){

		removeAll();

	}
	copy(original);

	return *this;

	assert(invariant());

}

unsigned int PositionList::getSize() const{

	assert(invariant());
	
	return numOfElements;

}

void PositionList::save(ofstream& game_out) const{

	assert(invariant());

	game_out << numOfElements << " ";
	cout << numOfElements << endl;

	Node *tempHead = head;
	
	for (int i = 0; i < numOfElements; i++){

		game_out << tempHead->row << " ";
		game_out << tempHead->col << " ";
		tempHead = tempHead->next;

	}

	game_out << endl;

}

void PositionList::load(ifstream& game_in){
	
	assert(invariant());

	int  numOfNodes;
	
	removeAll();
	
	game_in >> numOfNodes;

	int tRow;
	int tCol;
	int numOfPairs = 0;

	for (int i = 0; i < numOfNodes; i++){

		game_in >> tRow;
		game_in >> tCol;
		addToBack(tRow, tCol);

		numOfPairs++;	

	}

	if (numOfPairs != numOfNodes){

		exit(1);

	}

	assert(invariant());


}

bool PositionList::invariant()const{

	if (((head == nullptr && tail == nullptr) && numOfElements == 0) || ((head != nullptr && tail != nullptr) && numOfElements > 0)){

		return true;

	}
	else{

		return false;

	}

}