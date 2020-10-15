#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <array>
#include <cmath>
#include <vector>

using namespace std;
// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(vector<int> heap, vector<string> trace, int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && heap[l] > heap[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && heap[r] > heap[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
	
	int temp = heap[i];
	heap[i] = heap[largest];
	heap[largest] = temp;
	    
	string stemp = trace[i];
	trace[i] = trace[largest];
	trace[largest] = stemp;
	    
        //swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree 
        heapify(heap, trace, n, largest); 
    } 
} 

void heapSort(vector<int> heap, vector<string> trace, int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(heap, trace, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>0; i--) 
    { 
        // Move current root to end 
        //swap(arr[0], arr[i]); 
  	int temp = heap[0];
	heap[0] = heap[i];
	heap[i] = temp;
	    
	string stemp = trace[0];
	trace[0] = trace[i];
	trace[i] = trace;
        // call max heapify on the reduced heap 
        heapify(heap, trace, i, 0); 
    } 
} 

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
			 string p = id.substr(1, id.length()-2);
			 int x = stoi(p);
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
			int x = stoi(id.substr(1, id.length()-2));
			int y = stoi(score.substr(1, score.length()-2));;
			
			if(heap.size()==maxSize) {
				output << "Contestant " << id << " could not be inserted because the extended heap is full.\n";
			}
			else if(handle[x]!=-1) {
				output << "Contestant " << id << " is already in the extended heap:cannot insert.\n";
			}
			handle[x] = x;
			handlePoints[x] = y;
 			heap.push_back(y);
			trace.push_back(id);
			int n = heap.size();
			heapSort(heap, trace, n); 
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
				int x = stoi(id.substr(1, id.length()-2));
				handle[x] = -1;
				handlePoints[x] = -1;
				output << "Contestant " << id << " with current lowest score <" << score << "> eliminated.\n";
				trace.pop_back();
				heap.pop_back();
			}
	      }
	      else if(operation=="earnPoints") {
			string id, points;
			file >> id;
			file >> points;
			output << "earnPoints " << id << " " << points<< "\n"; 
			int x = stoi(points.substr(1, points.length()-2));
			int y = stoi(id.substr(1, id.length()-2));
		      	handlePoints[y] += x;
		        bool exists = false;
		      	for(int i = 0; i<trace.size(); i++) {
				if(trace[i]==id) {
					exists = true;
					int temp = x + heap[i];
					heap[i] = temp;
					output << "Contestant " << id << "'s score was increased by " << points << " points to <" << temp << ">.\n";
					int n = heap.size();
					heapSort(heap, trace, n); 
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
			output << "losePoints " << id << " " << points << "\n"; 
		      int x = stoi(points.substr(1, points.length()-2));
		      int y = stoi(id.substr(1, id.length()-2));
		      handlePoints[y] -= x;
		        bool exists = false;
		      	for(int i = 0; i<trace.size(); i++) {
				if(trace[i]==id) {
					exists = true;
					int temp = heap[i] - x;
					heap[i] = temp;
					output << "Contestant " << id << "'s score was decreased by " << points << " points to <" << temp << ">.\n";
					int n = heap.size();
					heapSort(heap, trace, n); 
				}
			 }
		      if(exists==false) {
			      output << "Contestant " << id << "is not in the extended heap.\n";
		      }
	      }
	      else if(operation=="showContestants") {
			output << "showContestants\n";
			 for(int i = 0; i<trace.size(); i++) {
				output << "Contestant " << trace[i] << " in extended heap location <"<< i+1 << "> with score <" << heap[i] << ">.\n";
			 }	      
	      }

	      else if(operation=="showHandles") {
		output << "showHandles\n";
		for(int i = 1; i<maxSize+1; i++) {
				if(handle[i]==-1) {
				  output << "There is no Contestant <" << i << "> in the extended heap: handle["<< i << "] = -1.\n";
				}
			      	else {
				 for(int j = 0; j<trace.size(); j++) {
				   int w = stoi(trace[j].substr(1, trace[j].length()-2));
					if(w==handle[i]) {
						output << "Contestant <" << i << "> stored in extended heap location <" << j+1 << ">.\n";
					}
				 }
			}
		      }
	      }
	      else if(operation=="showLocation") {
			string id;
			file >> id;
			int x = stoi(id.substr(1, id.length()-2));
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
		      for(int i = heap.size()-1; i>0; i--){
				heap.pop_back();      
		      }
		      output << "Contestant" << trace[0]  << "wins with score " << heap[0] <<"!\n";
	      }
	}
	file.close();
	output.close();
	}	     
}
