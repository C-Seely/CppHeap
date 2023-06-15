//*****************************************************************************************************
//
//		File:					heap.h
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
//		This class stores data in a templated Heap.
//	
//		Other files required: 
//			1. waitList.cpp
//			2. customer.h
//			3. overbooked.bin
//			
//*****************************************************************************************************

#include <algorithm>

#ifndef HEAP_H
#define HEAP_H

//*****************************************************************************************************

template <typename T>
class Heap
{
private:
	T * heap;
	int numValues;
	int capacity;

	void _siftUp(int child);
	void _siftDown(int parent);
	int _leftChildOf(int parent) const;
	int _parentOf(int child) const;

public:
	Heap(int c = 100);
	~Heap();
	bool insert(const T & dataIn);
	bool remove(T & dataOut);
	bool viewMax(T & dataOut) const;
	int getCapacity() const;
	int getNumValues() const;
	bool isEmpty() const;
	bool isFull() const;
};

//*****************************************************************************************************

template <typename T>
Heap<T>::Heap(int c)
{
	capacity = c;
	numValues = 0;
	heap = new T[capacity];
}

//*****************************************************************************************************

template <typename T>
Heap<T>::~Heap()
{
	delete[] heap;
}

//*****************************************************************************************************

template <typename T>
int Heap<T>::_leftChildOf(int parent) const
{
	return (parent * 2) + 1;
}

//*****************************************************************************************************

template <typename T>
int Heap<T>::_parentOf(int child) const
{
	return (child - 1) / 2;
}

//*****************************************************************************************************

template <typename T>
bool Heap<T>::insert(const T & dataIn)
{
	bool success = false;

	if (numValues < capacity)
	{
		heap[numValues] = dataIn;
		_siftUp(numValues);

		numValues++;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
void Heap<T>::_siftUp(int child)
{
	int parent;
	parent = _parentOf(child);

	if ((child > 0) && (heap[child] > heap[parent])) 
	{
		swap(heap[child], heap[parent]);
		_siftUp(parent);
	}
}

//*****************************************************************************************************

template <typename T>
bool Heap<T>::remove(T & dataOut)
{
	bool success = false;
	
	if (numValues > 0)
	{
		dataOut = heap[0];
		numValues--;

		heap[0] = heap[numValues];
		_siftDown(0);

		success = true;
	}
	
	return success;
}

//*****************************************************************************************************

template <typename T>
void Heap<T>::_siftDown(int parent)
{
	int child;
	child = _leftChildOf(parent);

	if (child < numValues)
	{
		if (((child + 1) < numValues) && (heap[child + 1] > heap[child]))
		{
			child++;
		}
		if (heap[parent] < heap[child])
		{
			swap(heap[parent], heap[child]);
			_siftDown(child);
		}
	}
}

//*****************************************************************************************************

template <typename T>
bool Heap<T>::viewMax(T & dataOut) const
{
	bool success = false;

	if (!isEmpty())
	{
		dataOut = heap(0);
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
int Heap<T>::getCapacity() const
{
	return capacity;
}

//*****************************************************************************************************

template <typename T>
int Heap<T>::getNumValues() const
{
	return numValues;
}

//*****************************************************************************************************

template <typename T>
bool Heap<T>::isEmpty() const
{
	return (numValues > 0);
}

//*****************************************************************************************************

template <typename T>
bool Heap<T>::isFull() const
{
	return (numValues >= capacity);
}

//*****************************************************************************************************

#endif