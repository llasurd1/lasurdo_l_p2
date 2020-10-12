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
	fstream file(argv[1], fstream::in);
	ofstream output;
	output.open("argv[2]");
  
	if(file.is_open()){
		file >> maxSize;
		while(!file.eof() && !file.fail()) {
		  string operation;
      file >> operation;
      if(operation=="findContestant") {
        string id;
        file >> id;
      }
      else if(operation=="insertContestant") {
        string id, score;
        file >> id;
        file >> score;
        stringstream num(score[1]); 
        int x = 0;
        num >> x; 
        output << "insertContestant " <<
        output << "Contestant " << id << " inserted with initial score " << score << "."
      }
      else if(operation=="eliminateWeakest") {
        
      }
      else if(operation=="earnPoints") {
        string id, points;
        file >> id;
        file >> points;
      }
      else if(operation=="showContestants") {
      
      }
      else if(operation=="losePoints") {
        string id, points;
        file >> id;
        file >> points;
      }
      else if(operation=="showHandles") {
      
      }
      else if(operation=="showLocation") {
        string id;
        file >> id;
      }
      else if(operation=="crownWinner") {
      
      }
		}
	file.close();
	}     
}
