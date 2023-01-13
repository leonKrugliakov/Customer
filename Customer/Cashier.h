//****************************************************************************************************
//
//      File:                Cashier.h
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
//			3.	  LLQueue.h - Contains the Queue class
//			4.	  Node.h - Contains the Node structure
//
//****************************************************************************************************

#ifndef CASHIER_H
#define CASHIER_H

#include "LLQueue.h"

//****************************************************************************************************

struct Cashier 
{
	int custId,
		endTime;
	bool busy;

	Cashier();
};

//****************************************************************************************************

Cashier::Cashier() 
{
	custId = 0;
	endTime = 0;
	busy = false;
}

//****************************************************************************************************

#endif