//****************************************************************************************************
//
//      File:                Customer.h
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
//			2.	  Cashier.h - Contains the Cashier structure
//			3.	  LLQueue.h - Contains the Queue class
//			4.	  Node.h - Contains the Node structure
//
//****************************************************************************************************

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "LLQueue.h"

//****************************************************************************************************

using namespace std;

//****************************************************************************************************

struct Customer
{
	int id,
		arrivalTime,
		serviceTime;

	friend istream &operator >> (istream& istr, Customer& cust);
	friend ostream &operator << (ostream& ostr, const Customer& cust);

	Customer();
};

//****************************************************************************************************

Customer::Customer()
{
	id = 0;
	arrivalTime = 0;
	serviceTime = 0;
}

//****************************************************************************************************

ostream &operator<<(ostream &ostr, const Customer& cust)
{
	ostr << cust.id << " " << cust.arrivalTime << " "
		<< cust.serviceTime << endl;

	return ostr;
}

//****************************************************************************************************

istream &operator>>(istream &istr, Customer& cust)
{
	istr >> cust.id;
	istr.ignore();
	istr >> cust.arrivalTime;
	istr.ignore();
	istr >> cust.serviceTime;

	return istr;
}

//****************************************************************************************************

#endif