//*****************************************************************************************************
//
//		File:			ArrListDriver.cpp
//		
//		Student:		William Gibbs
//
//		Assignment:	 	Program  #2, Array List
//
//		Course Name:	Data Structures I 
//
//		Course Number:	COSC 3050 - 10
//
//		Due:			September 7, 2020 
//
//
//		This program is set up with pre-defined values that verify functionality of various
//      list manipulating functions that are outlined in header file
//
//		Other files required: 
//			1.	ArrList.h - header file with definitions
//			
//*****************************************************************************************************

#include <iostream>
#include "ArrList.h"

//*****************************************************************************************************

using namespace std;

int main()
{
    ArrList<short> newList(8);
    short value;
    int numberOfValues,
        capacity;
    const char* line = new char[21];
    line = "====================";

    cout << line << endl;
    cout << "Initial Values:  \n";
    cout << "Capacity: " << newList.getCapacity(capacity) << endl;
    cout << "Number of Values: " << newList.getNumValues(numberOfValues) << endl;
    cout << "Is the list empty:  ";

    if ( newList.isEmpty() == true )
         cout << "Yes" << endl;
    else
         cout << "No" << endl;

    cout << line << endl;
    cout << "Inserting the values 7, 8, 9, 2, 1, 6 to the list using 'insertBack'." << endl;

    newList.insertBack(7);
    newList.insertBack(8);
    newList.insertBack(9);
    newList.insertBack(2);
    newList.insertBack(1);
    newList.insertBack(6);

    cout << "Capacity: " << newList.getCapacity(capacity) << endl;
    cout << "Display function: ";
    newList.display();

    cout << "Inserting 4 to the front and 5 at index 2." << endl;
    newList.insertFront(4);
    newList.insertAtIndex(5, 2);

    cout << "Current number of Values: " << newList.getNumValues(numberOfValues);

    cout << "\nDisplay function:  ";
    newList.display();

    cout << line << endl;
    cout << "Retrieves function:" << endl;
    cout << "The front value: ";
    newList.retrieveFront(value);
    cout << value << endl;

    cout << "The back value: ";
    newList.retrieveBack(value);
    cout << value << endl;

    cout << "The value at index 3: ";
    newList.retrieveAtIndex(value, 3);
    cout << value << endl;

    cout << "The smallest value:  " << newList.findMin(value) << endl;

    cout << line << endl;
    cout << "The Removes Function:" << endl;
    cout << "Removing the front and the value is: ";
    newList.retrieveFront(value);
    cout << value << endl;
    newList.removeFront(value);

    cout << "Now the new list of values is: ";
    newList.display();

    cout << "Removing at index 2 the value is: ";
    newList.removeAtIndex(value, 2);
    cout << value << endl;

    cout << "Removing the back value and that value is: ";
    newList.removeBack(value);
    cout << value << endl;

    cout << "Now the new list of values is: ";
    newList.display();

    cout << line << endl;
    cout << "Updates: " << endl;
    cout << "Update first value to 100, last value as 50 and index 2 as 15." << endl;
    newList.updateFront(100);
    newList.updateBack(50);
    newList.updateAtIndex(15, 2);

    cout << "Now the new list of values is: ";
    newList.display();

    cout << line << endl;
    cout << "New capacity: " << newList.getCapacity(capacity) << endl;
    cout << "New number of values: " << newList.getNumValues(numberOfValues);
    cout << "\nClearing values...\n" << endl;
    newList.clearList();
    
    cout << "New number of values: " << newList.getNumValues(numberOfValues);
    cout << "\nIs it empty?  ";

    if ( newList.isEmpty() == true )
         cout << "Yes\n";
    else
         cout << "No\n";

    return 0;
}

//*****************************************************************************************************

/*
====================
Initial Values:
Capacity: 8
Number of Values: 0
Is the list empty:  Yes
====================
Inserting the values 7, 8, 9, 2, 1, 6 to the list using 'insertBack'.
Capacity: 8
Display function: 7 8 9 2 1 6
Inserting 4 to the front and 5 at index 2.
Current number of Values: 8
Display function:  4 7 5 8 9 2 1 6
====================
Retrieves function:
The front value: 4
The back value: 6
The value at index 3: 8
The smallest value:  1
====================
The Removes Function:
Removing the front and the value is: 4
Now the new list of values is: 7 5 8 9 2 1 6
Removing at index 2 the value is: 8
Removing the back value and that value is: 6
Now the new list of values is: 7 5 9 2 1
====================
Updates:
Update first value to 100, last value as 50 and index 2 as 15.
Now the new list of values is: 100 5 15 2 50
====================
New capacity: 8
New number of values: 5
Clearing values...

New number of values: 0
Is it empty?  Yes

D:\OneDrive\Desktop\Webster\FA2020\DataStructures\DataStructures I\Week2\ArrayList\Debug\ArrayList.exe (process 15800) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/
