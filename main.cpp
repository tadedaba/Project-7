/* 
	This is the main method. It contains the testing
	function implementation. It calls functions 
	from the implementation to perform the duty.
*/
#include <cstdlib>
#include <iostream>
#include "que.h" 
#include "que.cpp"
using namespace std;
int main(int argc, const char * argv[]){
	int Tick, seed, SIM_TIME, PR, N, DUR_TRNS; 
	cout << " This program performs a queuing simulation\n"
		 << " and display the output of the simulation\n"
		 << " you need to enter the appropriate parameters\n"
		 << " in order for the program to start to simulate."<<endl;
	cout << " ============================================\n";
	cout << " Enter the parameters of the simulation"<<endl;
	cout << " ============================================\n";
  	cout << " The number of queue/server pairs: ";
  	cin >> N;
  	cout << " The probability of arrival in one tick (%): ";
  	cin >> PR;
  	cout << " Maximum transaction duration in ticks: ";
  	cin >> DUR_TRNS;
  	cout << " Total time of simulation in ticks: ";
  	cin >> SIM_TIME;
  	cout << " Enter a random number seed: ";
  	cin >> seed;
  	srand(seed);
  	Queue Q;
  	
  	Q.initialize(PR,DUR_TRNS, seed, N);
  	Tick = 0;
  	for(int i = 0; i < SIM_TIME; i++){
  		Q.enqueue(Tick);	//enques the current time
  		cout << setw(4)<<Tick + 1 <<setw(4)<<endl;
  		Q.servers(Tick);	//perform the service 
  		cout << setw(4) << endl;
  		Tick++;
	  }
	  cout<<"*********** Average Statistics ***********"<<endl;
	  cout << "=======================================\n";
	  Q.averages(Tick); 
	  return 0;
}
