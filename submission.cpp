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
	output.open(argv[2]);
  
	if(file.is_open()){
	file >> maxSize;
	int handle[maxSize+1];
	int handlePoints[maxSize+1];
	for(int i = 0; i<maxSize+1; i++) {
		handle[i] = -1;
		handlePoints[i] = -1;
	}	
	while(!file.eof() && !file.fail()) {
      		string operation;
      		file >> operation;
	
     		 if(operation=="findContestant") { 
      			 string id;
      			 file >> id;
			 int x = id[1] -48;
			 output << "findContestant " << id << "\n"; 
			 if(handle[x]==x) {
				 output << "Contestant " << id << " is in the extended heap with score <" << handlePoints[x] << ">.\n";
			 }
			 /*bool exists = false;
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
				output << "Contestant " << id << " is not in the extended heap.\n"; 
			 }
     		 }
      		else if(operation=="insertContestant") {
			string id, score;
			file >> id;
			file >> score;
			output << "insertContestant " << id << " " << score << "\n";
			int x = id[1] - 48;
			int y = score[1] - 48;
 			heap.push_back(y);
			trace.push_back(id);
        		output << "Contestant " << id << " inserted with initial score " << score << ".\n";
     		 }
	      else if(operation=="eliminateWeakest") {
			output << "eliminateWeakest\n";
			if(heap.size()==0) {
				output << "No contestant can be eliminated since the extended heap is empty.\n";
			}
			else {
				string id = trace[trace.size()-1];
				int score = heap[heap.size()-1];
				int x = id[1] - 48;
				handle[x] = -1;
				handlePoints[x] = -1;
				output << "Contestant " << id << " with current lowest score " << score << "eliminated.\n";
				trace.pop_back();
				heap.pop_back();
			}
	      }
	      else if(operation=="earnPoints") {
			string id, points;
			file >> id;
			file >> points;
			output << "earnPoints " << id << " " << points<< "\n"; 
			int x = points[1] - 48;
			int y = id[1]- 48;
		      	handlePoints[y] += x;
		        bool exists = false;
		      	for(int i = 0; i<trace.size(); i++) {
				if(trace[i]==id) {
					exists = true;
					int temp = x + heap[i];
					heap[i] = temp;
					output << "Contestant " << id << "'s score was increased by " << points << "points to <" << temp << ">.\n";
					
				}
			 }
		      if(exists==false) {
			      output << "Contestant " << id << "is not in the extended heap.\n";
		      }
	      }
	      else if(operation=="losePoints") {
			string id, points;
			file >> id;
			file >> points;
			output << "earnPoints " << id << " " << points << "\n"; 
		      int x = points[1]- 48;
		      int y = id[1] - 48;
		      handlePoints[y] -= x;
		        bool exists = false;
		      	for(int i = 0; i<trace.size(); i++) {
				if(trace[i]==id) {
					exists = true;
					int temp = heap[i] - x;
					heap[i] = temp;
					output << "Contestant " << id << "'s score was decreased by " << points << "points to <" << temp << ">.\n";
					
				}
			 }
		      if(exists==false) {
			      output << "Contestant " << id << "is not in the extended heap.\n";
		      }
	      }
	      else if(operation=="showContestants") {
			output << "showContestants\n";
			 for(int i = 0; i<trace.size(); i++) {
				output << "Contestant <" << trace[i] << "> in extended heap location <"<< i+1 << "> with score <" << heap[i] << ">.\n";
			 }	      
	      }

	      else if(operation=="showHandles") {
		output << "showHandles\n";
		for(int i = 1; i<maxSize+1; i++) {
				if(handle[i]==-1) {
				  output << "There is no Contestant <" << i << "> in the extended heap: handle["<< i+1 << "] = -1.\n";
				}
			      	else {
				 for(int i = 0; i<trace.size(); i++) {
				   int w = trace[i][1];
					if(w==i) {
						output << "Contestant <" << i << "> stored in extended heap location <" << i+1 << ">.\n";
					}
				 }
			}
		      }
	      }
	      else if(operation=="showLocation") {
			string id;
			file >> id;
			int x = id[1] - 48;
			output << "showLocation " << id << "\n";
		        if(handle[x]==-1) {
				output << "There is no Contestant " << id << " in the extended heap: handle["<< id << "] = -1.\n";
			}
		     	else {
				 for(int i = 0; i<trace.size(); i++) {
					if(trace[i]==id) {
						output << "Contestant " << id << " stored in extended heap location <" << i+1 << ">.\n";
					}
				 }
			}
			      
	      }
	      else if(operation=="crownWinner") {
			output << "crownWinner\n";
			string id, points;
	      }
	}
	file.close();
	output.close();
	}	     
}
