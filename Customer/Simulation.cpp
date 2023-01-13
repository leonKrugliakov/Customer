//****************************************************************************************************
//
//      File:                Simulation.cpp
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
//		    1.    Customer.h - Contains the Customer structure
//			2.	  Cashier.h - Contains the Cashier structure
//			3.	  LLQueue.h - Contains the Queue class
//			4.	  Node.h - Contains the Node structure
//
//****************************************************************************************************

#include <iostream>
#include <fstream>

#include "LLQueue.h"
#include "Customer.h"
#include "Cashier.h"

//****************************************************************************************************

using namespace std;

//****************************************************************************************************

void fillCustomerQueue(Queue<Customer> & custList, Customer& custIn, const int currentTime);
void processCustomers(Queue<Customer> & custList, Cashier serv[], const int currentTime);
bool isDone(Cashier cashiers[], Queue<Customer> & custList);

//****************************************************************************************************

int main()
{
	ifstream custData;
	Customer custArray[50];
	Queue<Customer> custList;
	Cashier cashiers[3];
	int currentTime = 0,
		temp = 0;
	bool isComplete = false;

	custData.open("customerList.txt");
	while (custData >> custArray[temp]) 
	{
		temp++;
	}

	while (!isComplete) 
	{
		cout << endl << "Time = " << currentTime << endl;
		for (int i = 0; i < temp; i++)
		{
			if (custArray[i].arrivalTime == currentTime)
			{
				fillCustomerQueue(custList, custArray[i], currentTime);
			}
		}

		processCustomers(custList, cashiers, currentTime);
		currentTime++;
		isComplete = isDone(cashiers, custList);
	}
}

//****************************************************************************************************

void fillCustomerQueue(Queue<Customer> & custList, Customer& custIn, const int currentTime)
{
	custList.enqueue(custIn);
	cout << "Customer #" << custIn.id << " has been enqueued." << endl;
}

//****************************************************************************************************

void processCustomers(Queue<Customer> & custList, Cashier cashiers[], const int currentTime) 
{
	Customer temp;

	for (int i = 0; i < sizeof(cashiers) - 1; i++) 
	{
		if (cashiers[i].busy == true && cashiers[i].endTime != currentTime)
		{
			if (cashiers[i].endTime + 1 == currentTime) 
			{
				cashiers[i].busy = false;
			}

			cout << "Cashier #" << (i + 1) << " is currently serving customer #" <<
				cashiers[i].custId << " until time: " << cashiers[i].endTime << endl;
		}
		else if (cashiers[i].busy == true && cashiers[i].endTime == currentTime) 
		{
			custList.dequeue(temp);

			if (temp.id == 0) 
			{
				cout << "Cashier #" << (i + 1) << " is not busy." << endl;
				cashiers[i].busy = false;
			}
			else 
			{
				cashiers[i].custId = temp.id;
				cashiers[i].endTime = temp.serviceTime + currentTime;
				cashiers[i].busy = true;

				cout << "Cashier #" << (i + 1) << " has started serving customer #" <<
					cashiers[i].custId << " until time: " << cashiers[i].endTime << endl;
			}
		}
		else if (cashiers[i].busy == false && custList.isEmpty() == false)
		{
			custList.dequeue(temp);
			cashiers[i].custId = temp.id;
			cashiers[i].endTime = temp.serviceTime + currentTime;
			cashiers[i].busy = true;

			cout << "Cashier #" << (i + 1) << " has started serving customer #" <<
				cashiers[i].custId << " until time: " << cashiers[i].endTime << endl;
		}
		else if(cashiers[i].busy == false && custList.isEmpty() == true)
		{
			cout << "Cashier #" << (i + 1) << " is not busy." << endl;
		}
	}
}

//****************************************************************************************************

bool isDone(Cashier cashiers[], Queue<Customer> & custList) 
{
	bool isDone = true;

	for (int i = 0; i < sizeof(cashiers) - 1; i++)
	{
		if (cashiers[i].busy == true && custList.isEmpty())
		{
			isDone = false;
		}
	}
	
	return isDone;
}

/*
Time = 0
Customer #1 has been enqueued.
Customer #2 has been enqueued.
Cashier #1 has started serving customer #1 until time: 7
Cashier #2 has started serving customer #2 until time: 3
Cashier #3 is not busy.

Time = 1
Customer #3 has been enqueued.
Cashier #1 is currently serving customer #1 until time: 7
Cashier #2 is currently serving customer #2 until time: 3
Cashier #3 has started serving customer #3 until time: 3

Time = 2
Cashier #1 is currently serving customer #1 until time: 7
Cashier #2 is currently serving customer #2 until time: 3
Cashier #3 is currently serving customer #3 until time: 3

Time = 3
Customer #4 has been enqueued.
Customer #5 has been enqueued.
Cashier #1 is currently serving customer #1 until time: 7
Cashier #2 has started serving customer #4 until time: 4
Cashier #3 has started serving customer #5 until time: 7

Time = 4
Cashier #1 is currently serving customer #1 until time: 7
Cashier #2 is not busy.
Cashier #3 is currently serving customer #5 until time: 7

Time = 5
Cashier #1 is currently serving customer #1 until time: 7
Cashier #2 is not busy.
Cashier #3 is currently serving customer #5 until time: 7

Time = 6
Cashier #1 is currently serving customer #1 until time: 7
Cashier #2 is not busy.
Cashier #3 is currently serving customer #5 until time: 7

Time = 7
Cashier #1 is not busy.
Cashier #2 is not busy.
Cashier #3 is not busy.

*/