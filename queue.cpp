/* 

*/
#include <cstdlib>
#include <iostream>
#include "queue.h" 
#include <string>
#include <queue>
using namespace std; 

void Queue::getTime(int time){
	Queue Que;
	currTime = time;
	Que.enqueue(currTime);
}
Queue::Queue(int prob, int ser_t, int Seed, int num){
	p = prob;
	s = ser_t;
	seed = Seed;
	n = num;
}
void getTransTime(int Trans[], int k){
	int sum[k] = 0;
	for(int j = 0; j < k; j++){
		ser_time = (rand() % s) + 1;
		Trans[j] = ser_time;
	}
	for(int n = o; n < k; n++){
		if(n == j)
			sum[n] += Trans[j];
	}
}
void Queue::enqueue(int t){
	queue <int> q[n];
	int count = 0;
	int index;
	index = Que.min_sizearray(q, n);
	q[index].push(t);
	count++;
}
int Queue::dequeue(){
	queue <int> q[n];
	int index, entry_time;
	index = Que.servers(q, n);
	entry_time = q[index].front();
	q[index].pop();
	return entry_time;
}
int Queue::min_sizearray(int q[], int k){
	int min_que = 0;
	for(int i = 0; i < NumOfQueues; ++i){
		if(q[i].isempty())
			min_que = i;
		else{
			if(q[i].size() > q[++i].size())
				min_que = i;
		}
	}
	return min_que;
}
void Queue::servers(int ser[], int n){
	int transtime[n] = 0;
	
	for(int i = 0; i <n; i++){
		if(transtime == 0){
			if(!q[i].empty())
			entry_time = Que.dequeue()
		}
	}
}
