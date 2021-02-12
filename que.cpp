/* 
	This is the implementation file. It contains all 
	the methods/functions that perform various operations.
*/
#include <bits/stdc++.h>
#include "que.h" 
#include <queue>		// header file for queuing operations
using namespace std; 
//global vaiable to initialize the parameters obtained from the user.
int p, s, seed, count, n, m;
int num = 0;
// arrays declaration and initialization.
int wait_time[MAX] = {0};// holds the in line wait time to be servered
int ser_time[MAX] = {0};// holds the time taken by server to deliver service
int longTime[MAX];		// array to hold all the wait times of the customers

Queue Que;	//initializes the Queue class
//array of queue declaration.  
queue<int>q[MAX];	// holds the customers in queue.
queue<int>que[MAX];	//copy of the queue 
//initialization function. 
void Queue::initialize(int prob, int ser_t, int Seed, int num){
	p = prob;
	s = ser_t;
	seed = Seed;
	n = num;
}
void Queue::enqueue(int t){ // enqueue the customer
	srand(seed);
	int index;
	count = 0;
	if(rand() % 100 < p){
		index = Que.min_sizearray();
		q[index].push(t);
		count++;
	}
}
//function that return the index of the shortest queue.
int Queue::min_sizearray(){
	int short_que;
	int arr[n];
	for(int i = 0; i < n; i++)
		arr[i] = q[i].size();	//form array of queue size
	for(int j = 0; j < n; j++){
		if(arr[j] == 0){
			return j;
			break;
		}	
		else
			continue;	
	}
	//The index of the short queue is the distance of smallest
	//element in the array of queue sizes. 
	short_que = distance(arr, min_element(arr, arr+n)); 
	return short_que;	
}
//function that performs the dequeuing and serving process
void Queue::servers(int timeNow){
	srand(seed);
	int entry_time;
	int j = 0;
	int timeWaited;
	for(int i = 0; i < n; i++){
		que[i] = q[i]; //get a copy of the queue.
		if(ser_time[i] == 0){
			if(!q[i].empty()){
				entry_time = q[i].front();
				q[i].front();	//referance the front of the queue
				q[i].pop();		//dequeue the front element
				ser_time[i] = (rand() % s) + 1; //generate new server time
				timeWaited = (timeNow - entry_time); // wait time for q[i]
				wait_time[i] += timeWaited; //total wait time at server[i]
				longTime[j++] = timeWaited; //array of all wait times
				num++;
			}
		}
		else
			--ser_time[i];	
		cout<<setw(8)<<ser_time[i]<<"  ";	//print out server time
		//for each queue, print out its contents from front to back
		for(int j = 0; j < q[i].size(); j++){
			if(!que[i].empty()){
				cout<<que[i].front()<<" ";
				que[i].pop();
			}
		}
		cout<<endl;
	}
}
//function to calculate and print the final averages.
void Queue::averages(int time){
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += wait_time[i]; //add all accumulated wait times
	}
	//find the longest wait time.
	int* long_t = max_element(longTime, longTime+n);
	cout << "  "<<num << " customers waited an average of "
		 << sum/num << " ticks."<<endl;
	cout << "  The longest time a customer waited "
		 << "was "<<*long_t << " ticks."<<endl;
	cout << "  " << time+1 - num << " customers remain in the"
		 << " lines."<<endl; 
}
