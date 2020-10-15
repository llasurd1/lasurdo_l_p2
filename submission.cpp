#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <array>
#include <cmath>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  
	int maxSize;     
	vector<int> heap;
	vector<string> trace;
	fstream file(argv[1], fstream::in);
	ofstream output;
	output.open("argv[2]");
  
	if(file.is_open()){
	file >> maxSize;
	int handle[maxSize+1];
	int handlePoints[maxSize+1];
	for(int i = 0; i<maxSize+1) {
		handle[i] = -1;
		handlePoints[i] = -1;
	}
		
	while(!file.eof() && !file.fail()) {
      		string operation;
      		file >> operation;
	
     		 if(operation=="findContestant") { 
      			 string id;
      			 file >> id;
			 stringstream num1(id[1]);
			 int x = 0;
			 num1 >> x;
			 if(handle[x]==x) {
				 output << "Contestant " << id << " is in the extended heap with score <" << handlePoints[x] << ">.";
			 }
			 /*boolean exists = false;
			 output << "findContestant " << id << " " << score;
			 for(int i = 0; i<trace.size(); i++) {
				 if(trace[i]==id) {
					exists = true;
					output << "Contestant " << id << " is in the extended heap with score " << heap[i] << ".";	 
				 }
			 }
			 if(exists==false) {
				output << "Contestant " << id << " is not in the extended heap.";
			 }*/
			 else {
				output << "Contestant " << id << " is not in the extended heap."; 
			 }
     		 }
      		else if(operation=="insertContestant") {
			string id, score;
			file >> id;
			file >> score;
			output << "insertContestant " << id << " " << score;
			stringstream num1(id[1]);
			stringstream num2(score[1]);
			int x = 0;
			int y = 0;
			num1 >> x; 
			num2 >> y;
 			heap.push_back(y);
			trace.push_back(id);
        		output << "Contestant " << id << " inserted with initial score " << score << ".";
     		 }
	      else if(operation=="eliminateWeakest") {
			output << "eliminateWeakest";
			if(heap.size()==0) {
				output << "No contestant can be eliminated since the extended heap is empty." <<;
			}
			else {
				string id = trace[trace.size()-1];
				int score = heap[heap.size()-1];
				stringstream num1(id[1]);
				int x = 0;
				num1 >> x;
				handle[x] = -1
				handlePoints[x] = -1;
				output << "Contestant " << id << " with current lowest score " << score << "eliminated.";
				trace.erase(trace.size()-1);
				heap.erase(heap.size()-1);
			}
	      }
	      else if(operation=="earnPoints") {
			string id, points;
			file >> id;
			file >> points;
			output << "earnPoints " << id << " " << points;
			stringstream num(points[1]); 
		      	stringstream num1(id[1]); 
			int x = 0;
		      int y = 0
			num >> x;
		      num1 >> y;
		      	handlePoints[y] += x;
		        boolean exists = false;
		      	for(int i = 0; i<trace.size(); i++) {
				if(trace[i]==id) {
					exists = true;
					int temp = x + heap[i];
					heap[i] = temp;
					output << "Contestant " << id << "'s score was increased by " << points << "points to <" << temp << ">.";
					
				}
			 }
		      if(exists==false) {
			      output << "Contestant " << id << "is not in the extended heap.";
		      }
	      }
	      else if(operation=="losePoints") {
			string id, points;
			file >> id;
			file >> points;
			output << "earnPoints " << id << " " << points;
			stringstream num(points[1]); 
		      stringstream num1(id[1]); 
			int x = 0;
		      int y = 0
			num >> x; 
		       num1 >> y;
		      handlePoints[y] -= x;
		        boolean exists = false;
		      	for(int i = 0; i<trace.size(); i++) {
				if(trace[i]==id) {
					exists = true;
					int temp = heap[i] - x;
					heap[i] = temp;
					output << "Contestant " << id << "'s score was decreased by " << points << "points to <" << temp << ">.";
					
				}
			 }
		      if(exists==false) {
			      output << "Contestant " << id << "is not in the extended heap.";
		      }
	      }
	      else if(operation=="showContestants") {
			output << "showContestants";
			 for(int i = 0; i<trace.size(); i++) {
				output << "Contestant " << id << " in extended heap location <"<< i+1 << "> with score <" << heap[i] << ">.";
			 }	      
	      }

	      else if(operation=="showHandles") {
		output << "showHandles";
		      for(int i = 1 i<maxSize+1) {
				if(handle[i]==-1) {
					output << "There is no Contestant " << id << " in the extended heap: handle["<< i+1 "] = -1.";
				}
			      	else {
				 for(int i = 0; i<trace.size(); i++) {
					if(trace[i]==i) {
						output << "Contestant " << id << " stored in extended heap location <" << i+1 << ">.";
					}
				 }
			}
		      }
	      }
	      else if(operation=="showLocation") {
			string id;
			file >> id;
			stringstream num1(id[1]);
			int x = 0;
		      	num1 >> x;
			output << "showLocation " << id;
		        if(handle[x]==-1) {
				output << "There is no Contestant " << id << " in the extended heap: handle["<< id << "] = -1.";
			}
		     	else {
				 for(int i = 0; i<trace.size(); i++) {
					if(trace[i]==id) {
						output << "Contestant " << id << " stored in extended heap location <" << i+1 << ">.";
					}
				 }
			}
			      
	      }
	      else if(operation=="crownWinner") {
			output << "crownWinner";
			string id, points;
	      }
	}
	file.close();
	     
}
