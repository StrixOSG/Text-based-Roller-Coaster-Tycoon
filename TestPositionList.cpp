// ==========================================
// Name: Matthew Hamilton
// Date: Apr.7,2016
// ==========================================

#include <iostream>
#include <string>
#include "PositionList.h"

using namespace std;

int main(){

	PositionList list1;

	//Testing getSize()
	cout << "Testing for getSize()" << endl;
	cout << "Num of Nodes: " << list1.getSize() << endl;

	//Testing for isEmpty
	cout << "list1 is empty? " << list1.isEmpty() << endl;

	//Testing for addToBack and debugPrint
	cout << "Testing for addToBack(4,5), addToBack(7,8), addToBack (12, 13) and debugPrint()" << endl;
	list1.addToBack(4, 5);
	cout << "Num of Nodes: " << list1.getSize() << endl;
	list1.debugPrint();
	list1.addToBack(7, 8);
	list1.addToBack(12, 13);
	list1.debugPrint();
	cout << endl;

	//Testing for getFrontRow and getFrontCol
	cout << "Front row: " << list1.getFrontRow() << " Front col: " << list1.getFrontCol() << endl << endl;

	//Testing for removeFront
	cout << "Testing for removeFront()" << endl;
	cout << "removeFront()" << endl;
	list1.removeFront();
	list1.debugPrint();
	cout << "Front row: " << list1.getFrontRow() << " Front col: " << list1.getFrontCol() << endl;
	cout << "Testing for removeFront()" << endl;
	list1.removeFront();
	list1.debugPrint();
	cout << "Front row: " << list1.getFrontRow() << " Front col: " << list1.getFrontCol() << endl;
	cout << "Testing for addToBack(9, 12)" << endl;
	list1.addToBack(9, 12);
	list1.debugPrint();
	cout << endl;

	cout << "PositionList list2" << endl;

	PositionList list2; //remove copy constructor if testing private copy function

	//Testing for private copy function | Note: in order to use this move copy function to be public temporarily
	cout << "Testing for list2 debugPrint()" << endl;
	list2.debugPrint();
	cout << "Testing for list2 copy(list1)" << endl;
	list2.copy(list1);
	list2.debugPrint();

	//Testing for copy constructor
	cout << "copying list3 from list2" << endl;
	PositionList list3(list2);
	list3.debugPrint();
	cout << "removingAll() from list2" << endl;
	list2.removeAll();
	list3.debugPrint();
	PositionList list4;
	cout << "setting list4 = list3" << endl;
	list4 = list3;
	list4.debugPrint();

	//Load Testing
	cout << "Testing load() for list4" << endl;
	ifstream testList;
	testList.open("TestList.txt");
	list4.load(testList);
	list4.debugPrint();

	//Save Testing
	cout << "Testing save() for list4" << endl;
	string testSave;
	cout << "Enter name for save: ";
	cin >> testSave;
	ofstream saveTest;
	saveTest.open(testSave + ".txt");
	list4.save(saveTest);
	saveTest.close();
	list4.debugPrint();
	cout << "Enter name for second save: ";
	cin >> testSave;
	saveTest.open(testSave + ".txt");
	list4.save(saveTest);
	saveTest.close();

}