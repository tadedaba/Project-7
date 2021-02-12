/*
	This is the heare file. It contain the class Queue that 
	contains five puplic functions and four private variables
	The operations that the member functions perform is specified
	in the implementation file. The member variables are used to
	initialize the inputs that is obtained from the user.
	
	Precondition: - The program is designed to work with integer 
					queues. The user is required to enter the required
					parameters for initialization. This program assumes
					the line of customers will not grow past 100 customers.
	Postcondition: - The program will perform queuing simulation.
					 The "customers" are represented by the horizontal
					 line of numbers and the "servers" are represented 
					 by the vertical numbers infront of the "customers".
					 "Customers are enqueued to the back of the line 
					 and dequeued from the front of the line.
*/
#include <iostream>
#ifndef _QUE
#define _QUE
static const int MAX = 100;
class Queue{
  	public:
  		//a function to initialize the parameters entered by the user. 
  		void initialize(int, int, int, int);
  		void enqueue(int);		// enqueues the "customers"
  		void servers(int);		// dequeues the customers and serves it
  		void averages(int);		// calculates the average statistics
  		int min_sizearray();	// exmines the queues, find the shortest 
		  						// queue and returns its index
	private:
		int p;	 //probability of arrivan in a single tick
  		int s;		//the maximum duration of simulation in ticks
  		int seed; 	// seed number for rand()
  		int count;  // total number of customers
  		int num;	// number of server-queue pair.
};
#endif
