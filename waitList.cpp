//*****************************************************************************************************
//
//		File:					waitList.cpp
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
//		This driver runs the booking functions.
//	
//		Other files required: 
//			1. customer.h
//			2. heap.h
//			3. overbooked.bin
//			
//*****************************************************************************************************

#include <iostream>
#include <fstream>

using namespace std;

#include "customer.h"
#include "heap.h"

//*****************************************************************************************************

void getData(Heap<Customer> & waitList);
void printWaitList(Heap<Customer> & waitList);

//*****************************************************************************************************

int main()
{
	Heap<Customer> waitList;
	getData(waitList);
	printWaitList(waitList);

	return 0;
}

//*****************************************************************************************************

void getData(Heap<Customer> & waitList)
{
	Customer cust;
	ifstream inFile;
	inFile.open("overbooked.bin", ios::binary);

	while (inFile.read((char*)& cust, sizeof(cust)))
	{
		cust.priority = (cust.mileage / 1000) + cust.years - cust.arrivalNum;
		waitList.insert(cust);
	}

	inFile.close();
}

//*****************************************************************************************************

void printWaitList(Heap<Customer> & waitList)
{
	Customer cust;
	ofstream outFile;
	outFile.open("waitList.txt");

	outFile << "Last and First Name:    |   Priority, Mileage, Years:" << endl;

	while (waitList.remove(cust))
	{
		outFile << cust;
	}
}

//*****************************************************************************************************

/*
Output:

Press any key to continue . . .

*/