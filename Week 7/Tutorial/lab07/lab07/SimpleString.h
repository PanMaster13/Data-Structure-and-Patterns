#pragma once
#include <iostream>

using namespace std;

class SimpleString
{
private:
	char *myChar; //Character pointer to a Char array
public:
	//Default Constructor and Copy Constructor
	SimpleString();

	SimpleString(const SimpleString& aString);

	//Default Constructor
	~SimpleString();
	//virtual ~SimpleString(); //This is optional

	//Operator for shallow copy
	SimpleString& operator=(const SimpleString& aString);

	//Clone function for Deep Copy
	SimpleString* Clone();

	//Operator for appending a new char into the string
	SimpleString& operator+(const char aChar);

	//Operator to output content of string
	const char* operator*() const;
};

SimpleString::SimpleString()
{
	//To create an empty string, allocate one element to hold the String Terminator
	myChar = new char[1];
	*myChar = '\0';
}

// The copy constructor
SimpleString::SimpleString(const SimpleString& aString)
{
	//First find out length of existing string
	int size = strlen(aString.myChar);

	//Create the new char array with size + 1, to accomadate the End-String character
	myChar = new char[size + 1];

	strcpy_s(myChar, size + 1, aString.myChar); //strcpy not safe (risky), use strcpy_s instead

}

SimpleString::~SimpleString() //tilde
{
	delete myChar;
}

//Same like copy constructor, but with return value
SimpleString& SimpleString::operator=(const SimpleString& aString)
{
	// First find out length of existing string
	int size = strlen(aString.myChar);

	//Create the new char array with size + 1, to accomadate the End-String character
	myChar = new char[size + 1];

	strcpy_s(myChar, size + 1, aString.myChar); //strcpy not safe (risky), use strcpy_s instead

	return *this;
}

SimpleString* SimpleString::Clone()
{
	return new SimpleString(*this);
}

SimpleString& SimpleString::operator+(const char aChar)
{
	char *temp; //1. Create a temp pointer
	size_t i, n;

	n = strlen(myChar); //2. Find out size of current buffer

	temp = new char[n + 2]; //3. Create the new buffer and add elements for aChar and Terminator

	for (i = 0; i < n; i++) //4. Copy existing content between old and new buffers.
	{
		temp[i] = myChar[i];
	}

	//5. Add the aChar and End-String character
	temp[i] = aChar;
	temp[i + 1] = '\0';

	//6. Remove old buffer from memory and redirect pointer to new one
	delete myChar;
	myChar = temp;

	//temp auto delete cuz its now out of scope
	return *this;
}

const char *SimpleString::operator*() const
{
	return myChar;
}