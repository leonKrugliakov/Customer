//****************************************************************************************************
//
//      File:                Node.h
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
//			4.	  LLQueue.h - Contains the Queue class
//
//****************************************************************************************************

#ifndef NODE_H
#define NODE_H

#include "Customer.h"

//****************************************************************************************************

template <typename TYPE>
struct Node
{
	TYPE data;
	Node<TYPE>* next;
	Node();
	Node(TYPE d, Node<TYPE>* n = nullptr);
};

//****************************************************************************************************

template <typename TYPE>
Node<TYPE>::Node()
{
	data = 0;
	next = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
Node<TYPE>::Node(TYPE d, Node<TYPE>* n)
{
	data = d;
	next = n;
}

//****************************************************************************************************

#endif