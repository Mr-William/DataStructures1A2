//*****************************************************************************************************
//
//		File:			ArrList.h
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
//			1.	ArrListDriver.cpp - main driver program
//			
//*****************************************************************************************************

#ifndef ARRLIST_H
#define ARRLIST_H
#include <new>

//*****************************************************************************************************

template <typename TYPE>
class ArrList
{
	private:
		TYPE* list;
		int capacity;
		int numValues;
		bool _resize();
	public:
		ArrList(int);
		ArrList();
		~ArrList();
		void display() const;
		bool update(const TYPE&);
		bool updateFront(const TYPE&);
		bool updateBack(const TYPE&);
		bool updateAtIndex(const TYPE&, int);
		bool insertBack(const TYPE&);
		bool insertFront(const TYPE&);
		bool insertAtIndex(const TYPE&, int index);
		bool retrieveAtIndex(TYPE&, int) const;
		bool retrieveFront(TYPE&) const;
		bool retrieveBack(TYPE&) const;
		bool retrieve(TYPE&, int&) const;
		bool removeFront(TYPE&);
		bool removeBack(TYPE&);
		bool removeAtIndex(TYPE&, int);
		int getCapacity(int&) const;
		int getNumValues(int&) const;
		TYPE findMin(TYPE&) const;
		void clearList();
		bool isEmpty() const;

};

//*****************************************************************************************************

template <typename TYPE>
bool ArrList<TYPE> :: _resize()
{
	bool success = false;
	capacity = capacity + capacity / 2;
	TYPE* newList = new (std::nothrow) TYPE[capacity];

	if (newList != nullptr)
	{
		for ( int i = 0; i < numValues; i++ )
			  newList[i] = list[i];
		
		delete [] list;
		list = newList;
		success = true;
	}

	return success;
}

//*****************************************************************************************************


template <typename TYPE>
ArrList<TYPE> ::ArrList()
{
	capacity = 5;
}

//*****************************************************************************************************

template <typename TYPE>
ArrList<TYPE> :: ArrList(int c)
{
	capacity = c;
	numValues = 0;
	list = new TYPE[capacity];
}

//*****************************************************************************************************

template <typename TYPE>
ArrList<TYPE> :: ~ArrList()
{
	delete[] list;
	list = nullptr;
	numValues = 0;
	capacity = 0;
}

//*****************************************************************************************************

template <typename TYPE>
void ArrList<TYPE> :: display() const
{
	if (numValues > 0)
	{
		for ( int i = 0; i < numValues; i++ )
			  std::cout << list[i] << " ";
		std::cout << "\n";
	}
}

//*****************************************************************************************************

template <typename TYPE>
bool ArrList<TYPE> :: update (const TYPE& dataIn)
{
	bool success = false;

	if (numValues > 0)
	{
		for ( int i = 0; !success && i < numValues; i++ )
			if ( list[i] == dataIn )
			{
				 list[i] = dataIn;
				 success = true;
			}
	}
	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool ArrList<TYPE> :: updateFront(const TYPE& dataIn)
{
	bool success = false;
	
	list[0] = dataIn;
		
	success = true;
	
	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool ArrList<TYPE> :: updateBack(const TYPE& dataIn)
{
	bool success = false;
	
	list[numValues - 1] = dataIn;

	success = true;

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool ArrList<TYPE> :: updateAtIndex(const TYPE& dataIn, int index)
{
	bool success = false;

	if ( index >= 0 && index < numValues )
	{
		list[index] = dataIn;

		success = true;
	}
	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool ArrList<TYPE> :: insertBack(const TYPE& dataIn)
{
	bool success = true;

	if ( numValues == capacity )
		success = _resize();

	if ( success == true )
	{
		list[numValues] = dataIn;

		numValues++;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool ArrList<TYPE> :: insertFront(const TYPE& dataIn)
{
	bool success = true;

	if ( numValues == capacity )
		success = _resize();

	if ( success == true )
	{
		numValues++;
		for (int i = numValues; i > 0; i--)
			list[i] = list[i - 1];
		list[0] = dataIn;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool ArrList<TYPE> :: insertAtIndex(const TYPE& dataIn, int index)
{
	bool success = false;

	if ( index >= 0 && index <= numValues )
	{
		success = true;

		if ( numValues == capacity )
			success = _resize();

		if ( success == true )
		{
			for ( int i = numValues; i > index; i-- )
			{
				list[i] = list[i - 1];
			}
			
			list[index] = dataIn;

			numValues++;
		}
	}
	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool ArrList<TYPE> :: retrieveAtIndex(TYPE& dataOut, int index) const
{
	bool success = false;

	if ( numValues > 0 )
	{
		dataOut = list[index];

		success = true;
	}
	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool ArrList<TYPE> :: retrieveFront(TYPE& dataOut) const
{
	bool success = false;

	if ( numValues > 0 )
	{
		dataOut = list[0];

		success = true;
	}
	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool ArrList<TYPE> :: retrieveBack(TYPE& dataOut) const
{
	bool success = false;

	if ( numValues > 0 )
	{
		dataOut = list[numValues - 1];

		success = true;
	}
	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool ArrList<TYPE> :: retrieve(TYPE& dataOut, int& index) const
{
	bool success = false;

	if ( numValues > 0 )
	{
		for ( int i = 0; !success && i < numValues; i++ )
		{
			if ( list[i] == dataOut )
			{
				success = true;
				index = i;
			}
		}
		return success;
	}
}

//*****************************************************************************************************

template <typename TYPE>
bool ArrList<TYPE> :: removeFront(TYPE& data)
{
	bool success = false;

	if ( numValues > 0 )
	{
		data = list[0];
		numValues--;

		for ( int i = 0; i < numValues; i++ )
			list[i] = list[i + 1];

		success = true;
	}
	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool ArrList<TYPE> :: removeBack(TYPE& data)
{
	bool success = false;

	if ( numValues > 0 )
	{
		data = list[numValues - 1];
		numValues--;

		success = true;
	}
	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool ArrList<TYPE> :: removeAtIndex(TYPE& data, int index)
{
	bool success = false;

	if ( (index >= 0) && (index <= numValues) )
	{
		data = list[index];
		
		for ( int i = index; i < numValues; i++ )
			list[i] = list[i + 1];

		numValues--;

		success = true;
	}
	return success;
}

//*****************************************************************************************************

template <typename TYPE>
int ArrList<TYPE> :: getCapacity(int& c) const
{
	c = this->capacity;

	return c;
}

//*****************************************************************************************************

template <typename TYPE>
int ArrList<TYPE> :: getNumValues(int& n) const
{
	n = this->numValues;

	return n;
}

//*****************************************************************************************************

template <typename TYPE>
TYPE ArrList<TYPE> :: findMin(TYPE& data) const
{
	TYPE min = list[0];

	for ( int i = 1; i < numValues; i++ )
	{
		if (list[i] < min)
			min = list[i];
	}
	return min;
}

//*****************************************************************************************************

template <typename TYPE>
void ArrList<TYPE> :: clearList()
{
	numValues = 0;
	_resize();
}

//*****************************************************************************************************

template <typename TYPE>
bool ArrList<TYPE> :: isEmpty() const
{
	bool empty = true;

	if ( this->numValues > 0 )
		empty = false;

	return empty;
}

//*****************************************************************************************************

#endif