//*****************************************************************************************************
//
//		File:					customer.h
//
//		Student:				Conor Seely
//
//		Assignment:				Program #9
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					04/12/2023
//
//
//		This customer structure stores data about customers.
//	
//		Other files required: 
//			1. waitList.cpp
//			2. heap.h
//			3. overbooked.bin
//			
//*****************************************************************************************************

#include <iomanip>

#ifndef CUSTOMER_H
#define CUSTOMER_H

//*****************************************************************************************************

struct Customer
{
	char fName[15];
	char lName[15];
	int mileage;
	int years;
	int arrivalNum;
	int priority;

	friend std::ostream & operator << (std::ostream & out, const Customer & data);
	bool operator == (const Customer & rhs) const;
	bool operator == (int value) const;
	bool operator != (const Customer & rhs) const;
	bool operator != (int value) const;
	bool operator < (const Customer & rhs) const;
	bool operator < (int value) const;
	bool operator > (const Customer & rhs) const;
	bool operator > (int value) const;
	int operator % (const Customer & rhs) const;
	int operator % (int value) const;
	Customer & operator = (int value);
};

//*****************************************************************************************************

std::ostream & operator << (std::ostream & out, const Customer & data)
{
	out << right << setw(15) << data.lName << ", " << left << setw(15) << data.fName << " | "
		<< data.priority << " | " << data.mileage << " | " << data.years << endl;
	return out;
}

//*****************************************************************************************************

bool Customer::operator == (const Customer & rhs) const
{
	return (this->priority == rhs.priority);
}

//*****************************************************************************************************

bool Customer::operator == (int value) const
{
	return (this->priority == value);
}

//*****************************************************************************************************

bool Customer::operator != (const Customer & rhs) const
{
	return (this->priority == rhs.priority);
}

//*****************************************************************************************************

bool Customer::operator != (int value) const
{
	return (this->priority == value);
}

//*****************************************************************************************************

bool Customer::operator < (const Customer & rhs) const
{
	return (this->priority < rhs.priority);
}

//*****************************************************************************************************

bool Customer::operator < (int value) const
{
	return (this->priority < value);
}

//*****************************************************************************************************

bool Customer::operator > (const Customer & rhs) const
{
	return (this->priority > rhs.priority);
}

//*****************************************************************************************************

bool Customer::operator > (int value) const
{
	return (this->priority > value);
}

//*****************************************************************************************************

int Customer::operator % (const Customer & rhs) const
{
	return (this->priority % rhs.priority);
}

//*****************************************************************************************************

int Customer::operator % (int value) const
{
	return (this->priority % value);
}

//*****************************************************************************************************

Customer & Customer::operator = (int value)
{
	this->priority = value;
	return *this;
}

//*****************************************************************************************************
#endif
