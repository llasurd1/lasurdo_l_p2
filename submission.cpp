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
	int [maxSize+1] 
while(!file.eof() && !file.fail()) {
      	string operation;
      	file >> operation;
	
      if(operation=="findContestant") { 
      	 string id;
      	 file >> id;
	 boolean exists = false;
	 output << "findContestant " << id << " " << score;
	 for(int i = 0; i<trace.size(); i++) {
		 if(trace[i]==id) {
			exists = true;
			output << "Contestant " << id << " is in the extended heap with score " << heap[i] << ".";	 
		 }
	 }
	 if(exists==false) {
		output << "Contestant " << id << " is not in the extended heap.";
	 }
      }
      else if(operation=="insertContestant") {
        string id, score;
        file >> id;
        file >> score;
	output << "insertContestant " << id << " " << score;
        stringstream num1(score[1]);
	stringstream num2(score[1]);
        int x = 0;
	int y = 0;
        num1 >> x; 
	num2 >> y;
       
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
        int x = 0;
        num >> x; 
      }
      else if(operation=="showContestants") {
      	output << "showContestants";
	 for(int i = 0; i<trace.size(); i++) {
		output << "Contestant " << id << " in extended heap location <"<< i+1 << "> with score <" << heap[i] << ">.";
	 }	      
      }
      else if(operation=="losePoints") {
        string id, points;
        file >> id;
        file >> points;
	output << "losePoints " << id << " " << points;
	stringstream num(points[1]); 
        int x = 0;
        num >> x; 
      }
      else if(operation=="showHandles") {
      	output << "showHandles";
      }
      else if(operation=="showLocation") {
        string id;
        file >> id;
	output << "showLocation " << id
      }
      else if(operation=="crownWinner") {
      	output << "crownWinner";
	string id, points;
      }
	}
	file.close();
	}     
}
