//****************************************************************************************************
//
//      File:                LLQueue.h
//
//      Student:             Leon Krugliakov
//
//      Assignment:          Program #5
//
//      Course Name:         Data Structures I
//
//      Course Number:       COSC 3050 - 10
//
//      Due:                 October 5th, 2020
//
//
//      This program creates a queue of customers and an array of cashiers.
//		Then this program simulates and displays how the customers are being
//		serviced by the cashiers in accordance to their arrival time and 
//		service time.
//
//      Other files required:
//		    1.    Simulation.cpp - Contains the driver function
//			2.	  Customer.h - Contains the Customer structure
//			3.	  Cashier.h - Contains the Cashier structure
//			4.	  Node.h - Contains the Node structure
//
//****************************************************************************************************

#ifndef LLQUEUE_H
#define LLQUEUE_H

#include <new>
#include <iostream>
#include <fstream>
#include "Node.h"

//****************************************************************************************************

using namespace std;

//****************************************************************************************************

template <typename T>
class Queue
{
private:
	Node<T>* front;
	Node<T>* rear;
public:
	Queue();
	~Queue();
	bool enqueue(const T& dataIn);
	bool dequeue(T& dataOut);
	bool peekFront(T& dataOut) const;
	bool peekRear(T& dataOut) const;
	int getSize() const;
	bool isFull() const;
	bool isEmpty() const;
};

//****************************************************************************************************

template <typename T>
Queue<T>::Queue() 
{
	front = nullptr;
	rear = nullptr;
}

//****************************************************************************************************

template <typename T>
Queue<T>::~Queue()
{
	Node<T>* temp;

	while (front != nullptr) 
	{
		temp = front;
		front = front->next;
		delete temp;
	}

	rear = nullptr;
}

//****************************************************************************************************

template <typename T>
bool Queue<T>::enqueue(const T& dataIn)
{
	bool success = false;

	Node<T>* temp = new (nothrow) Node<T>(dataIn);

	if (temp != nullptr) 
	{
		if (front == nullptr)
		{
			front = temp;
			rear = temp;
			success = true;
		}
		else if (rear != nullptr)
		{
			rear->next = temp;
			rear = temp;
			success = true;
		}
	}

	return success;
}

//****************************************************************************************************

template <typename T>
bool Queue<T>::dequeue(T& dataOut)
{
	bool success = true;

	Node<T>* temp = front;

	if (temp == nullptr)
	{
		success = false;
	}
	else if (temp == rear) 
	{
		dataOut = front->data;
		front = nullptr;
		rear = nullptr;
	}
	else 
	{
		dataOut = front->data;
		front = front->next;
		delete temp;
	}

	return success;
}

//****************************************************************************************************

template <typename T>
bool Queue<T>::peekFront(T& dataOut) const
{
	bool success = false;

	if (front != nullptr) 
	{
		dataOut = front->data;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename T>
bool Queue<T>::peekRear(T& dataOut) const
{
	bool success = false;

	if (front != nullptr) 
	{
		dataOut = rear->data;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename T>
int Queue<T>::getSize() const
{
	bool success = false;
	int size = 0;

	Node<T>* temp = front;

	while (temp != nullptr) 
	{
		size++;
		temp = temp->next;
		success = true;
	}

	return success;

}

//****************************************************************************************************

template <typename T>
bool Queue<T>::isFull() const
{
	bool success = false;

	Node<T>* temp = new (nothrow) Node<T>(3, nullptr);

	if (temp->data == 3) 
	{
		success = true;
		delete[] temp;
	}

	return success;
}

//****************************************************************************************************

template <typename T>
bool Queue<T>::isEmpty() const
{
	return (front == nullptr);
}

//****************************************************************************************************

#endif